//
// APacket.hpp for APacket in /home/plasko_a/projet/cplusplus/cpp_spider/lib/protocolv1
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Oct 25 09:19:33 2015 Antoine Plaskowski
// Last update Mon Oct 26 01:26:55 2015 Antoine Plaskowski
//

#ifndef		PACKET_HPP_
# define	PACKET_HPP_

# include	<cstdint>
# include	"ISocket.hpp"

class	APacket
{
public:
  enum  Opcode : uint8_t
  {
    RESULT = 0,
    MAC_ADDRESS = 1,
    VERSION = 2,
    CONNECT = 3,
    DISCONNECT = 4,
    SERVERCMD = 5,
    CLIENTLOG = 6,
    PING = 7,
    PONG = 8,
    KEYBOARD = 9,
    MOUSE = 10
  };
  virtual ~APacket(void);
  Opcode	get_opcode(void) const;
  uint8_t	get_id(void) const;
  uint16_t	get_size(void) const;
  uint8_t	operator[](uint16_t idx) const;
  virtual void	reset(void) = 0;
protected:
  union
  {
    struct __attribute__((__packed__))
    {
      Opcode	opcode;
      uint8_t	id;
      uint16_t	size;
      uint8_t	data[UINT16_MAX];
    }	m_packet;
    uint8_t	m_buffer[sizeof(m_packet)];
  };
  static const	uintmax_t	m_size_header = sizeof(m_packet.opcode) + sizeof(m_packet.id) + sizeof(m_packet.size);
};

#endif		/* !PACKET_HPP_ */
