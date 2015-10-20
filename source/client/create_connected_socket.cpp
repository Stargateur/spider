/*
** create_connected_socket.c for create_connected_socket in /home/plasko_a/projet/epitech/PSU_2014_myirc/source/client
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Wed Mar 11 06:23:56 2015 Antoine Plaskowski
** Last update Wed Apr  8 18:25:56 2015 Antoine Plaskowski
*/

#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<netdb.h>
#include	"create_connected_socket.h"

static int	rec_create_connected_socket(struct addrinfo const * const rp)
{
  int		sfd;

  if (rp == NULL)
    return (-1);
  if ((sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    {
      perror("socket()");
      return (rec_create_connected_socket(rp->ai_next));
    }
  if (connect(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
    return (sfd);
  perror("connect()");
  if (close(sfd) == -1)
    perror("close()");
  return (rec_create_connected_socket(rp->ai_next));
}

int			create_connected_socket(char const * const host,
						char const * const port)
{
  struct addrinfo	*result;
  struct addrinfo	hints;
  int			ret;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  if ((ret = getaddrinfo(host, port, &hints, &result)) != 0)
    {
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
      return (-1);
    }
  ret = rec_create_connected_socket(result);
  freeaddrinfo(result);
  return (ret);
}
