#include <iostream>
#include <string>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "LagSwitch.h"

static void Toggle(LagSwitch& lagswitch)
{
	bool running = true;
	while (running)
	{
		if (GetAsyncKeyState(VK_HOME)) // 0x24 is the home key
		{
			switch (lagswitch.GetState())
			{
			case off: // turn the lag switch on
				lagswitch.On();
				break;

			case on:  // turn the lag switch off
				lagswitch.Off();
				break;

			default:  // anything else (edge case)
				std::cerr << (int)lagswitch.GetState() << std::endl;
				running = false;
			}
		}

		if (GetAsyncKeyState(VK_END))
		{
			running = false;
		}

		Sleep(100);
	}
}

int main(int argc, const char* argv[])
{
	std::cout << "PUBG Lagswitch" << std::endl;
	std::cout << "by Chronix" << std::endl;
	std::cout << "https://www.github.com/akachronix" << std::endl;
	std::cout << std::endl;
	std::cout << "Press HOME to toggle." << std::endl;
	std::cout << "Press END to exit." << std::endl;
	std::cout << std::endl;

	PUBG_LagSwitch lagger;
	Toggle(lagger);

	return 0;
}