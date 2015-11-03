#include "KeyboardEvent.h"


KeyboardEvent::KeyboardEvent()
{
}

KeyboardEvent::KeyboardEvent(KeyboardEvent &old) : Event(old), m_keyData(old.m_keyData), m_mod(old.m_mod)
{

}

KeyboardEvent::KeyboardEvent(Key keyData, Modifier mod, eEventType type, long time) : Event(type, time), m_keyData(keyData), m_mod(mod)
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