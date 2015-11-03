#include "MouseEvent.h"



MouseEvent::MouseEvent()
{
}

MouseEvent::MouseEvent(MouseEvent &old) : Event(old), m_buttonData(old.m_buttonData), m_pos(old.m_pos)
{
}

MouseEvent::MouseEvent(Button buttonData, Position pos, eEventType type, long time) : Event(type, time), m_buttonData(buttonData), m_pos(pos)
{
}

MouseEvent::~MouseEvent()
{
}

Button		MouseEvent::getButtonData(void)
{
	return (m_buttonData);
}

Position	MouseEvent::getPos(void)
{
	return (m_pos);
}

void		MouseEvent::setButtonData(Button buttonData)
{
	m_buttonData = buttonData;
}

void		MouseEvent::setPos(Position pos)
{
	m_pos = pos;
}