//
// Option.cpp for Option in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Oct 24 15:42:58 2015 Antoine Plaskowski
// Last update Sat Oct 24 17:44:55 2015 Antoine Plaskowski
//

#include	<unistd.h>
#include	"Option.hpp"

Option::Option(std::string const &path_lib_iprotocol, std::string const &path_lib_idatabase, std::string const &path_lib_itime, std::string const &path_lib_isocket) :
  m_path_lib_iprotocol(path_lib_iprotocol),
  m_path_lib_idatabase(path_lib_idatabase),
  m_path_lib_itime(path_lib_itime),
  m_path_lib_isocket(path_lib_isocket)
{
}

Option::~Option(void)
{
}

bool	Option::getopt(int argc, char **argv)
{
  if (argv == NULL)
    return (true);
  bool	ret = false;
  int	c;
  while ((c = ::getopt(argc, argv, "")) != -1)
    switch (c)
      {
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
