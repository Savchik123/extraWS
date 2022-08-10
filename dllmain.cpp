#include "pch.h"
#include <process.h>
#include <string>
bool state = true;
void ews(PVOID)
{
	while (true)
	{
		if (GetAsyncKeyState(VK_F2))
		{
			while (GetAsyncKeyState(VK_F2))

			{
				Sleep(1);
			}
			state = !state;
		}
		if (state)
		{
			*(char*)(0x5109AC) = 235;
			*(char*)(0x5109C5) = 235;
			*(char*)(0x5231A6) = 235;
			*(char*)(0x52322D) = 235;
			*(char*)(0x5233BA) = 235;
		}
		else
		{
			*(char*)(0x5109AC) = 122;
			*(char*)(0x5109C5) = 122;
			*(char*)(0x5231A6) = 117;
			*(char*)(0x52322D) = 117;
			*(char*)(0x5233BA) = 117;
		}
	}
}




BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		_beginthread(ews, NULL, NULL);
	}
	return TRUE;
}
