#pragma once
#pragma comment(lib,"ws2_32.lib")

#include "ISocket.hpp"
#include "ITime.hpp"
#include <ws2tcpip.h>
#include <winsock2.h>

class SocketWindows : public ISocket
{
public:
	SocketWindows(std::string const &ip, SOCKET sock);
	~SocketWindows(void);
	ISocket	&accept(void) const;
	static bool	select(ITime const *timeout = nullptr);
	std::string const	&get_ip(void) const;
	bool	can_read(void) const;
	bool	want_read(void) const;
	bool	can_write(void) const;
	bool	want_write(void) const;
	uintmax_t	read(uint8_t &buffer, uintmax_t size) const;
	uintmax_t	write(uint8_t const &buffer, uintmax_t size) const;
private:
	static fd_set	m_readfds;
	static fd_set	m_writefds;
	static int	m_nfds;
	int m_sock;
	std::string m_ip;
};