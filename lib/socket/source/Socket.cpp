//
// Socket.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 22:51:48 2015 Bertrand-Rapello Baptiste
// Last update Thu Oct 22 09:35:14 2015 Antoine Plaskowski
//

#include	<sys/socket.h>
#include	<netdb.h>
#include	<unistd.h>
#include	<cstring>
#include	<algorithm>
#include	"ISocket.hpp"
#include	"Socket.hpp"

int	Socket::m_nfds = Socket::FAIL;
fd_set	Socket::m_fds = {};
fd_set	Socket::m_readfds = {};
fd_set	Socket::m_writefds = {};

Socket::Socket(void) :
  m_fd(FAIL),
  m_ip(),
  m_sockaddr({})
{
}

Socket::~Socket(void)
{
  if (m_fd != FAIL)
    FD_CLR(m_fd, &m_fds);
}

bool	Socket::select(ITime const *timeout) const
{
  std::memcpy(&m_readfds, &m_fds, sizeof(m_fds));
  std::memcpy(&m_writefds, &m_fds, sizeof(m_fds));
  int	ret;

  if (timeout == nullptr)
    ret = pselect(m_nfds + 1, &m_readfds, &m_writefds, NULL, NULL, NULL);
  else
    {
      struct timespec	time = {timeout->get_second(), timeout->get_nano()};

      ret = pselect(m_nfds + 1, &m_readfds, &m_writefds, NULL, &time, NULL);
    }
  if (ret == -1)
    {
      perror("select()");
      return (true);
    }
  return (false);
}

bool	Socket::aux_server(struct addrinfo const *rp)
{
  int	fd;

  if (rp == NULL)
    return (true);
  if ((fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    {
      perror("socket()");
      return (aux_server(rp->ai_next));
    }
  if (bind(fd, rp->ai_addr, rp->ai_addrlen) == 0)
    {
      if (listen(fd, 42) != -1)
	{
	  set_fd(fd);
	  m_sockaddr.base = *rp->ai_addr;
	  return (false);
	}
      perror("listen()");
    }
  else
    perror("bind()");
  if (close(fd) == -1)
    perror("close()");
  return (aux_server(rp->ai_next));
}

bool	 Socket::server(std::string host, std::string port)
{
  struct addrinfo	*result;
  struct addrinfo	hints =
    {
      AI_PASSIVE,
      AF_UNSPEC,
      SOCK_STREAM,
      IPPROTO_TCP,
      0, NULL, NULL, NULL};
  int	status = getaddrinfo(host.c_str(), port.c_str(), &hints, &result);
  if (status != 0)
    {
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
      return (true);
    }

  bool ret = aux_server(result);
  freeaddrinfo(result);
  return (ret);
}

bool	Socket::aux_client(struct addrinfo const *rp)
{
  if (rp == NULL)
    return (true);

  int	fd;
  if ((fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    {
      perror("socket()");
      return (aux_client(rp->ai_next));
    }
  if (connect(fd, rp->ai_addr, rp->ai_addrlen) == 0)
    {
      set_fd(fd);
      m_sockaddr.base = *rp->ai_addr;
      return (false);
    }
  perror("connect()");
  if (close(fd) == -1)
    perror("close()");
  return (aux_client(rp->ai_next));
}

bool	 Socket::client(std::string host, std::string port)
{
  struct addrinfo	*result;
  struct addrinfo	hints =
    {
      0,
      AF_UNSPEC,
      SOCK_STREAM,
      IPPROTO_TCP,
      0, NULL, NULL, NULL
    };
  int	status = getaddrinfo(host.c_str(), port.c_str(), &hints, &result);
  if (status != 0)
    {
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
      return (true);
    }

  bool ret = aux_client(result);
  freeaddrinfo(result);
  return (ret);  
}

ISocket	*Socket::accept(void) const
{
  Socket	*socket(new Socket());
  socklen_t	len = sizeof(sockaddr);

  std::memset(&socket->m_sockaddr.base, 0, sizeof(m_sockaddr));
  int	fd = c_accept(m_fd, &socket->m_sockaddr.base, &len);
  if (fd == -1)
    {
      perror("accept()");
      delete socket;
      return (nullptr);
    }
  socket->set_fd(fd);
  return (socket);
}

bool	Socket::set_ip(void)
{
  union
  {
    char	base;
    char	ipv4[INET_ADDRSTRLEN];
    char	ipv6[INET6_ADDRSTRLEN];
  }		ip;

  switch (m_sockaddr.base.sa_family)
    {
    case AF_INET:
      if (inet_ntop(AF_INET, &m_sockaddr.ipv4.sin_addr,
		    ip.ipv4, sizeof(ip.ipv4)) != NULL)
	{
	  ip.base = '\0';
	  perror("inet_ntop()");
	  return (true);
	}
      break;
    case AF_INET6:
      if (inet_ntop(AF_INET6, &m_sockaddr.ipv6.sin6_addr,
		    ip.ipv6, sizeof(ip.ipv6)) != NULL)
	{
	  ip.base = '\0';
	  perror("inet_ntop()");
	  return (true);
	}
      break;
    default:
      fprintf(stderr, "can't set the ip\n");
      return (true);
    }
  m_ip = ip.base;
  return (false);
}

std::string const	&Socket::get_ip(void) const
{
  return (m_ip);
}

bool	 Socket::standard_io(ISocket::io io)
{
  switch (io)
    {
    case IN:
      set_fd(IN);
      break;
    case OUT:
      set_fd(OUT);
      break;
    case ERR:
      set_fd(ERR);
      break;
    default:
      return (true);
    }
  return (false);
}

bool	 Socket::can_read(void) const
{
  if (m_fd != FAIL)
    return (FD_ISSET(m_fd, &m_readfds) != 0);
  return (false);
}

bool	 Socket::can_write(void) const
{
  if (m_fd != FAIL)
    return (FD_ISSET(m_fd, &m_writefds) != 0);
  return (false);
}

bool	Socket::set_fd(int fd)
{
  if (fd == FAIL)
    return (true);
  if (m_fd != FAIL)
    FD_CLR(m_fd, &m_fds);
  m_fd = fd;
  FD_SET(m_fd, &m_fds);
  m_nfds = std::max<int>(m_nfds, m_fd);
  set_ip();
  return (true);
}

ISocket	*new_socket(void)
{
  return (new Socket());
}
