//
// Packetread.cpp for Packetread in /home/plasko_a/projet/cplusplus/cpp_spider/lib/protocolv1
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Oct 25 10:24:10 2015 Antoine Plaskowski
// Last update Mon Oct 26 07:27:28 2015 Antoine Plaskowski
//

#include	<iostream>
#include	"Packetread.hpp"

Packetread::Packetread(void) :
  m_read(0),
  m_read_data(0),
  m_is_read(false)
{
}

bool	Packetread::read(ISocket const &socket)
{
  if (m_read >= sizeof(m_buffer))
    return (true);
  uintmax_t	ret;
  if (m_read < m_size_header)
    ret = socket.read(m_buffer[m_read], m_size_header - m_read);
  else
    ret = socket.read(m_buffer[m_read], m_size_header + get_size() - m_read);
  if (ret == 0)
    return (true);
  m_read += ret;
  if (m_read < m_size_header)
    return (false);
  if (m_read < m_size_header + get_size())
    return (false);
  m_is_read = true;
  return (m_read != m_size_header + get_size());
}

bool	Packetread::get_string(std::string &string)
{
  uint8_t       size;

  string.erase();
  if (get_int<uint8_t>(size) == true)
    return (true);
  for (uintmax_t i = 0; i < size; i++)
    {
      uint8_t   c;
      if (get_int<uint8_t>(c) == true)
	return (true);
      string.push_back(c);
    }
  return (false);
}

bool	Packetread::is_read(void) const
{
  return (m_is_read);
}

void	Packetread::reset(void)
{
  m_read = 0;
  m_read_data = 0;
  m_is_read = false;
}
