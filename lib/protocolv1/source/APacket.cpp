//
// APacket.cpp for APacket in /home/plasko_a/projet/cplusplus/cpp_spider/lib/protocolv1
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Oct 25 09:20:05 2015 Antoine Plaskowski
// Last update Mon Oct 26 01:29:25 2015 Antoine Plaskowski
//

#include	"APacket.hpp"

APacket::~APacket(void)
{
}

APacket::Opcode	APacket::get_opcode(void) const
{
  return (m_packet.opcode);
}

uint8_t	APacket::get_id(void) const
{
  return (m_packet.id);
}

uint16_t	APacket::get_size(void) const
{
  return (m_packet.size);
}

uint8_t	APacket::operator[](uint16_t idx) const
{
  return (m_packet.data[idx]);
}
