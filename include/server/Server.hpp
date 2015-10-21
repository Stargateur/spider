//
// Server.hpp for Server in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 22:50:01 2015 Antoine Plaskowski
// Last update Wed Oct 21 23:42:17 2015 Antoine Plaskowski
//

#ifndef		SERVER_HPP_
# define	SERVER_HPP_

#include	<list>
#include	"IBatabase.hpp"
#include	"IProtocol.hpp"

class	Server
{
public:
  Server(void);
  ~Server(void);
  bool	run(void);
private:
  std::list<Client *>	clients;
  IBatabase	m_database;
  IProtocol	m_protocol;
};

#endif		/* !SERVER_HPP_ */
