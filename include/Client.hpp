//
// Client.hpp for Client in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 23:48:57 2015 Antoine Plaskowski
// Last update Wed Oct 21 23:55:36 2015 Antoine Plaskowski
//

#ifndef		CLIENT_HPP_
# define	CLIENT_HPP_

#include	<list>
#include	<tuple>

class	Client
{
public:
  ISocket	&get_socket(void);
private:
  ISocket	m_socket;
  vector<IPacket *>	m_IPacket;
  string	m_mac_address;
  std::list<std::tuple<uintmax_t, void *>>	to_write;
}

#endif		/* !CLIENT_HPP_ */
