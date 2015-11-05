//
// IDatabase.hpp for IDatabase in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 23:43:13 2015 Antoine Plaskowski
// Last update Thu Nov  5 21:43:57 2015 Antoine Plaskowski
//

#ifndef		IDATABASE_HPP_
# define	IDATABASE_HPP_

#include	<string>
#include	"IProtocol.hpp"
#include	"ITime.hpp"

class	IDatabase
{
public:
  virtual ~IDatabase(void);
  virtual bool select_db(std::string const &db) = 0;
  virtual bool insert_keyboard(std::string const &mac_addresse, IProtocol::Keyboard const &keyboard) = 0;
  virtual bool insert_mouse(std::string const &mac_addresse, IProtocol::Mouse const &mouse) = 0;
  virtual bool insert_log(std::string const &mac_addresse, IProtocol::Log const &log) = 0;
  virtual bool show(std::string const &mac_addresse) = 0;
};

extern "C"
{
# define	NAME_FCT_NEW_IDATABASE	"new_idatabase"
#ifdef	__linux__
  IDatabase	&new_idatabase(std::string const &host = "localhost",
			       std::string const &port = "0",
			       std::string const &user = "",
			       std::string const &passwd = "");
#else
  __declspec(dllexport) IDatabase	&new_idatabase(std::string const &host = "localhost",
						       std::string const &port = "0",
						       std::string const &user = "",
						       std::string const &passwd = "");
#endif
  typedef	IDatabase &(*fct_new_idatabase)(void);
  typedef	IDatabase &(&ref_new_idatabase)(void);
}


#endif		/* !IDATABASE_HPP_ */
