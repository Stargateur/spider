//
// ISocket.hh for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:47:26 2015 Bertrand-Rapello Baptiste
// Last update Thu Oct 22 02:08:16 2015 Antoine Plaskowski
//

#ifndef		ISOCKET_HPP_
# define	ISOCKET_HPP_

# include	<list>
# include	<string>
# include	"ISocket.hpp"

class ISocket
{
public:
  enum io
    {
      IN,
      OUT,
      ERR
    };  
public:
  virtual ~ISocket(void);
  virtual bool server(std::string host ="::1", std::string port="4242") = 0;
  virtual bool client(std::string host ="::1", std::string port="4242") = 0;
  virtual bool accept(ISocket const &socket) = 0;
  virtual std::string const & get_ip(void) = 0;
  virtual bool standard_io(ISocket::io io) = 0;
  virtual bool can_read(void) const = 0;
  virtual bool can_write(void) const = 0;
};

#endif	/* !ISOCKET_HPP_ */
