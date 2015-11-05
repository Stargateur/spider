// Socket_Windows.cpp : définit les fonctions exportées pour l'application DLL.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <io.h>
#include <exception>
#include <fcntl.h>
#include "Socket_Windows.hpp"

static WSAData	m_wsadata;
int	SocketWindows::m_nfds = -1;
fd_set	SocketWindows::m_readfds = {};
fd_set	SocketWindows::m_writefds = {};

SocketWindows::SocketWindows(std::string const &ip, SOCKET sock) :
	m_sock(sock),
	m_ip(ip)
{
}

SocketWindows::~SocketWindows(void)
{
	FD_CLR(m_sock, &m_writefds);
	FD_CLR(m_sock, &m_readfds);
	WSACleanup();
}

bool	SocketWindows::select(ITime const *timeout)
{
	int	ret;

	if (timeout == nullptr)
		ret = ::select(m_nfds + 1, &m_readfds, &m_writefds, NULL, NULL);
	else
	{
		struct timeval	time = {timeout->get_second(), timeout->get_nano() * 1000};
		ret = ::select(m_nfds + 1, &m_readfds, &m_writefds, NULL, &time);
	}
	m_nfds = -1;
	if (ret == -1)
	{
		perror("select()");
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
	fd = ::accept(m_sock, &sockaddr.base, &len);
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
	bool	ret = FD_ISSET(m_sock, &m_readfds);
	FD_CLR(m_sock, &m_readfds);
	return (ret);
}

bool	SocketWindows::want_read(void) const
{
	FD_SET(m_sock, &m_readfds);
	m_nfds = std::max<int>(m_nfds, m_sock);
	return (false);
}

bool	SocketWindows::can_write(void) const
{
	bool	ret = FD_ISSET(m_sock, &m_writefds);
	FD_CLR(m_sock, &m_writefds);
	return (ret);
}

bool	SocketWindows::want_write(void) const
{
	FD_SET(m_sock, &m_writefds);
	m_nfds = std::max<int>(m_nfds, m_sock);
	return (false);
}

uintmax_t	SocketWindows::read(uint8_t &buffer, uintmax_t size) const
{
	int	ret = ::recv(m_sock, reinterpret_cast<char *>(&buffer), size, 0);
	if (ret < 0)
		throw std::exception();
	return (ret);
}

uintmax_t	SocketWindows::write(uint8_t const &buffer, uintmax_t size) const
{
	int	ret = ::send(m_sock, reinterpret_cast<char const*>(&buffer), size, 0);
	if (ret < 0)
		throw std::exception();
	return (ret);
}

static SOCKET	aux_server(struct addrinfo const *rp)
{
	SOCKET	fd;

	if (rp == NULL)
		return (INVALID_SOCKET);
	if ((fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == INVALID_SOCKET)
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
	if ((fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == INVALID_SOCKET)
	{
		perror("socket()");
		return (aux_client(rp->ai_next));
	}
	if (::connect(fd, rp->ai_addr, rp->ai_addrlen) != 0)
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