//
// IDatabase.hpp for IDatabase in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 23:43:13 2015 Antoine Plaskowski
// Last update Sun Oct 25 05:39:21 2015 Antoine Plaskowski
//

#ifndef		IDATABASE_HPP_
# define	IDATABASE_HPP_

#include	<string>
#include	"ITime.hpp"

class	IDatabase
{
public:
  virtual ~IDatabase(void);
  virtual bool  connect(std::string const & host="localhost", std::string const  &port="0", std::string const &user="", std::string const &passwd="", std::string const &db="") = 0;
  virtual bool select_db(std::string const & db) = 0;
  virtual bool insert_keyboard(const std::string  & mac_address, const ITime  & tme, std::string event, const std::string & key, const std::string & process) = 0;
  virtual bool insert_mouse(const std::string & mac_addresse, const ITime & tme, std::string event, const std::string & button, const std::string & process) = 0;
  virtual bool insert_log(const std::string & mac_addresse, const std::string & log) = 0;
  virtual bool show(const std::string & mac_addresse) = 0;
};

extern "C"
{
# define	NAME_FCT_NEW_IDATABASE	"new_idatabase"
  IDatabase	&new_idatabase(void);
  typedef	IDatabase &(*fct_new_idatabase)(void);
}


#endif		/* !IDATABASE_HPP_ */
