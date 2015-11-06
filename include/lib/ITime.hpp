//
// ITime.hh for  in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:44:16 2015 Bertrand-Rapello Baptiste
// Last update Fri Nov  6 09:34:44 2015 Antoine Plaskowski
//

#ifndef ITIME_HPP_
# define ITIME_HPP_

#include <cstdint>

class	ITime
{
public:
  virtual intmax_t	get_second(void) const = 0;
  virtual bool	set_second(intmax_t) = 0;
  virtual intmax_t	get_nano(void) const = 0;
  virtual bool	set_nano(intmax_t) = 0;
  virtual bool	now(void) = 0;
  virtual ITime	&clone(void) const = 0;
  virtual	~ITime(void);
};

class	ITimeException
{
public:
  virtual char const *what(void) const noexcept = 0;
  virtual ~ITimeException(void);
};

extern "C"
{
# define	NAME_FCT_NEW_ITIME	"new_itime"
#ifdef __linux__
  ITime	&new_itime(void);
#else
  __declspec(dllexport) ITime	&new_itime(void);
#endif
  typedef	ITime &(*fct_new_itime)(void);
  typedef	ITime &(&ref_new_itime)(void);
}

#endif 
