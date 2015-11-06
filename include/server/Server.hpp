//
// Server.hpp for Server in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 22:50:01 2015 Antoine Plaskowski
// Last update Fri Nov  6 08:57:17 2015 Antoine Plaskowski
//

#ifndef		SERVER_HPP_
# define	SERVER_HPP_

#include	<list>
#include	"Option.hpp"
#include	"DynamicLinkLibrary.hpp"
#include	"IDatabase.hpp"
#include	"IProtocol.hpp"
#include	"ISocket.hpp"
#include	"ITime.hpp"

class	Server
{
public:
  Server(Option const &option);
  ~Server(void);
  bool	run(void);
private:
  bool	command(void);
  void	select(void);
private:
  DynamicLinkLibrary	m_dll_idatabase;
  DynamicLinkLibrary	m_dll_itime;
  DynamicLinkLibrary	m_dll_iprotocol;
  DynamicLinkLibrary	m_dll_isocket;
  ref_new_idatabase	m_new_idatabase;
  ref_new_itime	m_new_itime;
  ref_new_iprotocol	m_new_iprotocol;
  ref_iselect	m_iselect;
  ref_new_iserver	m_new_iserver;
  ref_new_istandard	m_new_istandard;
  IDatabase	&m_database;
  ISocket	&m_server;
  ISocket	&m_in;
  std::list<IProtocol *>	m_clients;
  ITime	&m_timeout;
};

#endif		/* !SERVER_HPP_ */
