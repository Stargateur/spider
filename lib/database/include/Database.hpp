//
// Database.hh for $ in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:57:19 2015 Bertrand-Rapello Baptiste
// Last update Fri Oct 23 16:21:59 2015 Bertrand-Rapello Baptiste
//

#ifndef DATABASE_HPP_
# define DATABASE_HPP_

#include <iostream>
#include <string>
#include <ctime>
#include <cstdint>
#include <mysql.h>
#include "ITime.hpp"
#include "IDatabase.hpp"

class Database : public IDatabase
{
public:
  Database(void);
  ~Database(void);
  
public:
  bool	connect(std::string const &host="localhost", std::string const &port="0", std::string const &user = "", std::string const &passwd="", std::string const  &db="");
  bool select_db(std::string const & db);
  bool insert_keyboard(const std::string  & mac_address, const ITime  & tme, std::string event, const std::string & key, const std::string & process);
  bool insert_mouse(const std::string & mac_addresse, const ITime & tme, std::string event, const std::string & button, const std::string & process);
  bool insert_log(const std::string & mac_addresse, const std::string & log);
  bool show(const std::string & mac_addresse);
private:
  MYSQL  *m_db;
};

#endif
