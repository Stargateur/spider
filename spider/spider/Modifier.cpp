#include "Modifier.h"



Modifier::Modifier()
{
}

Modifier::Modifier(Modifier const &old) : m_Ctrl(old.m_Ctrl), m_Alt(old.m_Alt), m_CapsLock(old.m_CapsLock), m_Shift(old.m_Shift)
{
}

Modifier::Modifier(bool Ctrl, bool Alt, bool CapsLock, bool Shift) : m_Ctrl(Ctrl), m_Alt(Alt), m_CapsLock(CapsLock), m_Shift(Shift)
{
}

Modifier::~Modifier()
{
}

bool		Modifier::getCtrl(void)
{
	return (m_Ctrl);
}

bool		Modifier::getAlt(void)
{
	return (m_Alt);
}

bool		Modifier::getShift(void)
{
	return (m_Shift);
}

bool		Modifier::getCapsLock(void)
{
	return (m_CapsLock);
}

void		Modifier::setCtrl(bool Ctrl)
{
	m_Ctrl = Ctrl;
}

void		Modifier::setAlt(bool Alt)
{
	m_Alt = Alt;
}

void		Modifier::setShift(bool Shift)
{
	m_Shift = Shift;
}

void		Modifier::setCapsLock(bool CapsLock)
{
	m_CapsLock = CapsLock;
}