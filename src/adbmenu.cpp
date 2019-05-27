#include "include/menus/adbmenu.h"
#include"include/checkdependencies.h"
#include <iostream>

int state = checkd();
std::string depPath = "cd dependencies & ";
AdbMenu::AdbMenu()
{
	elements = { "Adb push","Adb pull","Install app","UnInstall App" };
}
void AdbMenu::Commands(int x)
{
	switch (x)
	{
	case 1:
		adbpush();
		break;
	case 2:
		adbpull();
		break;
	case 3:
		adbinstall();
		break;
	case 4:
		adbuninstall();
		break;
	}
}

int AdbMenu::adbpush()
{
	system("CLS");

	std::string path_on_pc;
	std::string path_on_device;

	std::cout << "Please enter path on PC: ";
	std::cin >> path_on_pc;
	std::cout << '\n';
	std::cout << "Please enter path on device: ";
	std::cin >> path_on_device;
	std::cout << '\n';

	if (state == 0)
	{
		system((depPath + "adb push " + path_on_pc + " " +path_on_device).c_str());
		return 0;
	}
	return -1;
}
int AdbMenu::adbpull()
{
	std::cout << "life is hard 2" << std::endl;
	return 0;
}
int AdbMenu::adbinstall()
{
	std::cout << "life is hard 3" << std::endl;
	return 0;
}
int AdbMenu::adbuninstall()
{
	std::cout << "life is hard 4" << std::endl;
	return 0;
}
