#pragma once
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
	Event(eEventType type, long time);
	~Event();
	eEventType		getType(void);
	long			getTime(void);
	void			setType(eEventType type);
	void			setTime(long time);
protected:
	eEventType		m_type;
	long			m_time;
};

