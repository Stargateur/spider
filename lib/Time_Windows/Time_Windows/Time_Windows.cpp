// Time_Windows.cpp : définit les fonctions exportées pour l'application DLL.
//

#include <ctime>
#include "Time_Windows.hpp"

TimeWindows::TimeWindows(void)
{
}

intmax_t	TimeWindows::get_second(void) const
{
	return (m_second);
}

bool	TimeWindows::set_second(intmax_t second)
{
	m_second = second;
	return (false);
}

intmax_t	TimeWindows::get_nano(void) const
{
	return (m_mili * 1000000);
}

bool	TimeWindows::set_nano(intmax_t nano)
{
	m_mili = nano / 1000000;
	return (false);
}

bool	TimeWindows::now(void)
{
	SYSTEMTIME SystemTime;
	m_second = time(NULL);
	GetSystemTime(&SystemTime);
	m_mili = SystemTime.wMilliseconds;
	return (false);
}

ITime	&TimeWindows::clone(void) const
{
	return (*new TimeWindows());
}

TimeWindows::~TimeWindows(void)
{
}

extern "C" __declspec(dllexport)
ITime	&new_itime(void)
{
	return (*new TimeWindows());
}