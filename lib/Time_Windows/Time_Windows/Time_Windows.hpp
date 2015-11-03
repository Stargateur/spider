#pragma once

#include <windows.h>
#include "ITime.hpp"

class	TimeWindows : public ITime
{
public:
	TimeWindows(void);
	intmax_t	get_second(void) const;
	bool	set_second(intmax_t);
	intmax_t	get_nano(void) const;
	bool	set_nano(intmax_t);
	bool	now(void);
	ITime	&clone(void) const;
	~TimeWindows(void);
private:
	time_t m_second;
	WORD m_mili;
};
