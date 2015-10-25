//
// Option.hpp for Option in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Oct 24 15:43:06 2015 Antoine Plaskowski
// Last update Sat Oct 24 19:01:58 2015 Antoine Plaskowski
//

#ifndef		OPTION_HPP_
# define	OPTION_HPP_

# include	<string>

class	Option
{
public:
  Option(std::string const &path_lib_iprotocol = "lib/protocolv1/lib_protocolv1_linux.so",
	 std::string const &path_lib_idatabase = "lib/database/lib_database_linux.so",
	 std::string const &path_lib_itime = "lib/time/lib_time_linux.so",
	 std::string const &path_lib_isocket = "lib/socket/lib_socket_linux.so");
  ~Option(void);
  bool	getopt(int argc, char **argv);
  std::string const	&get_path_lib_iprotocol(void) const;
  std::string const	&get_path_lib_idatabase(void) const;
  std::string const	&get_path_lib_itime(void) const;
  std::string const	&get_path_lib_isocket(void) const;
private:
  std::string	m_path_lib_iprotocol;
  std::string	m_path_lib_idatabase;
  std::string	m_path_lib_itime;
  std::string	m_path_lib_isocket;
};

#endif		/* !OPTION_HPP_ */
