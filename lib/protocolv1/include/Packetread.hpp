//
// Packetread.hpp for Packetread in /home/plasko_a/projet/cplusplus/cpp_spider/lib/protocolv1
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Oct 25 10:10:39 2015 Antoine Plaskowski
// Last update Tue Nov  3 14:16:37 2015 Antoine Plaskowski
//

#ifndef		PACKETREAD_HPP_
# define	PACKETREAD_HPP_

# include	<limits>
# include	<cstring>
# include	"APacket.hpp"

class	Packetread : public APacket
{
public:
  Packetread(void);
  template<typename T>
  bool	get_int(T &value)
  {
    value = 0;
    for (uintmax_t i = 0; i < sizeof(T); i++)
      {
	value |= (m_packet.data[m_read_data] << (i * std::numeric_limits<uint8_t>::digits));
	if (m_read_data++ == UINT16_MAX)
	  return (true);
      }
    return (false);
  }
  bool	get_string(std::string &string);
  bool	read(ISocket const &socket);
  bool	is_read(void) const;
  void	reset(void);
private:
  uintmax_t	m_read;
  uint16_t	m_read_data;
  bool	m_is_read;
};

#endif		/* !PACKETREAD_HPP_ */
