//
// IDatabase.hpp for IDatabase in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 23:43:13 2015 Antoine Plaskowski
// Last update Wed Oct 21 23:46:01 2015 Antoine Plaskowski
//

#ifndef		IDATABASE_HPP_
# define	IDATABASE_HPP_

#include	<string>

class	IDatabase
{
public:
  bool connect(string const * host = nullptr, string const * port = nullptr, string const * user = nullptr, string const * passwd = nullptr, string const * db = nullptr);
  bool select_db(string const & db);
};

#endif		/* !IDATABASE_HPP_ */
