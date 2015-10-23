//
// Socket.hpp for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 22:50:40 2015 Bertrand-Rapello Baptiste
// Last update Fri Oct 23 09:20:30 2015 Antoine Plaskowski
//

#ifndef		SOCKET_HPP_
# define	SOCKET_HPP_

# include	<sys/select.h>
# include	<arpa/inet.h>
# include	<string>
# include	"ISocket.hpp"
# include	"ITime.hpp"

class Socket : public ISocket
{
public:
    enum
    {
      FAIL = -1,
      IN = 0,
      OUT = 1,
      ERR = 2
    };
public:
  Socket(void);
  ~Socket(void);
  static bool	select(ITime const *timeout = nullptr);
  bool	server(std::string host = "::1", std::string port = "4242");
  bool	client(std::string host = "::1", std::string port = "4242");
  ISocket	*accept(void) const;
  std::string const	&get_ip(void) const;
  bool	standard_io(ISocket::io io);
  bool	can_read(void) const;
  bool	can_write(void) const;
  uintmax_t	read(uint8_t *buffer, uintmax_t size) const;
  uintmax_t	write(uint8_t *buffer, uintmax_t size) const;
private:
  bool	set_fd(int fd);
  bool	set_ip(void);
  bool	aux_server(struct addrinfo const *rp);
  bool	aux_client(struct addrinfo const *rp);
private:
  static fd_set	m_fds;
  static fd_set	m_readfds;
  static fd_set	m_writefds;
  static int	m_nfds;
  int	m_fd;
  std::string	m_ip;
  union
  {
    struct sockaddr       base;
    struct sockaddr_in    ipv4;
    struct sockaddr_in6   ipv6;
  }             m_sockaddr;
};

#endif	/* !ISOCKET_HPP_ */
