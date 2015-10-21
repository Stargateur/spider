//
// Socket.hpp for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 22:50:40 2015 Bertrand-Rapello Baptiste
// Last update Wed Oct 21 23:33:10 2015 Bertrand-Rapello Baptiste
//

#ifndef SOCKET_HPP_
# define SOCKET_HPP_

#include "ISocket.hpp"

class Socket : public ISocket
{
public:
  Socket();
  ~Socket();

private:
  
public:
  bool server(std::string host ="::1", std::string port="4242");
  bool client(std::string host ="::1", std::string port="4242");
  bool accept(ISocket const &);
  std::string const & get_ip();
  bool standard_io(ISocket::io );
  bool can_read();
  bool can_write();
  ITime const & get_timeout();
  
  
};

#endif
