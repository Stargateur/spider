//
// Database.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 21:04:15 2015 Bertrand-Rapello Baptiste
// Last update Sat Oct 24 19:10:16 2015 Antoine Plaskowski
//

#include	"Database.hpp"

Database::Database(void) :
  m_db(mysql_init(NULL))
{
}

Database::~Database(void)
{
  mysql_close(m_db);
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
  MYSQL_RES *res;
  MYSQL_FIELD *field;
  MYSQL_ROW row;
  int rtr = 0;
  int ret = 0;
  unsigned int nbFields = 0;
  unsigned long long nbRows = 0;
  std::string cmd;
  std::string rtrBis;
  
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
  /*
  mysql_query(m_db, "SELECT * FROM client");
  res = mysql_store_result(m_db);
  nbFields = mysql_num_fields(res);
  nbRows = mysql_num_rows(res);
  field = mysql_fetch_field(res);
  std::cout << "nombre de champ " << nbFields << " nombre de row " <<  nbRows << "nom du champ " << field->name << std::endl;;
  unsigned long *lengths;
  unsigned int i = 0;
  while ((row = mysql_fetch_row(res)) != NULL)
    {
      //lengths = mysql_fetch_lengths(res);
      for (i = 0; i < nbFields; i++)
	{
	  std::cout << "row[" << i << "]  " << row[i] << std::endl;
	}
    }
  */
  return false;
}

bool Database::insert_keyboard(const std::string  & mac_address, const ITime  & tme, std::string event, const std::string & key, const std::string & process)
{
  std::string cmd = "INSERT INTO keyboard_inputbis (id_client, day, hours, id_key, state, id_process) VALUES (";
  std::string clientName;
  MYSQL_RES *res;
  MYSQL_FIELD *field;
  MYSQL_ROW row;
  unsigned int nbFields = 0;
  unsigned long long nbRows = 0;
  int rtr = 0;
  int ret = 0;
  int stop = 0;
  unsigned int i = 0;
  int	lastid = 0;
  
  mysql_query(m_db, "SELECT * FROM client"); 
  res = mysql_store_result(m_db);
  nbFields = mysql_num_fields(res);
  nbRows = mysql_num_rows(res);
  field = mysql_fetch_field(res);

  while ((row = mysql_fetch_row(res)) != NULL && stop != 1)
    {
      //lengths = mysql_fetch_lengths(res);
      for (i = 0; i < nbFields; i+=2)
	{
	  lastid = std::stoi(row[i]);
	  std::cout << "row[" << i << "]  " << row[i] << " et " << row[i+1]  << std::endl;
	  clientName = row[i+1];
	  if (clientName == mac_address)
	    {
	      cmd += row[i];
	      cmd += ", ";
	      stop = 1;
	    }
	}
    }
  std::cout << stop << std::endl;
  if (stop != 1)
    {
      std::string toAdd = "INSERT INTO client (id, mac_addr) VALUES (";
      toAdd += std::to_string(lastid+1);
      toAdd += ", \"";
      toAdd += mac_address;
      toAdd += "\");";
      //mysql_query(m_db, toAdd);
      std::cout << "jai ajoute un client et ma ligne de cmd " << toAdd << std::endl;
      mysql_query(m_db, toAdd.c_str());
      cmd += std::to_string(lastid+1);
      cmd += ", ";
    }

  std::cout << cmd << std::endl;
  cmd += "NULL, NULL, NULL, \"";
  cmd += event;
  cmd += "\", 1);";
  std::cout << cmd << std::endl;
  mysql_query(m_db, cmd.c_str());
  
  //cmd = "INSERT INTO keyboard_inputbis (id_client\"";
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
