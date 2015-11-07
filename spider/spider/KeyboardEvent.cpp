#include "KeyboardEvent.h"


KeyboardEvent::KeyboardEvent()
{
}

KeyboardEvent::KeyboardEvent(KeyboardEvent const &old) : Event(old), m_keyData(old.m_keyData), m_mod(old.m_mod)
{

}

KeyboardEvent::KeyboardEvent(Key const &keyData, Modifier const &mod, eEventType type, intmax_t second, intmax_t nano, std::string const &winName) : Event(type, second, nano, winName), m_keyData(keyData), m_mod(mod)
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

void		KeyboardEvent::setKeyData(Key const &keyData)
{
	m_keyData = keyData;
}

void		KeyboardEvent::setMod(Modifier const &mod)
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
	if (m_mod.getCapsLock())
		ret << "CapsLock ";
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