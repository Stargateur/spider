//
// Option.cpp for Option in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Oct 24 15:42:58 2015 Antoine Plaskowski
// Last update Mon Oct 26 04:29:45 2015 Antoine Plaskowski
//

#include	<unistd.h>
#include	<string>
#include	"Option.hpp"

Option::Option(void) :
  m_path_lib_iprotocol("lib/protocolv1/lib_protocolv1_linux.so"),
  m_path_lib_idatabase("lib/database/lib_database_linux.so"),
  m_path_lib_itime("lib/time/lib_time_linux.so"),
  m_path_lib_isocket("lib/socket/lib_socket_linux.so"),
  m_host("::1"),
  m_port("4242")
{
}

Option::~Option(void)
{
}

bool	Option::getopt(int argc, char **argv)
{
  bool	ret = false;
  int	c;
  while ((c = ::getopt(argc, argv, "h:p:")) != -1)
    switch (c)
      {
      case 'h':
	m_host = optarg;
	break;
      case 'p':
	m_port = optarg;
	break;
      default:
	ret = true;
      }
  return (ret);
}

std::string const	&Option::get_path_lib_iprotocol(void) const
{
  return (m_path_lib_iprotocol);
}

std::string const	&Option::get_path_lib_itime(void) const
{
  return (m_path_lib_itime);
}

std::string const	&Option::get_path_lib_idatabase(void) const
{
  return (m_path_lib_idatabase);
}

std::string const	&Option::get_path_lib_isocket(void) const
{
  return (m_path_lib_isocket);
}

std::string const	&Option::get_host(void) const
{
  return (m_host);
}

std::string const	&Option::get_port(void) const
{
  return (m_port);
}
