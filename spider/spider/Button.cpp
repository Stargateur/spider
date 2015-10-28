#include "Button.h"


Button::Button()
{
}

Button::Button(std::string &name, int id) : m_name(name), m_id(id)
{
}

Button::~Button()
{
}

std::string		Button::getName(void)
{
	return (m_name);
}

int				Button::getId(void)
{
	return (m_id);
}

void			Button::setName(std::string &name)
{
	m_name = name;
}

void			Button::setId(int id)
{
	m_id = id;
}