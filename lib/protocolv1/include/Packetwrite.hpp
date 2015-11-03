//
// Packetwrite.hpp for Packetwrite in /home/plasko_a/projet/cplusplus/cpp_spider/lib/protocolv1
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Oct 25 10:10:39 2015 Antoine Plaskowski
// Last update Tue Nov  3 14:16:53 2015 Antoine Plaskowski
//

#ifndef		PACKETWRITE_HPP_
# define	PACKETWRITE_HPP_

# include	<limits>
# include	"APacket.hpp"

class	Packetwrite : public APacket
{
public:
  Packetwrite(void);
  template<typename T>
  bool	put_int(T const value)
  {
    for (uintmax_t i = 0; i < sizeof(T); i++)
      {
	m_packet.data[m_write_data] = (value >> (i * std::numeric_limits<uint8_t>::digits));
	if (m_write_data++ == UINT16_MAX)
	  return (true);
      }
    return (false);
  }
  bool	put_string(std::string const &string);
  bool	write(ISocket const &socket);
  bool	is_write(void) const;
  void	set_opcode(Opcode opcode);
  void	set_id(uint8_t id);
  void	set_size(void);
  void	reset(void);
private:
  uintmax_t	m_write;
  uint16_t	m_write_data;
  bool	m_is_write;
};

#endif		/* !PACKETWRITE_HPP_ */
