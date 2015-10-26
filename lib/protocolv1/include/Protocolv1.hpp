//
// Protocolv1.hpp for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 22:50:40 2015 Bertrand-Rapello Baptiste
// Last update Mon Oct 26 11:14:59 2015 Antoine Plaskowski
//

#ifndef		PROTOCOLV1_HPP_
# define	PROTOCOLV1_HPP_

# include	<string>
# include	<array>
# include	"IProtocol.hpp"
# include	"ITime.hpp"
# include	"Packetread.hpp"
# include	"Packetwrite.hpp"

class Protocolv1 : public IProtocol
{
private:
  enum	Errorcode : uint8_t
  {
    NO_ERROR = 0,
    IGNORED = 1,
    UNKNOWN_ERROR = 2,
    CLIENT_ALREADY_STARTED = 3,
    CLIENT_ALREADY_STOPPED = 4,
    CLIENT_ALREADY_MUTED = 5,
    CLIENT_ALREADY_UNMUTED = 6,
    INVALID_COMMAND = 7,
    INVALID_KEYBOARD_INPUT = 8,
    INVALID_MOUSE_INPUT = 9,
    UNKNOWN_ID = 10,
    WRONG_PROTOCOL_VERSION = 11,
    WRONG_MAC_ADDRESS = 12,
    CONNECT_FAIL = 13,
    DISCONNECT_FAIL = 14
  };
public:
  Protocolv1(ISocket &socket, ITime &time);
  ~Protocolv1(void);
private:
  Protocolv1(Protocolv1 const &source);
  Protocolv1	&operator=(Protocolv1 const &source);
public:
  bool	select(void) const;
  bool	run(ITime const *timeout = nullptr);
  bool	server_command(Commandcode command);
  std::string const	&get_mac_address(void) const;
  bool	mac_address(std::string const &mac_address);
  bool	log(IProtocol::Log const &log);
  bool	keyboard(std::vector<IProtocol::Keyboard> const &keyboard);
  bool	mouse(std::vector<IProtocol::Mouse> const &mouse);
  ISocket const	&get_isocket(void) const;
  IProtocol::Log const	&get_log(void) const;
  bool	is_log(void) const;
  IProtocol::Keyboard const	&get_keyboard(void) const;
  bool	is_keyboard(void) const;
  IProtocol::Mouse const	&get_mouse(void) const;
  bool	is_mouse(void) const;
private:
  bool	read(void);
  bool	write(void);
  bool	timeout(ITime const &timeout);
  bool	read_result(void);
  bool	write_result(Errorcode code, uint8_t id);
  bool	read_mac_address(void);
  bool	write_mac_address(std::string const &mac_address);
  bool	read_version(void);
  bool	write_version(void);
  bool	read_connect(void);
  bool	write_connect(void);
  bool	read_disconnect(void);
  bool	write_disconnect(void);
  bool	read_servercmd(void);
  bool	write_servercmd(Commandcode command);
  bool	read_clientlog(void);
  bool	write_clientlog(IProtocol::Log const &log);
  bool	read_ping(void);
  bool	write_ping(void);
  bool	read_pong(void);
  bool	write_pong(void);
  bool	read_keyboard(void);
  bool	write_keyboard(std::vector<Keyboard> const &keyboard);
  bool	read_mouse(void);
  bool	write_mouse(std::vector<Mouse> const &mouse);
  bool	write_packet(APacket::Opcode code);
private:
  ISocket	&m_socket;
  ITime	&m_last_read;
  std::string	m_mac_address;
  std::array<Packetwrite, UINT8_MAX>	m_packets;
  uint8_t	m_write;
  uint8_t	m_to_write;
  Packetread	m_read;
  bool	m_is_connect;
  bool	m_is_stop;
  bool	m_is_mute;
  bool	m_wait_pong;
  IProtocol::Log	m_log;
  bool	m_is_log;
  IProtocol::Keyboard	m_keyboard;
  bool	m_is_keyboard;
  IProtocol::Mouse	m_mouse;
  bool	m_is_mouse;
};

#endif	/* !IPROTOCOLV1_HPP_ */
