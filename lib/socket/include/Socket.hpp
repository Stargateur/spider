//
// Socket.hpp for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 22:50:40 2015 Bertrand-Rapello Baptiste
// Last update Tue Nov  3 12:57:06 2015 Antoine Plaskowski
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
  Socket(std::string const &ip, int fd);
  ~Socket(void);
  static bool	select(ITime const *timeout = nullptr);
  ISocket	&accept(void) const;
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
  int	m_fd;
  std::string	m_ip;
};

class	SocketException : public ISocketException
{
public:
  SocketException(std::string const &what);
  virtual char const	*what(void) const throw();
private:
  std::string const	m_what;
};

#endif	/* !ISOCKET_HPP_ */
