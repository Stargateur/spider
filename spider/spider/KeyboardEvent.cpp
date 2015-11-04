#include "KeyboardEvent.h"


KeyboardEvent::KeyboardEvent()
{
}

KeyboardEvent::KeyboardEvent(KeyboardEvent &old) : Event(old), m_keyData(old.m_keyData), m_mod(old.m_mod)
{

}

KeyboardEvent::KeyboardEvent(Key keyData, Modifier mod, eEventType type, long time, std::string &winName) : Event(type, time, winName), m_keyData(keyData), m_mod(mod)
{

}

KeyboardEvent::~KeyboardEvent()
{
}

Key			KeyboardEvent::getKeyData(void)
{
	return (m_keyData);
}

Modifier	KeyboardEvent::getModifier(void)
{
	return (m_mod);
}

void		KeyboardEvent::setKeyData(Key keyData)
{
	m_keyData = keyData;
}

void		KeyboardEvent::setMod(Modifier mod)
{
	m_mod = mod;
}

std::string KeyboardEvent::toString(void)
{
	std::stringstream ret;

	ret << m_keyData.getId() << " ";
	ret << m_keyData.getName() << " ";
	if (m_mod.getAlt())
		ret << "Alt ";
	if (m_mod.getAltGr())
		ret << "AltGr ";
	if (m_mod.getCtrl())
		ret << "Ctrl ";
	if (m_mod.getShift())
		ret << "Shift ";
	ret << Event::toString() << std::endl;
	return (ret.str());
}

eInput		KeyboardEvent::getInput(void)
{
	return (Keyboard);
}