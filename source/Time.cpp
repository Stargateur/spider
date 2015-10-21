//
// Time.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 21:04:15 2015 Bertrand-Rapello Baptiste
// Last update Wed Oct 21 21:16:09 2015 Bertrand-Rapello Baptiste
//

#include <iostream>
#include "Time.hpp"

Time::Time()
{
	this->now();
}

Time::~Time()
{

}

intmax_t Time::get_second() const
{
	return (intmax_t)m_strctTime.tv_sec;
}

intmax_t Time::get_nano() const
{
	return (intmax_t)m_strctTime.tv_nsec;
}

bool Time::now()
{
	if (clock_gettime(CLOCK_REALTIME, &m_strctTime) == -1)
		return true;
	return false;
}
