#include "include/menus/adbmenu_debugging.h"
#include "include/menus/adbmenu.h"
#include <stdio.h>
#include <iostream>
#include <thread>
using namespace std;
AdbMenuDebugging::AdbMenuDebugging()
{
	elements = { "Logcat","Kmsg","Dmsg","SysDump" };
}
void AdbMenuDebugging::Commands(int x)
{
	switch (x)
	{
	case 1:
		takelogcat();
	break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}
}
void AdbMenuDebugging::startScreen()
{
	std::cout << "///Debugging options///\n";
}
void takelogcat()
{
	float t = 0;
	std::cout << "How long do you want the logcat to run for?(seconds): ";
	std::cin >> t;
	std::cout << "Logging...\n";
	system((depPath + "adb shell timeout " + std::to_string(t) + "\" logcat > /sdcard/log.txt\"").c_str());
	system((depPath + "adb pull /sdcard/log.txt").c_str());
	return;
}