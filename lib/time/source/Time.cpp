//
// Time.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 21:04:15 2015 Bertrand-Rapello Baptiste
// Last update Thu Oct 22 02:48:09 2015 Antoine Plaskowski
//

#include	"Time.hpp"

Time::Time(void) :
  m_timespec({0, 0})
{
}

Time::~Time(void)
{
}

intmax_t	Time::get_second(void) const
{
  return (static_cast<intmax_t>(m_timespec.tv_sec));
}

intmax_t	Time::get_nano(void) const
{
  return (static_cast<intmax_t>(m_timespec.tv_nsec));
}

bool	Time::now(void)
{
  if (clock_gettime(CLOCK_REALTIME, &m_timespec) == -1)
    return true;
  return false;
}

ITime	*new_itime(void)
{
  return (new Time());
}
