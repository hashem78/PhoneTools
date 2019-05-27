#include "include/menus/adbmenu.h"
#include "include/menus/adbmenu_install_apk.h"
#include "include/menus/adbmenu_list_apps.h"
#include"include/checkdependencies.h"
#include <iostream>
#include <filesystem>
#include <fstream>

int state = checkd();
std::string depPath = "cd dependencies & ";
AdbMenu::AdbMenu()
{
	elements = { "Adb push","Adb pull","Install app","UnInstall App","List apps" };
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
	case 5:
		adblistapps();
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
		system((depPath + "adb push " + path_on_pc + " " + path_on_device).c_str());
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
	if (state == 0) {
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

	return -1;

}
int AdbMenu::adbinstallsingle()
{
	if (state == 0) {
		system("CLS");
		std::string path_on_pc;
		std::string c = "adb install ";
		std::cout << "Please enter path of apk: ";
		std::cin >> path_on_pc;
		std::cout << '\n';

		system((depPath + c + path_on_pc).c_str());


		return 0;
	}

	return -1;

}
int AdbMenu::adbuninstall()
{
	if (state == 0) {
		system("CLS");
		std::string appname;
		std::string com;
		std::cout << "Please enter app name: ";
		std::cin >> appname;

		system((depPath + "adb shell pm list packages -3 \"| cut -f 2 -d \":\"| grep \"" + appname + '\"' + (std::string)"> /sdcard/del.txt").c_str());
		system((depPath + "adb pull /sdcard/del.txt > nul & adb shell rm -rf /sdcard/del.txt").c_str());

		std::ifstream file("dependencies/del.txt");
		if (file.is_open())
			file >> com;
		system((depPath + "adb uninstall " + com).c_str());
		file.close();
		return 0;
	}
	return -1;
}

int AdbMenu::adblistapps()
{
	AdbMenuListApps M;
	printMenu(M);
	return 0;
}
int AdbMenu::adbshowuserapps()
{
	if (state == 0)
	{

		system((depPath+ "adb shell pm list packages -3 \"| cut -f 2 -d \":\"").c_str());
		return 0;
	}
	return -1;
}
int AdbMenu::adbshowsystemapps()
{
	system((depPath + "adb shell pm list packages -s \"| cut -f 2 -d \":\"").c_str());
	return 0;
}
int AdbMenu::adbshowallapps()
{
	system((depPath + "adb shell pm list packages \"| cut -f 2 -d \":\"").c_str());
	return 0;
}
