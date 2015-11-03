#include "Event.h"



Event::Event()
{
}

Event::Event(Event &old) : m_type(old.m_type), m_time(old.m_time), m_winName(old.m_winName)
{

}

Event::Event(eEventType type, long time, std::string &winName) : m_type(type), m_time(time), m_winName(winName)
{

}

Event::~Event()
{
}

eEventType		Event::getType(void)
{
	return (m_type);
}

long			Event::getTime(void)
{
	return (m_time);
}

std::string		&Event::getWinName(void)
{
	return (m_winName);
}

void			Event::setType(eEventType type)
{
	m_type = type;
}

void			Event::setTime(long time)
{
	m_time = time;
}

void			Event::setWinName(std::string &winName)
{
	m_winName = winName;
}