//
// ITime.hh for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:44:16 2015 Bertrand-Rapello Baptiste
// Last update Wed Oct 21 22:20:15 2015 Antoine Plaskowski
//

#ifndef ITIME_HPP_
# define ITIME_HPP_

#include <cstdint>

class ITime
{
public:
	virtual intmax_t get_second(void) const = 0;
	virtual intmax_t get_nano(void) const = 0;
	virtual bool now(void) = 0;
	virtual ~ITime(void);
};
  

#endif 