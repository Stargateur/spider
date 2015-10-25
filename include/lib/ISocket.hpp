//
// ISocket.hh for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:47:26 2015 Bertrand-Rapello Baptiste
// Last update Sun Oct 25 09:48:47 2015 Antoine Plaskowski
//

#ifndef		ISOCKET_HPP_
# define	ISOCKET_HPP_

# include	<list>
# include	<string>
# include	"ITime.hpp"

class ISocket
{
public:
  enum	Standard
    {
      IN,
      OUT,
      ERR
    };  
public:
  virtual ~ISocket(void);
  virtual ISocket	&accept(void) const = 0;
  virtual std::string const	&get_ip(void) const = 0;
  virtual bool	can_read(void) const = 0;
  virtual bool	want_read(void) const = 0;
  virtual bool	can_write(void) const = 0;
  virtual bool	want_write(void) const = 0;
  virtual uintmax_t	read(void *buffer, uintmax_t size) const = 0;
  virtual uintmax_t	write(void const *buffer, uintmax_t size) const = 0;
};

extern "C"
{
# define	NAME_FCT_ISELECT	"iselect"
  bool	iselect(ITime const *timeout);
  typedef	bool	(*fct_iselect)(ITime const *timeout);
# define	NAME_FCT_NEW_ISERVER	"new_iserver"
  ISocket	&new_iserver(std::string const &ip, std::string const &port);
  typedef	ISocket	&(*fct_new_iserver)(std::string const &ip, std::string const &port);
# define	NAME_FCT_NEW_ICLIENT	"new_iclient"
  ISocket	&new_iclient(std::string const &ip, std::string const &port);
  typedef	ISocket	&(*fct_new_iclient)(std::string const &ip, std::string const &port);
# define	NAME_FCT_NEW_ISTANDARD	"new_istandard"
  ISocket	&new_istandard(ISocket::Standard standard);
  typedef	ISocket	&(*fct_new_istandard)(ISocket::Standard standard);
}

#endif	/* !ISOCKET_HPP_ */
