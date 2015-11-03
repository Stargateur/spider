#pragma once
#include <string>

enum eEventType
{
	Pressed,
	Released
};

class Event
{
public:
	Event();
	Event(Event &old);
	Event(eEventType type, long time, std::string &winName);
	~Event();
	eEventType		getType(void);
	long			getTime(void);
	std::string		&getWinName(void);
	void			setType(eEventType type);
	void			setTime(long time);
	void			setWinName(std::string &winName);
protected:
	eEventType		m_type;
	long			m_time;
	std::string		m_winName;
};

