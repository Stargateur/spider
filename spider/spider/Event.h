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
	Event(eEventType type, long time, std::string const &winName);
	~Event();
	eEventType			getType(void);
	long				getTime(void);
	std::string			&getWinName(void);
	void				setType(eEventType type);
	void				setTime(long time);
	void				setWinName(std::string const &winName);
	virtual std::string toString(void);
	virtual eInput		getInput(void);
protected:
	eEventType			m_type;
	long				m_time;
	std::string			m_winName;
};