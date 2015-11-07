#include "Event.h"

Event::Event()
{
}

Event::Event(Event const &old) : m_type(old.m_type), m_second(old.m_second), m_nano(old.m_nano), m_winName(old.m_winName)
{

}

Event::Event(eEventType type, intmax_t second, intmax_t nano, std::string const &winName) :
	m_type(type),
	m_second(second),
	m_nano(nano),
	m_winName(winName)
{

}

Event::~Event()
{
}

char const	*Event::getEvent(void) const
{
	switch (m_type)
	{
	case Pressed:
		return ("Pressed");
	case Released:
		return ("Released");
	case Click:
		return ("Click");
	case Move:
		return ("Move");
	case Scroll:
		return ("Scroll");
	}
	return ("");
}

eEventType		Event::getType(void) const
{
	return (m_type);
}

intmax_t		Event::getSecond(void) const
{
	return (m_second);
}

intmax_t		Event::getNano(void) const
{
	return (m_nano);
}

std::string		&Event::getWinName(void)
{
	return (m_winName);
}

void			Event::setType(eEventType type)
{
	m_type = type;
}

void			Event::setWinName(std::string const &winName)
{
	m_winName = winName;
}

std::string		Event::toString(void)
{
	std::stringstream ret;

	if (m_type == Pressed)
		ret << "Pressed ";
	else if (m_type == Released)
		ret << "Released ";
	ret << "s : " << m_second << " n : " << m_nano << " " << m_winName;
	return (ret.str());
}

eInput			Event::getInput(void)
{
	return (None);
}