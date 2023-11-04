#include "Display.h"
#include <iostream>

void Display::update()
{
	system("cls");
	std::cout << "Welcome to alythesniper's assault cube"
		<< "\n            trainer!"
		<< "\n\n\nHacks:                      Status:"
		<< "\nTriggerbot            --->        [" << bTriggerBot << "]"
		<< "\nNo Recoil             --->        [" << bNoRecoil << "]";

}
