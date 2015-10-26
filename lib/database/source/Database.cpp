//
// Database.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 21:04:15 2015 Bertrand-Rapello Baptiste
// Last update Mon Oct 26 15:43:17 2015 Bertrand-Rapello Baptiste
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

bool Database::insert_keyboard(const std::string  & mac_address, const ITime  & tme, std::string event, const std::string & key, const std::string & process)
{
  std::string cmd = "INSERT INTO keyboard_input (id_client, day, hours, id_key, state, id_process) VALUES (";
  std::string clientName;
  std::string keyb_name;
  std::string soft_name;
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

  /* d abord je parcour les clients */
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
      /* le client n'existe pas je le rajoute */
      std::string toAdd = "INSERT INTO client (id, mac_addr) VALUES (";
      toAdd += std::to_string(lastid+1);
      toAdd += ", \"" + mac_address + "\");";
      //toAdd += mac_address;
      //toAdd += "\");";
      std::cout << "jai ajoute un client et ma ligne de cmd " << toAdd << std::endl;
      mysql_query(m_db, toAdd.c_str());
      cmd += std::to_string(lastid+1);
      cmd += ", ";
    }

  /* ici on va s occuper de la date */

  /* pour le moment c'est a Null */
  std::cout << cmd << std::endl;
  cmd += "NULL, NULL, ";

  stop = 0;
  /* ici on va parcourir les id des touches */
  mysql_query(m_db, "SELECT * FROM key_string_bis");
  res = mysql_store_result(m_db);
  nbFields = mysql_num_fields(res);
  nbRows = mysql_num_rows(res);
  field = mysql_fetch_field(res);
  lastid = 0;
  while ((row = mysql_fetch_row(res)) != NULL && stop != 1)
    {
      for (i = 0; i < nbFields; i+=2)
	{
	  lastid = std::stoi(row[i]);
	  std::cout << "row[" << i << "]  " << row[i] << " et " << row[i+1]  << std::endl;
	  keyb_name = row[i+1];
	  if (keyb_name == key)
	    {
	      cmd += row[i];
	      cmd += ", ";
	      stop = 1;
	    }
	}
    }
  if (stop != 1)
    {
      /* la touche n'existe pas je le rajoute */
      std::string toAdd = "INSERT INTO key_string_bis (id, id_key) VALUES (";
      toAdd += std::to_string(lastid+1);
      toAdd += ", \"" + key + "\");";
      //toAdd += key;
      //toAdd += "\");";
      std::cout << "jai ajoute une touche et ma ligne de cmd " << toAdd << std::endl;
      mysql_query(m_db, toAdd.c_str());
      cmd += std::to_string(lastid+1);
      cmd += ", ";
    }

  cmd += "\"";
  cmd += event;
  cmd += "\", ";

  /* et maintenant de l'application */
  mysql_query(m_db, "SELECT * FROM software_used");
  res = mysql_store_result(m_db);
  nbFields = mysql_num_fields(res);
  nbRows = mysql_num_rows(res);
  field = mysql_fetch_field(res);
  lastid = 0;
  stop = 0;
  while ((row = mysql_fetch_row(res)) != NULL && stop != 1)
    {
      //lengths = mysql_fetch_lengths(res);
      for (i = 0; i < nbFields; i+=2)
	{
	  lastid = std::stoi(row[i]);
	  std::cout << "row[" << i << "]  " << row[i] << " et " << row[i+1]  << std::endl;
	  soft_name = row[i+1];
	  if (process == soft_name)
	    {
	      cmd += row[i];
	      stop = 1;
	    }
	}
    }
  if (stop != 1)
    {
      /* l application n'existe pas je le rajoute */
      std::string toAdd = "INSERT INTO software_used (id, soft_name) VALUES (";
      toAdd += std::to_string(lastid+1);
      toAdd += ", \"" + process + "\");";
      std::cout << "to add  " << toAdd << std::endl;
      mysql_query(m_db, toAdd.c_str());
      cmd += std::to_string(lastid+1);
    }

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
