#include "Modifier.h"



Modifier::Modifier()
{
}

Modifier::Modifier(Modifier &old) : m_Ctrl(old.m_Ctrl), m_Alt(old.m_Alt), m_AltGr(old.m_AltGr), m_Shift(old.m_Shift)
{
}

Modifier::Modifier(bool Ctrl, bool Alt, bool AltGr, bool Shift) : m_Ctrl(Ctrl), m_Alt(Alt), m_AltGr(AltGr), m_Shift(Shift)
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

bool		Modifier::getAltGr(void)
{
	return (m_AltGr);
}

bool		Modifier::getShift(void)
{
	return (m_Shift);
}

void		Modifier::setCtrl(bool Ctrl)
{
	m_Ctrl = Ctrl;
}

void		Modifier::setAlt(bool Alt)
{
	m_Alt = Alt;
}

void		Modifier::setAltGr(bool AltGr)
{
	m_AltGr = AltGr;
}

void		Modifier::setShift(bool Shift)
{
	m_Shift = Shift;
}