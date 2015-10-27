#include <windows.h>
#include <iostream>

HHOOK kbHook; 
bool shift = false;

LRESULT CALLBACK KeyboardProc(_In_ int code, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	bool ctrl = false;
	KBDLLHOOKSTRUCT		*a;

	a = (KBDLLHOOKSTRUCT*)lParam;
	std::cout << a->vkCode << std::endl;
	if (code == HC_ACTION)
	{
		if (a->vkCode == VK_LSHIFT || a->vkCode == VK_RSHIFT)
			shift = true;
		else
			shift = false;
	}
	ctrl = GetAsyncKeyState(VK_CONTROL) >> ((sizeof(SHORT) * 8) - 1);
	if (a->vkCode == VK_F12 && ctrl)
	{
		UnhookWindowsHookEx(kbHook);
	}
	//
	// Créer un instance de KeyboardEvent ici !
	//

	//
	// Récupérer la fenêtre active :
	// HWND GetForegroundWindow()
	//
	// Nom de la fenêtre active : 
	// GetWindowTextA(HWND window, char *name, sizeof(name))
	// Windows limite le nom des fenêtres à 255 caractères donc "char name[256]"
	//
	return (CallNextHookEx(NULL, code, wParam, lParam));
}

int main(int ac, char **av)
{
	bool end = true;
	kbHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
	MSG message;

	while(GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return (0);
}