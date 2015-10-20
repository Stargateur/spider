/*
** accept_client.c for accept_client in /home/plasko_a/projet/epitech/PSU_2014_myftp/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Mar 11 06:48:53 2015 Antoine Plaskowski
// Last update Mon Oct 19 18:46:37 2015 Antoine Plaskowski
*/

#include	<iostream>
#include	<arpa/inet.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<stdio.h>
#include	<netdb.h>
#include	<string.h>
#include	"accept_client.h"

char const	*get_addr(t_sockaddr_in const * const addr)
{
  static union
  {
    char	base;
    char	ipv4[INET_ADDRSTRLEN];
    char	ipv6[INET6_ADDRSTRLEN];
  }		ip;

  switch (addr->base.sa_family)
    {
    case AF_INET:
      if (inet_ntop(AF_INET, &addr->ipv4.sin_addr,
		    ip.ipv4, sizeof(ip.ipv4)) != NULL)

	perror("inet_ntop()");
      break;
    case AF_INET6:
      if (inet_ntop(AF_INET6, &addr->ipv6.sin6_addr,
		    ip.ipv6, sizeof(ip.ipv6)) != NULL)
	perror("inet_ntop()");
      break;
    default:
      ip.base = '\0';
    }
  return (&ip.base);
}

int		accept_client(int const sock, t_clientaddr *ca)
{
  int		cfd;

  if (ca != NULL)
    {
      ca->len = sizeof(ca->addr);
      memset(&ca->addr, 0, sizeof(ca->addr));
      cfd = accept(sock, &ca->addr.base, &ca->len);
      ca->cfd = cfd;
    }
  else
    cfd = accept(sock, NULL, NULL);
  if (cfd == -1)
    perror("accept()");
  return (cfd);
}
