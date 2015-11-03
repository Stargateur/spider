#pragma once
#include "Event.h"
#include "Button.h"
#include "Position.h"

class MouseEvent : public Event
{
public:
	MouseEvent();
	MouseEvent(MouseEvent &old);
	MouseEvent(Button buttonData, Position pos, eEventType type, long time);
	~MouseEvent();
	Button		getButtonData(void);
	Position	getPos(void);
	void		setButtonData(Button buttonData);
	void		setPos(Position pos);
private:
	Button		m_buttonData;
	Position	m_pos;
};

