/*
** create_binded_socket.c for create_binded_socket in /home/plasko_a/projet/epitech/PSU_2014_myirc/source/serveur
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed Mar 11 06:24:48 2015 Antoine Plaskowski
// Last update Tue Oct 20 00:35:47 2015 Antoine Plaskowski
*/

#include	<sys/socket.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<netdb.h>
#include	"create_binded_socket.h"

static int	rec_create_binded_socket(struct addrinfo const * const rp)
{
  int		sfd;

  if (rp == NULL)
    return (-1);
  if ((sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    {
      perror("socket()");
      return (rec_create_binded_socket(rp->ai_next));
    }
  if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
    {
      if (listen(sfd, 42) != -1)
	return (sfd);
      perror("listen()");
    }
  else
    perror("bind()");
  if (close(sfd) == -1)
    perror("close()");
  return (rec_create_binded_socket(rp->ai_next));
}

int			create_binded_socket(char const * const port)
{
  struct addrinfo	*result;
  struct addrinfo	hints;
  int			ret;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET6;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  hints.ai_protocol = IPPROTO_TCP;
  if ((ret = getaddrinfo(NULL, port, &hints, &result)) != 0)
    {
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
      return (-1);
    }
  ret = rec_create_binded_socket(result);
  freeaddrinfo(result);
  return (ret);
}
