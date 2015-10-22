//
// c_accept.cpp for c_accept in /home/plasko_a/projet/cplusplus/cpp_spider/lib/socket
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Oct 22 05:26:33 2015 Antoine Plaskowski
// Last update Thu Oct 22 05:28:07 2015 Antoine Plaskowski
//

#include	<sys/socket.h>
#include	"Socket.hpp"

int	c_accept(int socket, struct sockaddr *addr, socklen_t *addrlen)
{
  return (accept(socket, addr, addrlen));
}
