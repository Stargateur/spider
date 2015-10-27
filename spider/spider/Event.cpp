#include "Event.h"



Event::Event()
{
}

Event::Event(Event &old) : m_type(old.m_type), m_time(old.m_time)
{

}

Event::Event(eEventType type, long time) : m_type(type), m_time(time)
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

void			Event::setType(eEventType type)
{
	m_type = type;
}

void			Event::setTime(long time)
{
	m_time = time;
}