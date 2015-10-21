//
// ISocket.hh for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:47:26 2015 Bertrand-Rapello Baptiste
// Last update Wed Oct 21 23:33:03 2015 Bertrand-Rapello Baptiste
//

#ifndef ISOCKET_HPP_
# define ISOCKET_HPP_

#include <list>
#include "ITime.hpp"

class ISocket
{
public:
  enum io
    {
      in,
      out,
      err
    };
  
public:
  virtual bool server(std::string host ="::1", std::string port="4242") = 0;
  virtual bool client(std::string host ="::1", std::string port="4242") = 0;
  virtual bool accept(ISocket const &);
  virtual std::string const & get_ip() = 0;
  virtual bool standard_io(ISocket::io ) = 0;
  virtual bool can_read() = 0;
  virtual bool can_write() = 0;
  //virtual bool set_timeout(ITime * ptr = nulptr);
  virtual ITime const & get_timeout();
  
  virtual ISocket();
};

#define
