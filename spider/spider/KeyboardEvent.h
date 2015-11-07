#pragma once
#include "Event.h"
#include "Key.h"
#include "Modifier.h"

class KeyboardEvent :	public Event
{
public:
	KeyboardEvent();
	KeyboardEvent(KeyboardEvent const &old);
	KeyboardEvent(Key const &keyData, Modifier const &mod, eEventType type, intmax_t second, intmax_t nano, std::string const &winName);
	~KeyboardEvent();
	Key					getKeyData(void);
	Modifier			getModifier(void);
	void				setKeyData(Key const &keyData);
	void				setMod(Modifier const &mod);
	virtual std::string toString(void);
	virtual eInput		getInput(void);
private:
	Key					m_keyData;
	Modifier			m_mod;
};