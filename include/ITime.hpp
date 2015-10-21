//
// ITime.hh for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:44:16 2015 Bertrand-Rapello Baptiste
// Last update Wed Oct 21 20:46:43 2015 Bertrand-Rapello Baptiste
//

#ifndef ITIME_HPP_
# define ITIME_HPP_

#include <cstdint>

class ITime
{
public:
	virtual intmax_t get_second() const = 0;
	virtual intmax_t get_nano() const = 0;
	virtual bool now() = 0;
	virtual ~ITime();
};
  

#endif 
