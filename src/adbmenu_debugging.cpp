#include "include/menus/adbmenu_debugging.h"
#include "include/menus/adbmenu.h"
#include <stdio.h>
#include <iostream>
#include <thread>
using namespace std;
AdbMenuDebugging::AdbMenuDebugging()
{
	elements = { "Logcat","DumpSys","Dmesg(root)","Kmsg(root)" };
}
void AdbMenuDebugging::Commands(int x)
{
	switch (x)
	{
	case 1:
		takelogcat();
	break;
	case 2:
		takedump();
		break;
	case 3:
		takedmsg();
		break;
	case 4:
		takekmsg();
		break;
	default:
		break;
	}
}
void AdbMenuDebugging::startScreen()
{
	std::cout << "///Debugging options///\n";
}
void AdbMenuDebugging::takelogcat()
{
	float t = 0;
	std::cout << "How long do you want the logcat to run for?(seconds): ";
	std::cin >> t;
	std::cout << "Logging...\n";
	if (state == 0) 
	{
		system((depPath + "adb shell timeout " + std::to_string(t) + "\" logcat > /sdcard/log.log\"").c_str());
		system((depPath + "adb pull /sdcard/log.txt").c_str());
		return;
	}
}
void AdbMenuDebugging::takedmsg()
{
	if (state == 0)
	{
		system((depPath + "adb shell su -c dmesg > dlog.log").c_str());
		return;
	}
}
void AdbMenuDebugging::takekmsg()
{
	if (state == 0)
	{
		system((depPath + "adb shell su -c \"cat /proc/last_kmsg\" > last_kmsg.log").c_str());
		return;
	}
}
void AdbMenuDebugging::takedump()
{
	if (state == 0)
	{
		system((depPath + "adb shell dumpsys > dumpsys.log").c_str());
		return;
	}
}