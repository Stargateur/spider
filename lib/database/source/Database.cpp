//
// Database.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 21:04:15 2015 Bertrand-Rapello Baptiste
// Last update Thu Oct 22 22:33:22 2015 Bertrand-Rapello Baptiste
//

#include	"Database.hpp"

Database::Database(void) :
  m_db(mysql_init(NULL))
{
}

Database::~Database(void)
{
}

bool  Database::connect(std::string const &host, std::string const &port, std::string const &user, std::string const &passwd, std::string const &db)
{
  unsigned int portInt;

  portInt = std::stoul(port, nullptr, 10);
  std::cout << "le port est " << portInt << std::endl;
  mysql_real_connect(m_db, host.c_str(), user.c_str(), passwd.c_str(), db.c_str(), portInt, NULL, 0);
  return false;
}

bool Database::select_db(std::string const & db)
{
  int rtr = 0;
  std::string cmd;

  cmd = "CREATE DATABASE ";
  rtr = mysql_select_db(m_db, db.c_str());
  if (rtr != 0)
    {
      std::cout << "il faut créer la bdd" << std::endl;
      cmd += db;
      rtr = mysql_query(m_db, cmd.c_str());
      if (rtr != 0)
	return true;
      else
	{
	  rtr = mysql_select_db(m_db, db.c_str());
	  cmd = "CREATE TABLE (id int, mac_address VARCHAR(18));";
	  rtr = mysql_query(m_db, cmd.c_str());
	}
    }
  return false;
}

bool Database::insert_keyboard(const std::string  & mac_address, const ITime  & tme, std::string event, const std::string & key, const std::string & process)
{
  
  return false;
}

bool Database::insert_mouse(const std::string & mac_addresse, const ITime & tme, std::string event, const std::string & button, const std::string & process)
{
  return false;
}

bool Database::insert_log(const std::string & mac_addresse, const std::string & log)
{
  return false;
}

bool Database::show(const std::string & mac_addresse)
{
  return false;
}

IDatabase	*new_idatabase(void)
{
  return (new Database());
}
