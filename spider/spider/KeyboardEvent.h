#pragma once
#include "Event.h"
#include "Key.h"
#include "Modifier.h"

class KeyboardEvent :	public Event
{
public:
	KeyboardEvent();
	KeyboardEvent(KeyboardEvent &old);
	KeyboardEvent(Key keyData, Modifier mod, eEventType type, long time, std::string &winName);
	~KeyboardEvent();
	Key					getKeyData(void);
	Modifier			getModifier(void);
	void				setKeyData(Key keyData);
	void				setMod(Modifier mod);
	virtual std::string toString(void);
	virtual eInput		getInput(void);
private:
	Key					m_keyData;
	Modifier			m_mod;
};