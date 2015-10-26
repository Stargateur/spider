//
// Server.hpp for Server in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 22:50:01 2015 Antoine Plaskowski
// Last update Mon Oct 26 03:58:27 2015 Antoine Plaskowski
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
  DynamicLinkLibrary	m_dll_idatabase;
  DynamicLinkLibrary	m_dll_itime;
  DynamicLinkLibrary	m_dll_iprotocol;
  DynamicLinkLibrary	m_dll_isocket;
  fct_new_idatabase	m_new_idatabase;
  fct_new_itime	m_new_itime;
  fct_new_iprotocol	m_new_iprotocol;
  fct_iselect	m_iselect;
  fct_new_iserver	m_new_iserver;
  fct_new_istandard	m_new_istandard;
  IDatabase	&m_database;
  ISocket	&m_server;
  ISocket	&m_in;
  std::list<IProtocol *>	m_clients;
};

#endif		/* !SERVER_HPP_ */
