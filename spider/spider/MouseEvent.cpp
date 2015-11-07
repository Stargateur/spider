#include "MouseEvent.h"

MouseEvent::MouseEvent()
{
}

MouseEvent::MouseEvent(MouseEvent &old) : Event(old), m_buttonData(old.m_buttonData), m_pos(old.m_pos)
{
}

MouseEvent::MouseEvent(Button buttonData, Position pos, eEventType type, intmax_t second, intmax_t nano, std::string &winName) : Event(type, second, nano, winName), m_buttonData(buttonData), m_pos(pos)
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

std::string	MouseEvent::toString(void)
{
	std::stringstream ret;

	ret << m_buttonData.getId() << " ";
	ret << m_buttonData.getName() << " ";
	ret << m_pos.getX() << " ";
	ret << m_pos.getY() << " ";
	ret << Event::toString() << std::endl;
	return (ret.str());
}

eInput		MouseEvent::getInput(void)
{
	return (Mouse);
}