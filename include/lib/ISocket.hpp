//
// ISocket.hh for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:47:26 2015 Bertrand-Rapello Baptiste
// Last update Fri Nov  6 09:31:49 2015 Antoine Plaskowski
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
      In,
      Out,
      Err
    };  
public:
  virtual ~ISocket(void);
  virtual ISocket	&accept(void) const = 0;
  virtual std::string const	&get_ip(void) const = 0;
  virtual bool	can_read(void) const = 0;
  virtual bool	want_read(void) const = 0;
  virtual bool	can_write(void) const = 0;
  virtual bool	want_write(void) const = 0;
  virtual uintmax_t	read(uint8_t &buffer, uintmax_t size) const = 0;
  virtual uintmax_t	write(uint8_t const &buffer, uintmax_t size) const = 0;
};

class	ISocketException : public std::exception
{
public:
  virtual char const *what(void) const noexcept = 0;
  virtual ~ISocketException(void);
};

extern "C"
{
# define	NAME_FCT_ISELECT	"iselect"
# define	NAME_FCT_NEW_ISERVER	"new_iserver"
# define	NAME_FCT_NEW_ICLIENT	"new_iclient"
# define	NAME_FCT_NEW_ISTANDARD	"new_istandard"
#ifdef	__linux__
  bool	iselect(ITime const *timeout);
  ISocket	&new_iserver(std::string const &ip, std::string const &port);
  ISocket	&new_iclient(std::string const &ip, std::string const &port);
  ISocket	&new_istandard(ISocket::Standard standard);
#else
  __declspec(dllexport) bool	iselect(ITime const *timeout);
  __declspec(dllexport) ISocket	&new_iserver(std::string const &ip, std::string const &port);
  __declspec(dllexport) ISocket	&new_iclient(std::string const &ip, std::string const &port);
  __declspec(dllexport) ISocket	&new_istandard(ISocket::Standard standard);
#endif
  typedef	bool	(*fct_iselect)(ITime const *timeout);
  typedef	ISocket	&(*fct_new_iserver)(std::string const &ip, std::string const &port);
  typedef	ISocket	&(*fct_new_iclient)(std::string const &ip, std::string const &port);
  typedef	ISocket	&(*fct_new_istandard)(ISocket::Standard standard);
  typedef	bool	(&ref_iselect)(ITime const *timeout);
  typedef	ISocket	&(&ref_new_iserver)(std::string const &ip, std::string const &port);
  typedef	ISocket	&(&ref_new_iclient)(std::string const &ip, std::string const &port);
  typedef	ISocket	&(&ref_new_istandard)(ISocket::Standard standard);
}

#endif	/* !ISOCKET_HPP_ */
