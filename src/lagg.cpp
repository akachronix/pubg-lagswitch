#include <iostream>
#include <string>
#include <memory>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "lag_switch.hpp"
#include "liblog.hpp"

// global variable for while loop
bool running = true;

int main(int argc, const char* argv[])
{
	/* create a logger object (made by me ;p) to make
	   formatting easier and to have output to a file */
	#ifdef _LOGGER_DEBUG
	auto console = std::make_unique<logger>(loglevel_t::everything, "lagg.log");
	#else
	auto console = std::make_unique<logger>(loglevel_t::warnings, "lagg.log");
	#endif
	
	lagswitch lagger;

	// run loop to detect keystrokes
	console->log("Starting to poll for home toggle.");
	while(running)
	{
		// check if home key is being pressed
		console->log("Polling home key.");
		if(GetAsyncKeyState(0x24)) // 0x24 is the home key
		{
			console->log("Home key is pressed.");

			/* depending on whether its on or off we keep track of it and
			   check it here and run the appropriate batch script for it */
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
				console->log_error("lag_switch was not an expected value.");
				std::cerr << (int)lagger.get_state() << std::endl;
				running = false;
			}
		}

		// when end key is pressed we cleanly exit
 		console->log("Polling end key.");
		if(GetAsyncKeyState(0x23)) // 0x23 is the end key
		{
			console->log("End key has been pressed.. exiting.");
			running = false;
		}

		// home & end keys are either not held down or we have a weird edge case
		else
		{
			console->log("Home and end key has not pressed.. do nothing.");
		}

		// sleep so we're not taking 100% cpu
		Sleep(100);
	}

	// wait for enter keypress to exit
	// std::cin.get();

	return 0;
}
