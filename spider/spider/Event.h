#pragma once
#include <string>
#include <sstream>

enum eEventType
{
	Pressed,
	Released,
	Click,
	Move,
	Scroll
};

enum eInput
{
	None,
	Keyboard,
	Mouse
};

class Event
{
public:
	Event();
	Event(Event const &old);
	Event(eEventType type, intmax_t second, intmax_t nano, std::string const &winName);
	~Event();
	char const			*getEvent(void) const;
	eEventType			getType(void) const;
	intmax_t			getSecond(void) const;
	intmax_t			getNano(void) const;
	std::string			&getWinName(void);
	void				setType(eEventType type);
	void				setWinName(std::string const &winName);
	virtual std::string toString(void);
	virtual eInput		getInput(void);
protected:
	eEventType			m_type;
	intmax_t			m_second;
	intmax_t			m_nano;
	std::string			m_winName;
};