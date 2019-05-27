#include "include/menus/adbmenu.h"
#include "include/menus/adbmenu_install_apk.h"
#include"include/checkdependencies.h"
#include <iostream>
#include <filesystem>

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
	system("CLS");

	std::string path_on_pc;
	std::string path_on_device;

	std::cout << "Please enter path on device: ";
	std::cin >> path_on_device;
	std::cout << '\n';
	std::cout << "Please enter path on PC: ";
	std::cin >> path_on_pc;
	std::cout << '\n';

	if (state == 0)
	{
		system((depPath + "adb pull " + path_on_device + " " + path_on_pc).c_str());
		return 0;
	}
	return -1;
}
int AdbMenu::adbinstall()
{
	AdbInstallMenu M;
	printMenu(M);
	return 0;
}
int AdbMenu::adbinstallbatch()
{
	system("CLS");
	std::string path_on_pc;
	std::string c = "adb install -r ";
	std::cout << "Please enter path of folder to install apks from: ";
	std::cin >> path_on_pc;
	std::cout << '\n';
	for (const auto& entry : std::filesystem::directory_iterator(path_on_pc))
	{
		std::cout << "Installing: " << entry.path().generic_string() << '\n';
		system((depPath + c + entry.path().generic_string()).c_str());
		//std::cout << entry.path().generic_string() << std::endl;
	}

	return 0;

}
int AdbMenu::adbuninstall()
{
	std::cout << "life is hard 4" << std::endl;
	return 0;
}
