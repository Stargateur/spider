//
// Socket.hpp for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 22:50:40 2015 Bertrand-Rapello Baptiste
// Last update Thu Oct 22 02:12:03 2015 Antoine Plaskowski
//

#ifndef SOCKET_HPP_
# define SOCKET_HPP_

# include	"ISocket.hpp"

class Socket : public ISocket
{
public:
  Socket(void);
  ~Socket(void);
  bool server(std::string host = "::1", std::string port = "4242");
  bool client(std::string host = "::1", std::string port = "4242");
  bool accept(ISocket const &socket);
  std::string const & get_ip(void);
  bool standard_io(ISocket::io io);
  bool can_read(void);
  bool can_write(void);
private:
  int	fd;
};

#endif	/* !ISOCKET_HPP_ */
