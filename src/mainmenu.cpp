#include "include/menus/mainmenu.h"
#include "include/menus/adbmenu.h"
#include <iostream>
MainMenu::MainMenu()
{
	this->elements = { "Adb options","Fastboot options" };
}
void MainMenu::startScreen()
{
	std::cout << "///Welcome to Phone tools v1///\n";
}
void MainMenu::Commands(int x)
{
	AdbMenu M;
	switch (x) 
	{
	case 1:
		if (!M.show())
			return;
		break;
	case 2:
		break;
	}
}