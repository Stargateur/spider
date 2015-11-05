//
// Socket.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 22:51:48 2015 Bertrand-Rapello Baptiste
// Last update Tue Nov  3 12:58:14 2015 Antoine Plaskowski
//

#include	<sys/socket.h>
#include	<netdb.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<cstring>
#include	<iostream>
#include	<algorithm>
#include	<exception>
#include	"ISocket.hpp"
#include	"Socket.hpp"

int	Socket::m_nfds = -1;
fd_set	Socket::m_readfds = {};
fd_set	Socket::m_writefds = {};

Socket::Socket(std::string const &ip, int fd) :
  m_fd(fd),
  m_ip(ip)
{
  if (fcntl(fd, F_GETFD) == -1)
    {
      perror("fcntl()");
      throw SocketException("fd invalid");
    }
}

Socket::~Socket(void)
{
  if (m_fd > 2)
    close(m_fd);
  FD_CLR(m_fd, &m_writefds);
  FD_CLR(m_fd, &m_readfds);
}

bool	Socket::select(ITime const *timeout)
{
  int	ret;

  if (timeout == nullptr)
    ret = pselect(m_nfds + 1, &m_readfds, &m_writefds, NULL, NULL, NULL);
  else
    {
      struct timespec	time = {timeout->get_second(), timeout->get_nano()};
      ret = pselect(m_nfds + 1, &m_readfds, &m_writefds, NULL, &time, NULL);
    }
  m_nfds = -1;
  if (ret == -1)
    {
      perror("select()");
      return (true);
    }
  return (false);
}

ISocket	&Socket::accept(void) const
{
  union
  {
    struct sockaddr	base;
    struct sockaddr_in	ipv4;
    struct sockaddr_in6	ipv6;
  }	sockaddr;
  socklen_t	len = sizeof(sockaddr);
  std::memset(&sockaddr.base, 0, len);
  int	fd = ::accept(m_fd, &sockaddr.base, &len);
  if (fd == -1)
    {
      perror("accept()");
      throw std::exception();
    }

  switch (sockaddr.base.sa_family)
    {
    case AF_INET:
      char	ipv4[INET_ADDRSTRLEN];
      if (inet_ntop(AF_INET, &sockaddr.ipv4.sin_addr, ipv4, sizeof(ipv4)) == NULL)
	perror("inet_ntop()");
      return (*new Socket(ipv4, fd));
    case AF_INET6:
      char	ipv6[INET6_ADDRSTRLEN];
      if (inet_ntop(AF_INET6, &sockaddr.ipv6.sin6_addr, ipv6, sizeof(ipv6)) == NULL)
	perror("inet_ntop()");
      return (*new Socket(ipv6, fd));
    }
  return (*new Socket("", fd));
}

std::string const	&Socket::get_ip(void) const
{
  return (m_ip);
}

bool	Socket::want_read(void) const
{
  FD_SET(m_fd, &m_readfds);
  m_nfds = std::max<int>(m_nfds, m_fd);
  return (false);
}

bool	 Socket::can_read(void) const
{
  bool	ret = FD_ISSET(m_fd, &m_readfds);
  FD_CLR(m_fd, &m_readfds);
  return (ret);
}

bool	Socket::want_write(void) const
{
  FD_SET(m_fd, &m_writefds);
  m_nfds = std::max<int>(m_nfds, m_fd);
  return (false);
}

bool	 Socket::can_write(void) const
{ 
  bool	ret = FD_ISSET(m_fd, &m_writefds);
  FD_CLR(m_fd, &m_writefds);
  return (ret);
}

uintmax_t	Socket::read(uint8_t &buffer, uintmax_t size) const
{
  ssize_t	ret = ::read(m_fd, &buffer, size);
  if (ret < 0)
    throw std::exception();
  return (ret);
}

uintmax_t	Socket::write(uint8_t const &buffer, uintmax_t size) const
{
  ssize_t	ret = ::write(m_fd, &buffer, size);
  if (ret < 0)
    throw std::exception();
  return (ret);
}

static int	aux_server(struct addrinfo const *rp)
{
  int	fd;

  if (rp == NULL)
    return (-1);
  if ((fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    {
      perror("socket()");
      return (aux_server(rp->ai_next));
    }
  if (bind(fd, rp->ai_addr, rp->ai_addrlen) != 0)
    {
      perror("bind()");
      if (close(fd) == -1)
	perror("close()");
      return (aux_server(rp->ai_next));
    }
  if (listen(fd, 42) != 0)
    {
      perror("listen()");
      if (close(fd) == -1)
	perror("close()");
      return (aux_server(rp->ai_next));
    }
  return (fd);
}

ISocket	&new_iserver(std::string const &host, std::string const &port)
{
  struct addrinfo	*result;
  struct addrinfo	hints =
    {
      AI_PASSIVE,
      AF_UNSPEC,
      SOCK_STREAM,
      IPPROTO_TCP,
      0,
      NULL,
      NULL,
      NULL
    };
  int	status = getaddrinfo(NULL, port.c_str(), &hints, &result);
  if (status != 0)
    {
      std::cerr << "getaddrinfo: " << gai_strerror(status) <<  std::endl;
      throw std::exception();
    }

  int fd = aux_server(result);
  freeaddrinfo(result);
  if (fd == -1)
    throw SocketException("Impossible de se connecter à ");
  return (*new Socket(host, fd));
}

static int	aux_client(struct addrinfo const *rp)
{
  int	fd;

  if (rp == NULL)
    return (-1);
  if ((fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    {
      perror("socket()");
      return (aux_client(rp->ai_next));
    }
  if (connect(fd, rp->ai_addr, rp->ai_addrlen) != 0)
    {
      perror("connect()");
      if (close(fd) == -1)
	perror("close()");
      return (aux_client(rp->ai_next));
    }
  return (fd);
}

ISocket	&new_iclient(std::string const &host, std::string const &port)
{
  struct addrinfo	*result;
  struct addrinfo	hints =
    {
      0,
      AF_UNSPEC,
      SOCK_STREAM,
      IPPROTO_TCP,
      0,
      NULL,
      NULL,
      NULL
    };
  int	status = getaddrinfo(host.c_str(), port.c_str(), &hints, &result);
  if (status != 0)
    {
      std::cerr << "getaddrinfo: " << gai_strerror(status) <<  std::endl;
      throw std::exception();
    }

  int fd = aux_client(result);
  freeaddrinfo(result);
  if (fd == -1)
    throw SocketException("lol");
  return (*new Socket(host, fd));
}

ISocket	&new_istandard(ISocket::Standard standard)
{
  switch (standard)
    {
    case ISocket::In:
      return (*new Socket("Standard Input (stdin)", 0));
    case ISocket::Out:
      return (*new Socket("Standard Output (stdout)", 1));
    case ISocket::Err:
      return (*new Socket("Standard Input (stdin)", 2));
    }
  throw std::exception();
}

bool	iselect(ITime const *time)
{
  return (Socket::select(time));
}

SocketException::SocketException(std::string const &what) :
  m_what(what)
{
}

char const	*SocketException::what(void) const throw()
{
  return (m_what.c_str());
}
