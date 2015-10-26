//
// Server.cpp for Server in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Oct 24 17:20:22 2015 Antoine Plaskowski
// Last update Mon Oct 26 04:51:48 2015 Antoine Plaskowski
//

#include	"Server.hpp"

#include	"unistd.h"

Server::Server(Option const &option) :
  m_dll_idatabase(option.get_path_lib_idatabase()),
  m_dll_itime(option.get_path_lib_itime()),
  m_dll_iprotocol(option.get_path_lib_iprotocol()),
  m_dll_isocket(option.get_path_lib_isocket()),
  m_new_idatabase(m_dll_idatabase.get_symbole<decltype(m_new_idatabase)>(NAME_FCT_NEW_IDATABASE)),
  m_new_itime(m_dll_itime.get_symbole<decltype(m_new_itime)>(NAME_FCT_NEW_ITIME)),
  m_new_iprotocol(m_dll_iprotocol.get_symbole<decltype(m_new_iprotocol)>(NAME_FCT_NEW_IPROTOCOL)),
  m_iselect(m_dll_isocket.get_symbole<decltype(m_iselect)>(NAME_FCT_ISELECT)),
  m_new_iserver(m_dll_isocket.get_symbole<decltype(m_new_iserver)>(NAME_FCT_NEW_ISERVER)),
  m_new_istandard(m_dll_isocket.get_symbole<decltype(m_new_istandard)>(NAME_FCT_NEW_ISTANDARD)),
  m_database(m_new_idatabase()),
  m_server(m_new_iserver(option.get_host(), option.get_port())),
  m_in(m_new_istandard(ISocket::IN)),
  m_clients()
{
}

Server::~Server(void)
{
  delete &m_database;
  delete &m_server;
  delete &m_in;
  for (auto it = m_clients.begin(); it != m_clients.end(); it++)
    delete *it;
}


bool	Server::run(void)
{
  m_server.want_read();
  for (auto it = m_clients.begin(); it != m_clients.end(); it++)
    (*it)->select();
  m_iselect(nullptr);
  if (m_server.can_read())
    m_clients.push_back(&m_new_iprotocol(m_server.accept(), m_new_itime()));
  bool	remove = false;
  for (auto it = m_clients.begin(); it != m_clients.end(); it++)
    {
      if (*it != nullptr)
	if ((*it)->run(m_database) == true)
	  {
	    remove = true;
	    *it = nullptr;
	  }
    }
  if (remove == true)
    m_clients.remove(nullptr);
  return (false);
}
