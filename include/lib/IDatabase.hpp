//
// IDatabase.hpp for IDatabase in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 23:43:13 2015 Antoine Plaskowski
// Last update Thu Oct 22 09:21:25 2015 Antoine Plaskowski
//

#ifndef		IDATABASE_HPP_
# define	IDATABASE_HPP_

#include	<string>

class	IDatabase
{
public:
  bool connect(std::string const * host = nullptr, std::string const * port = nullptr, std::string const * user = nullptr, std::string const * passwd = nullptr, std::string const * db = nullptr);
  bool select_db(std::string const & db);
};

#endif		/* !IDATABASE_HPP_ */
