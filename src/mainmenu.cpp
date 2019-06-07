#include "include/menus/mainmenu.h"
#include "include/menus/adbmenu.h"
#include <iostream>
#include <chrono>
#include <string>
#include <thread>
MainMenu::MainMenu()
{
	this->elements = { "Adb options","Fastboot options" };
}
void MainMenu::startScreen()
{
	std::string s = "Welcome to Phone tools v1";
	for (const auto& x : s)
	{
		std::cout << x;
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	std::cout << '\n';
	for (const auto& x : s)
	{
		std::cout << '/';
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	std::cout << '\n';

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