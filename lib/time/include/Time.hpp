//
// Time.hh for $ in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:57:19 2015 Bertrand-Rapello Baptiste
// Last update Thu Oct 22 01:04:05 2015 Antoine Plaskowski
//

#ifndef TIME_HPP_
# define TIME_HPP_

#include <ctime>
#include <cstdint>
#include "ITime.hpp"

class Time : public ITime
{
public:
  Time(void);
  ~Time(void);
public:
  intmax_t	get_second(void) const;
  intmax_t	get_nano(void) const;
  bool	now(void);
private:
  struct timespec	m_timespec;  
};

#endif