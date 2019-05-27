#include "include/menus/mainmenu.h"
#include "include/menus/adbmenu.h"
MainMenu::MainMenu()
{
	this->elements = { "Adb options","Fastboot options" };
}
void MainMenu::Commands(int x)
{
	AdbMenu AdbOptions;
	switch (x) 
	{
	case 1:
		printMenu(AdbOptions);
		break;
	case 2:
		break;
	}
}