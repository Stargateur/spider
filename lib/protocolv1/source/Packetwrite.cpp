//
// Packetwrite.cpp for Packetwrite in /home/plasko_a/projet/cplusplus/cpp_spider/lib/protocolv1
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Oct 25 10:24:10 2015 Antoine Plaskowski
// Last update Mon Oct 26 07:31:45 2015 Antoine Plaskowski
//

#include	<iostream>
#include	"Packetwrite.hpp"

Packetwrite::Packetwrite(void) :
  m_write(0),
  m_write_data(0),
  m_is_write(false)
{
}

bool	Packetwrite::write(ISocket const &socket)
{
  if (m_write >= sizeof(m_buffer))
    return (true);
  uintmax_t	ret = socket.write(m_buffer[m_write], m_size_header + get_size() - m_write);

  if (ret == 0)
    return (true);
  m_write += ret;
  if (m_write < m_size_header + get_size())
    return (false);
  m_is_write = true;
  return (m_write != m_size_header + get_size());
}

bool	Packetwrite::put_string(std::string const &string)
{
  if (string.size() > UINT8_MAX)
    return (true);
  if (put_int<uint8_t>(string.size()))
    return (true);
  for (uintmax_t i = 0; i < string.size(); i++)
    if (put_int<uint8_t>(string[i]) == true)
      return (true);
  return (false);
}

bool	Packetwrite::is_write(void) const
{
  return (m_is_write);
}

void	Packetwrite::set_opcode(Opcode opcode)
{
  m_packet.opcode = opcode;
}

void	Packetwrite::set_id(uint8_t id)
{
  m_packet.id = id;
}

void	Packetwrite::set_size(void)
{
  m_packet.size = m_write_data;
}

void	Packetwrite::reset(void)
{
  m_write = 0;
  m_write_data = 0;
  m_is_write = false;
}
