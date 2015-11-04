#pragma once
#include <string>

std::string gVirtualKeyCode[] = {
	"",
	"Left mouse button",						// VK_LBUTTON	0x01
	"Right mouse button",						// VK_RBUTTON	0x02
	"Control-break processing",					// VK_CANCEL	0x03
	"Middle mouse button",						// VK_MBUTTON	0x04
	"X1 mouse button",							// VK_XBUTTON1	0x05
	"X2 mouse button",							// VK_XBUTTON2	0x06
	"Undefined",								// -			0x07
	"BACKSPACE",								// VK_BACK		0x08
	"TAB",										// VK_TAB		0x09
	"Reserved",									// -			0x0A
	"Reserved",									// -			0x0B
	"CLEAR",									// VK_CLEAR		0x0C
	"ENTER",									// VK_RETURN	0x0D
	"Undefined",								// -			0x0E
	"Undefined",								// -			0x0F
	"SHIFT",									// VK_SHIFT		0x10
	"CTRL",										// VK_CONTROL	0x11
	"ALT",										// VK_MENU		0x12
	"PAUSE",									// VK_PAUSE		0x13
	"CAPS LOCK",								// VK_CAPITAL	0x14
	"IME Kana mode",							// VK_KANA		0x15
	"Undefined",								// -			0x16
	"IME Junja mode",							// VK_JUNJA		0x17
	"IME final mode",							// VK_FINAL		0x18
	"IME Hanja mode",							// VK_HANJA		0x19
	"Undefined",								// -			0x1A
	"ESC",										// VK_ESCAPE	0x1B
	"IME convert",								// VK_CONVERT	0x1C
	"IME nonconvert",							// VK_NONCONVERT0x1D
	"IME accept",								// VK_ACCEPT	0x1E
	"IME mode change request",					// VK_MODECHANGE0x1F
	"SPACEBAR",									// VK_SPACE		0x20
	"PAGE UP",									// VK_PRIOR		0x21
	"PAGE DOWN",								// VK_NEXT		0x22
	"END",										// VK_END		0x23
	"HOME",										// VK_HOME		0x24
	"LEFT ARROW",								// VK_LEFT		0x25
	"UP ARROW",									// VK_UP		0x26
	"RIGTH ARROW",								// VK_RIGTH		0x27
	"DOWN ARROW",								// VK_DOWN		0x28
	"SELECT",									// VK_SELECT	0x29
	"PRINT",									// VK_PRINT		0x2A
	"EXECUTE",									// VK_EXECUTE	0x2B
	"PRINT SCREEN",								// VK_SNAPSHOT	0x2C
	"INS",										// VK_INSERT	0x2D
	"DEL",										// VK_DELETE	0x2E
	"HELP",										// VK_HELP		0x2F
	"0",										//				0x30
	"1",										//				0x31
	"2",										//				0x32
	"3",										//				0x33
	"4",										//				0x34
	"5",										//				0x35
	"6",										//				0x36
	"7",										//				0x37
	"8",										//				0x38
	"9",										//				0x39
	"Undefined",								// -			0x3A
	"Undefined",								// -			0x3B
	"Undefined",								// -			0x3C
	"Undefined",								// -			0x3D
	"Undefined",								// -			0x3E
	"Undefined",								// -			0x3F
	"Undefined",								// -			0x40
	"A",										//				0x41
	"B",										//				0x42
	"C",										//				0x43
	"D",										//				0x44
	"E",										//				0x45
	"F",										//				0x46
	"G",										//				0x47
	"H",										//				0x48
	"I",										//				0x49
	"J",										//				0x4A
	"K",										//				0x4B
	"L",										//				0x4C
	"M",										//				0x4D
	"N",										//				0x4E
	"O",										//				0x4F
	"P",										//				0x50
	"Q",										//				0x51
	"R",										//				0x52
	"S",										//				0x53
	"T",										//				0x54
	"U",										//				0x55
	"V",										//				0x56
	"W",										//				0x57
	"X",										//				0x58
	"Y",										//				0x59
	"Z",										//				0x5A
	"Left Windows",								// VK_LWIN		0x5B
	"Right Windows",							// VK_RWIN		0x5C
	"Applications",								// VK_APPS		0x5D
	"Reserved",									// -			0x5E
	"Computer Sleep",							// VK_SLEEP		0x5F
	"Numeric keypad 0",							// VK_NUMPAD0	0x60
	"Numeric keypad 1",							// VK_NUMPAD1	0x61
	"Numeric keypad 2",							// VK_NUMPAD2	0x62
	"Numeric keypad 3",							// VK_NUMPAD3	0x63
	"Numeric keypad 4",							// VK_NUMPAD4	0x64
	"Numeric keypad 5",							// VK_NUMPAD5	0x65
	"Numeric keypad 6",							// VK_NUMPAD6	0x66
	"Unassigned",								// -			0x8A
	"Unassigned",								// -			0x8B
	"Unassigned",								// -			0x8C
	"Unassigned",								// -			0x8D
	"Unassigned",								// -			0x8E
	"Unassigned",								// -			0x8F
	"NUM LOCK",									// VK_NUMLOCK	0x90
	"SCROLL LOCK",								// VK_SCROLL	0x91
	"OEM specific",								//				0x92
	"OEM specific",								//				0x93
	"OEM specific",								//				0x94
	"OEM specific",								//				0x95
	"OEM specific",								//				0x96
	"Unassigned",								//				0x97
	"Unassigned",								//				0x98
	"Unassigned",								//				0x99
	"Unassigned",								//				0x9A
	"Unassigned",								//				0x9B
	"Unassigned",								//				0x9C
	"Unassigned",								//				0x9D
	"Unassigned",								//				0x9E
	"Unassigned",								//				0x9F
	"Left SHIFT",								// VK_LSHIFT	0xA0
	"Right SHIFT",								// VK_RSHIFT	0xA1
	"Left CONTROL",								// VK_LCONTROL	0xA2
	"Right CONTROL",							// VK_RCONTROL	0xA3
	"Left MENU",								// VK_LMENU		0xA4
	"Right MENU",								// VK_RMENU		0xA5
	"Browser Back",								// VK_BROWSER_BACK	0xA6
	"Browser Forward",							// VK_BROWSER_FORWARD	0xA7
	"Browser Refresh",							// VK_BROWSER_REFRESH	0xA8
	"Browser Stop",								// VK_BROWSER_STOP	0xA9
	"Browser Search",							// VK_BROWSER_SEARCH	0xAA
	"Browser Favorites",						// VK_BROWSER_FAVORITES	0xAB
	"Browser Start and Home",					// VK_BROWSER_HOME	0xAC
	"Volume Mute",								// VK_VOLUME_MUTE	0xAD
	"Volume Down",								// VK_VOLUME_DOWN	0xAE
	"Volume Up",								// VK_VOLUME_UP		0xAF
	"Next Track",								// VK_MEDIA_NEXT_TRACK	0xB0
	"Previous Track",							// VK_MEDIA_PREV_TRACK	0xB1
	"Stop Media",								// VK_MEDIA_STOP	0xB2
	"Play/Pause Media",							// VK_MEDIA_PLAY_PAUSE	0xB3
	"Start Mail",								// VK_LAUNCH_MAIL	0xB4
	"Select Media",								// VK_LAUNCH_MEDIA_SELECT	0x85
	"Start Application 1",						// VK_LAUNCH_APP1	0xB6
	"Start Application 2",						// VK_LAUNCH_APP2	0xB7
	"Reserved",									// -			0xB8
	"Reserved",									// -			0xB9
	"Miscellaneous characters ;:",				// VK_OEM_1		0xBA
	"+",										// VK_OEM_PLUS	0xBB
	",",										// VK_OEM_COMMA	0xBC
	"-",										// VK_OEM_MINUS	0xBD
	".",										// VK_OEM_PERIOD	0xBE
	"Miscellaneous characters /?",				// VK_OEM_2		0xBF
	"Miscellaneous characters `~",				// VK_OEM_3		0xC0
	"Reserved",									// -			0xC1
	"Reserved",									// -			0xC2
	"Reserved",									// -			0xC3
	"Reserved",									// -			0xC4
	"Reserved",									// -			0xC5
	"Reserved",									// -			0xC6
	"Reserved",									// -			0xC7
	"Reserved",									// -			0xC8
	"Reserved",									// -			0xC9
	"Reserved",									// -			0xCA
	"Reserved",									// -			0xCB
	"Reserved",									// -			0xCC
	"Reserved",									// -			0xCD
	"Reserved",									// -			0xCE
	"Reserved",									// -			0xCF
	"Reserved",									// -			0xD0
	"Reserved",									// -			0xD1
	"Reserved",									// -			0xD2
	"Reserved",									// -			0xD3
	"Reserved",									// -			0xD4
	"Reserved",									// -			0xD5
	"Reserved",									// -			0xD6
	"Reserved",									// -			0xD7
	"Unassigned",								// -			0xD8
	"Unassigned",								// -			0xD9
	"Unassigned",								// -			0xDA
	"Miscellaneous characters [{",				// VK_OEM_4		0xDB
	"Miscellaneous characters \|",				// VK_OEM_5		0xDC
	"Miscellaneous characters ]}",				// VK_OEM_6		0xDD
	"Miscellaneous characters '\"",				// VK_OEM_7		0xDE
	"Miscellaneous characters",					// VK_OEM_8		0xDF
	"Reserved",									// -			0xE0
	"OEM specific",								//				0xE1
	"angle bracket or backslash",				// VK_OEM_102	0xE2
	"OEM specific",								//				0xE3
	"OEM specific",								//				0xE4
	"IEM PROCESS",								// VK_PROCESSKEY0xE5
	"OEM specific",								//				0xE6
	"Packet",									// VK_PACKET	0xE7
	"Unassigned",								// -			0xE8
	"OEM specific",								//				0xE9
	"OEM specific",								//				0xEA
	"OEM specific",								//				0xEB
	"OEM specific",								//				0xEC
	"OEM specific",								//				0xED
	"OEM specific",								//				0xEE
	"OEM specific",								//				0xEF
	"OEM specific",								//				0xF1
	"OEM specific",								//				0xF2
	"OEM specific",								//				0xF3
	"OEM specific",								//				0xF4
	"OEM specific",								//				0xF5
	"Attn",										// VK_ATTN		0xF6
	"CrSel",									// VK_CRSEL		0xF7
	"ExSel",									// VK_EXSEL		0xF8
	"Erase EOF",								// VK_EREOF		0xF9
	"Play",										// VK_PLAY		0xFA
	"Zoom",										// VK_ZOOM		0xFB
	"Reserved",									// VK_NONAME	0xFC
	"PA1",										// VK_PA1		0xFD
	"Clear"										// VK_OEM_CLEAR	0xFE
};