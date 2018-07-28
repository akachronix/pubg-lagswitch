#include <iostream>
#include <string>
#include <memory>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "lag_switch.hpp"

// global variable for while loop
bool running = true;

int main(int argc, const char* argv[])
{	
	#ifdef _FORTNITE
		fortnitelagswitch lagger;
	#endif

	#ifdef _PUBG
		pubglagswitch lagger;
	#endif

	// gotta nest preprocessor statements ya know
	#ifndef _FORTNITE
		#ifndef _PUBG
			#error You must declare _FORTNITE or _PUBG to build.
		#endif
	#endif

	while(running)
	{
		if(GetAsyncKeyState(0x24)) // 0x24 is the home key
		{
			switch(lagger.get_state())
			{
			case lag::off: // turn the lag switch on
				std::cout << "Turning lagswitch on." << std::endl;
				lagger.on();
				std::cout << "Done." << std::endl;
				break;

			case lag::on:  // turn the lag switch off
				std::cout << "Turning lagswitch off." << std::endl;
				lagger.off();
				std::cout << "Done." << std::endl;
				break;
			
			default:       // anything else (edge case)
				std::cerr << (int)lagger.get_state() << std::endl;
				running = false;
			}
		}

		if(GetAsyncKeyState(0x23)) // 0x23 is the end key
		{
			running = false;
		}

		Sleep(100);
	}

	return 0;
}
