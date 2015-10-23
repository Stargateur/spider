//
// IProtocol.hpp for IProtocol in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 23:48:57 2015 Antoine Plaskowski
// Last update Fri Oct 23 10:19:20 2015 Antoine Plaskowski
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
  ~IProtocol(void);
  virtual bool	run(IDatabase *database = nullptr, ITime const *timeout = nullptr) = 0;
  virtual bool	set_socket(ISocket *socket) = 0;
  virtual bool	start(void) = 0;
  virtual bool	stop(void) = 0;
  virtual bool	mute(void) = 0;
  virtual bool	unmute(void) = 0;
  virtual std::string const	&get_mac_address(void) const = 0;
  virtual bool	mac_address(std::string const &mac_address) = 0;
  virtual bool	keyboard(ITime const &time, std::string const &event, std::string const &key, std::string const &process) = 0;
  virtual bool	mouse(ITime const &time, uintmax_t x, uintmax_t y, uintmax_t amont, std::string const &event, std::string const &key, std::string const &process) = 0;
};

extern "C"
{
# define	NAME_FCT_NEW_IPROTOCOL	"new_iprotocol"
  IProtocol	*new_iprotocol(void);
  typedef	IProtocol *(*fct_new_iprotocol)(ISocket *socket, ITime *time);
}
  
#endif		/* !IPROTOCOL_HPP_ */
