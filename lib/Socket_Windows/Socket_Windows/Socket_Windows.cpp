// Socket_Windows.cpp : définit les fonctions exportées pour l'application DLL.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <io.h>
#include <exception>
#include <fcntl.h>
#include "Socket_Windows.hpp"

DWORD	SocketWindows::m_idx_events = 0;
WSAEVENT	SocketWindows::m_events[WSA_MAXIMUM_WAIT_EVENTS] = {};
static WSAData	m_wsadata;

SocketWindows::SocketWindows(std::string const &ip, SOCKET sock) :
	m_sock(sock),
	m_event(WSACreateEvent()),
	m_ip(ip)
{
}

SocketWindows::~SocketWindows(void)
{
	WSACloseEvent(m_event);
	WSACleanup();
}

bool	SocketWindows::select(ITime const *timeout)
{
	DWORD	ret;
	if (timeout == nullptr)
		ret = WSAWaitForMultipleEvents(m_idx_events, m_events, false, WSA_INFINITE, false);
	else
		ret = WSAWaitForMultipleEvents(m_idx_events, m_events, false, timeout->get_second() * 1000 + timeout->get_nano() / 1000000, false);
	m_idx_events = 0;
	if (ret == WSA_WAIT_FAILED)
	{
		return (true);
	}
	return (false);
}

ISocket	&SocketWindows::accept(void) const
{
	WSAStartup(MAKEWORD(2, 2), &m_wsadata);
	union
	{	
		struct sockaddr	base;
		struct sockaddr_in	ipv4;
		struct sockaddr_in6	ipv6;
	}	sockaddr;
	SOCKET fd;
	socklen_t len = sizeof(sockaddr);
	std::memset(&sockaddr.base, 0, len);
	fd = WSAAccept(m_sock, &sockaddr.base, &len, NULL, NULL);
	if (fd == INVALID_SOCKET)
	{
		perror("accept()");
		throw std::exception();
	}
	switch (sockaddr.base.sa_family)
	{
	case AF_INET:
		char	ipv4[INET_ADDRSTRLEN];
		if (inet_ntop(AF_INET, &sockaddr.ipv4.sin_addr, ipv4, sizeof(ipv4)) == NULL)
			perror("inet_ntop()");
		return (*new SocketWindows(ipv4, fd));
	case AF_INET6:
		char	ipv6[INET6_ADDRSTRLEN];
		if (inet_ntop(AF_INET6, &sockaddr.ipv6.sin6_addr, ipv6, sizeof(ipv6)) == NULL)
			perror("inet_ntop()");
		return (*new SocketWindows(ipv6, fd));
	}
	return (*new SocketWindows("", fd));
}

std::string const	&SocketWindows::get_ip(void) const
{
	return (m_ip);
}

bool	SocketWindows::can_read(void) const
{
	WSANETWORKEVENTS	networkevents;
	if (WSAEnumNetworkEvents(m_sock, m_event, &networkevents) == SOCKET_ERROR)
		return (false);
	if (networkevents.lNetworkEvents != FD_READ)
		return (false);
	return (networkevents.iErrorCode[FD_READ_BIT] == ERROR_SUCCESS);
}

bool	SocketWindows::want_read(void) const
{
	if (WSAEventSelect(m_sock, m_event, FD_READ) == SOCKET_ERROR)
		return (true);
	if (m_idx_events >= WSA_MAXIMUM_WAIT_EVENTS)
		return (true);
	m_events[m_idx_events++] = m_event;
	return (false);
}

bool	SocketWindows::can_write(void) const
{
	WSANETWORKEVENTS	networkevents;
	if (WSAEnumNetworkEvents(m_sock, m_event, &networkevents) == SOCKET_ERROR)
		return (false);
	if (networkevents.lNetworkEvents != FD_WRITE)
		return (false);
	return (networkevents.iErrorCode[FD_WRITE_BIT] == ERROR_SUCCESS);
}

bool	SocketWindows::want_write(void) const
{
	if (WSAEventSelect(m_sock, m_event, FD_WRITE) == SOCKET_ERROR)
		return (true);
	if (m_idx_events >= WSA_MAXIMUM_WAIT_EVENTS)
		return (true);
	m_events[m_idx_events++] = m_event;
	return (false);
}

bool	SocketWindows::want_read_write(void) const
{
	if (WSAEventSelect(m_sock, m_event, FD_READ | FD_WRITE) == SOCKET_ERROR)
		return (true);
	if (m_idx_events >= WSA_MAXIMUM_WAIT_EVENTS)
		return (true);
	m_events[m_idx_events++] = m_event;
	return (false);
}

uintmax_t	SocketWindows::read(uint8_t &buffer, uintmax_t size) const
{
	WSABUF buff;
	buff.len = size;
	buff.buf = reinterpret_cast<char *>(&buffer);
	uintmax_t	ret = WSARecv(m_sock, &buff, size, NULL, NULL, NULL, NULL);
	if (ret < 0)
		throw std::exception();
	return (ret);
}

uintmax_t	SocketWindows::write(uint8_t const &buffer, uintmax_t size) const
{
	WSABUF buff;
	buff.len = size;
	buff.buf = reinterpret_cast<char *>(const_cast<uint8_t *>(&buffer));
	uintmax_t	ret = WSASend(m_sock, &buff, size, NULL, NULL, NULL, NULL);
	if (ret < 0)
		throw std::exception();
	return (ret);
}

static SOCKET	aux_server(struct addrinfo const *rp)
{
	SOCKET	fd;

	if (rp == NULL)
		return (INVALID_SOCKET);
	if ((fd = WSASocket(rp->ai_family, rp->ai_socktype, rp->ai_protocol, NULL, 0, 0)) == INVALID_SOCKET)
	{
		perror("socket()");
		return (aux_server(rp->ai_next));
	}
	if (bind(fd, rp->ai_addr, rp->ai_addrlen) != 0)
	{
		perror("bind()");
		if (closesocket(fd) == -1)
			perror("close()");
		return (aux_server(rp->ai_next));
	}
	if (listen(fd, 42) != 0)
	{
		perror("listen()");
		if (closesocket(fd) == -1)
			perror("close()");
		return (aux_server(rp->ai_next));
	}
	return (fd);
}

ISocket	&new_iserver(std::string const &host, std::string const &port)
{
	WSAStartup(MAKEWORD(2, 2), &m_wsadata);
	struct addrinfo	*result;
	struct addrinfo	hints =
	{
		AI_PASSIVE,
		AF_UNSPEC,
		SOCK_STREAM,
		IPPROTO_TCP,
		0,
		NULL,
		NULL,
		NULL
	};
	int	status = getaddrinfo(NULL, port.c_str(), &hints, &result);
	if (status != 0)
	{
		std::cerr << "getaddrinfo: " << gai_strerror(status) << std::endl;
		WSACleanup();
		throw std::exception();
	}

	SOCKET fd = aux_server(result);
	freeaddrinfo(result);
	if (fd == INVALID_SOCKET)
	{
		WSACleanup();
		throw std::exception();
	}
	return (*new SocketWindows(host, fd));
}

static SOCKET	aux_client(struct addrinfo const *rp)
{
	SOCKET	fd;

	if (rp == NULL)
		return (INVALID_SOCKET);
	if ((fd = WSASocket(rp->ai_family, rp->ai_socktype, rp->ai_protocol, NULL, 0, 0)) == INVALID_SOCKET)
	{
		perror("socket()");
		return (aux_client(rp->ai_next));
	}
	if (WSAConnect(fd, rp->ai_addr, rp->ai_addrlen, NULL, NULL, NULL, NULL) != 0)
	{
		perror("connect()");
		if (closesocket(fd) == -1)
			perror("close()");
		return (aux_client(rp->ai_next));
	}
	return (fd);
}

ISocket	&new_iclient(std::string const &host, std::string const &port)
{
	WSAStartup(MAKEWORD(2, 2), &m_wsadata);
	struct addrinfo	*result;
	struct addrinfo	hints =
	{
		0,
		AF_UNSPEC,
		SOCK_STREAM,
		IPPROTO_TCP,
		0,
		NULL,
		NULL,
		NULL
	};
	int	status = getaddrinfo(host.c_str(), port.c_str(), &hints, &result);
	if (status != 0)
	{
		std::cerr << "getaddrinfo: " << WSAGetLastError() << std::endl;
		WSACleanup();
		throw std::exception();
	}

	SOCKET fd = aux_client(result);
	freeaddrinfo(result);
	if (fd == INVALID_SOCKET)
	{
		WSACleanup();
		throw std::exception();
	}
	return (*new SocketWindows(host, fd));
}

ISocket	&new_istandard(ISocket::Standard standard)
{
	WSAStartup(MAKEWORD(2, 2), &m_wsadata);
	switch (standard)
	{
	case ISocket::In:
		return (*new SocketWindows("Standard Input (stdin)", 0));
	case ISocket::Out:
		return (*new SocketWindows("Standard Output (stdout)", 1));
	case ISocket::Err:
		return (*new SocketWindows("Standard Input (stdin)", 2));
	}
	WSACleanup();
	throw std::exception();
}

bool	iselect(ITime const *timeout)
{
	return (SocketWindows::select(timeout));
}