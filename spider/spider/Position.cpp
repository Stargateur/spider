#include "Position.h"



Position::Position()
{
}

Position::Position(int x, int y, int z) : m_x(x), m_y(y), m_z(z)
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

int			Position::getZ(void)
{
	return (m_z);
}

void		Position::setX(int x)
{
	m_x = x;
}

void		Position::setY(int y)
{
	m_y = y;
}

void		Position::setZ(int z)
{
	m_z = z;
}