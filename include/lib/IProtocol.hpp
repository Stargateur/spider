//
// IProtocol.hpp for IProtocol in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 23:48:57 2015 Antoine Plaskowski
// Last update Thu Oct 22 03:24:05 2015 Antoine Plaskowski
//

#ifndef		IPROTOCOL_HPP_
# define	IPROTOCOL_HPP_

# include	"ISocket.hpp"
# include	"IDatabase.hpp"

class	IProtocol
{
public:
  ~IProtocol(void);
  bool	run(IDatabase &database);
  ISocket	&get_socket(void);
  std::string const	&get_mac_address(void);
}

#endif		/* !IPROTOCOL_HPP_ */
