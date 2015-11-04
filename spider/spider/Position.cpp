#include "Position.h"



Position::Position()
{
}

Position::Position(int x, int y) : m_x(x), m_y(y)
{
}

Position::~Position()
{
}

int			Position::getX(void)
{
	return (m_x);
}

int			Position::getY(void)
{
	return (m_y);
}

void		Position::setX(int x)
{
	m_x = x;
}

void		Position::setY(int y)
{
	m_y = y;
}