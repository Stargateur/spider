//
// Time.hh for $ in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:57:19 2015 Bertrand-Rapello Baptiste
// Last update Wed Oct 21 21:00:09 2015 Bertrand-Rapello Baptiste
//

#ifndef TIME_HPP_
# define TIME_HPP_

#include <ctime>
#include <cstdint>
#include "ITime.hpp"

class Time : public ITime
{
public:
  Time();
  ~Time();

private:
	struct timespec m_strctTime;

public:
  intmax_t get_second() const;
  intmax_t get_nano() const;
  bool now();
  
};

#endif
