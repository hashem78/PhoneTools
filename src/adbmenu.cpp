#define _CRT_SECURE_NO_WARNINGS //visual studio ass thanks stackoverflow <3
#include "include/menus/adbmenu.h"
#include "include/menus/adbmenu_install_apk.h"
#include "include/menus/adbmenu_list_apps.h"
#include "include/menus/adbmenu_reboot_options.h"
#include "include/menus/adbmenu_debugging.h"
#include "include/checkdependencies.h"
#include "include/directory_handler.h"
#include <chrono>
#include <iostream>
#include <algorithm>
#include <fstream>

int state = checkd();
std::string depPath = "cd dependencies & ";
AdbMenu::AdbMenu()
{
	elements = { "Adb push","Adb pull","Install app","Uninstall App","List apps","Screen record","Reboot options","Debugging","Navigate" };
}
void AdbMenu::startScreen()
{
	std::cout << "///Adb Options///\n";
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
		adbinstallmenu();
		break;
	case 4:
		adbuninstall();
		break;
	case 5:
		adblistappsmenu();
		break;
	case 6:
		adbscreenrecord();
		break;
	case 7:
		adbrebootoptions();
		break;
	case 8:
		adbdebuggingmenu();
	case 9:
		adbnavigate();
	}
}
void AdbMenu::adbnavigate()
{
	populate_pathlist("/");
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
int AdbMenu::adbpull(std::string path_on_device, std::string path_on_pc)
{
	system("CLS");

	if (path_on_device == "" && path_on_pc == "")
	{
		std::cout << "Please enter path on device: ";
		std::cin >> path_on_device;
		std::cout << '\n';
		std::cout << "Please enter path on PC: ";
		std::cin >> path_on_pc;
		std::cout << '\n';
	}
	if (state == 0)
	{
		system((depPath + "adb pull " + path_on_device + " " + path_on_pc).c_str());
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

int AdbMenu::adblistappsmenu()
{
	AdbMenuListApps M;
	if (!M.show())

	return 0;
}

int AdbMenu::adbrebootoptions()
{
	AdbMenuRebootOptions M;
	if (!M.show())
		return 0;

	return 0;
}
int AdbMenu::adbinstallmenu()
{
	AdbInstallMenu M;

	if(!M.show())
	   return 0;
	return 0;
}
int AdbMenu::adbdebuggingmenu()
{
	AdbMenuDebugging M;
	if (!M.show())
		return 0;
	return 0;
}
int AdbMenu::adbscreenrecord()
{
	system("CLS");
	struct recops
	{
		int height, width;
		int length;
		long bitrate;
		recops(int h = 720, int w = 1280, int l = 180, long b = 4000000)
		{
			if (h == 0)
				height = 720;
			else
				height = h;
			if (w == 0)
				width = 1280;
			else
				width = w;
			if (l == 0)
				length = 180;
			else
				length = l;

			if (b == 0)
				bitrate = 4000000;
			else
				bitrate = b;
		}
	};
	int a, b, c, d;
	std::cout << "Please enter details asked, enter 0 for default values\n";
	std::cout << "Enter recording height: ";
	std::cin >> a;
	std::cout << "\nEnter recording width: ";
	std::cin >> b;
	std::cout << "\nEnter recording length(seconds): ";
	std::cin >> c;
	std::cout << "\nEnter recording bitrate: ";
	std::cin >> d;
	recops options(a, b, c, d);
	std::string fileName;

	auto timenow = std::chrono::system_clock::now();
	time_t currt = std::chrono::system_clock::to_time_t(timenow);
	fileName = ctime(&currt);
	fileName[fileName.size() - 1] = '4'; //these lines idk why but filename wasn't getting concatinated so i improvised :P
	fileName[fileName.size() - 2] = 'p';
	fileName[fileName.size() - 3] = 'm';
	fileName[fileName.size() - 4] = '.';



	std::replace(fileName.begin(), fileName.end(), ' ', '_');
	std::replace(fileName.begin(), fileName.end(), ':', '-');//NO FOOKN ILLEGAL CHARS

	std::string com = "adb shell screenrecord --size "
		+ std::to_string(options.width)
		+ "x" + std::to_string(options.height)
		+ " --bit-rate " + std::to_string(options.bitrate)
		+ " --time-limit " + std::to_string(options.length)
		+ " /sdcard/" + fileName;
	std::cout << "Recording...\n";
	system((depPath + com).c_str());
	std::cout << "Enter path on pc: ";
	std::string path_on_pc;
	std::cin >> path_on_pc;
	std::cout << '\n';
	adbpull("/sdcard/"+fileName,path_on_pc);

	return 0;
}