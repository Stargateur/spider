//
// Option.hpp for Option in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Oct 24 15:43:06 2015 Antoine Plaskowski
// Last update Fri Nov  6 12:12:58 2015 Antoine Plaskowski
//

#ifndef		OPTION_HPP_
# define	OPTION_HPP_

# include	<string>

class	Option
{
public:
  Option(void);
  ~Option(void);
  bool	getopt(int argc, char **argv);
  std::string const	&get_path_lib_iprotocol(void) const;
  std::string const	&get_path_lib_idatabase(void) const;
  std::string const	&get_path_lib_itime(void) const;
  std::string const	&get_path_lib_isocket(void) const;
  std::string const	&get_host(void) const;
  std::string const	&get_port(void) const;
  std::string const	&get_host_database(void) const;
  std::string const	&get_port_database(void) const;
  std::string const	&get_user_database(void) const;
  std::string const	&get_password_database(void) const;
private:
  std::string	m_path_lib_iprotocol;
  std::string	m_path_lib_idatabase;
  std::string	m_path_lib_itime;
  std::string	m_path_lib_isocket;
  std::string	m_host;
  std::string	m_port;
  std::string	m_host_database;
  std::string	m_port_database;
  std::string	m_user_database;
};

#endif		/* !OPTION_HPP_ */
