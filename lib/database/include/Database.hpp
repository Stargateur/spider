//
// Database.hh for $ in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:57:19 2015 Bertrand-Rapello Baptiste
// Last update Fri Nov  6 16:19:39 2015 Antoine Plaskowski
//

#ifndef		DATABASE_HPP_
# define	DATABASE_HPP_

#include	<iostream>
#include	<string>
#include	<ctime>
#include	<cstdint>
#include	<mysql.h>
#include	"IDatabase.hpp"

class Database : public IDatabase
{
public:
  Database(std::string const &host,
	   std::string const &port,
	   std::string const &user);
  ~Database(void);
  bool	select_db(std::string const &db);
  bool	insert_keyboard(std::string const &mac_address, IProtocol::Keyboard const &keyboard);
  bool	insert_mouse(std::string const &mac_address, IProtocol::Mouse const &mouse);
  bool	insert_log(std::string const &mac_address, IProtocol::Log const &log);
  bool	show(std::string const &mac_address);
private:
  uint64_t	get_id(std::string const &table, std::string const &column, std::string const &id_name, std::string const &search);    
  MYSQL	*m_sql;
};

#endif		/* !DATABASE_HPP_ */
