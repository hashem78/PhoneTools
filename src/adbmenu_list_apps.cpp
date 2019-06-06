#include "include/menus/adbmenu_list_apps.h"
#include "include/menus/adbmenu.h"
#include <iostream>

AdbMenuListApps::AdbMenuListApps()
{
	elements = {"Show user packages","Show system packages","Show all packages"};
}
void AdbMenuListApps::Commands(int x)
{
	switch (x)
	{
	case 1:
		adbshowuserapps();
		break;
	case 2:
		adbshowsystemapps();
		break;
	case 3:
		adbshowallapps();
		break;
	}
}
void AdbMenuListApps::startScreen()
{
	std::cout << "///List Apps///\n";
}
int adbshowuserapps()
{
	if (state == 0)
	{

		system((depPath + "adb shell pm list packages -3 \"| cut -f 2 -d \":\"").c_str());
		return 0;
	}
	return -1;
}
int adbshowsystemapps()
{
	if (state == 0)
	{
		system((depPath + "adb shell pm list packages -s \"| cut -f 2 -d \":\"").c_str());
		return 0;
	}
	return -1;
}
int adbshowallapps()
{
	if (state == 0)
	{
		system((depPath + "adb shell pm list packages \"| cut -f 2 -d \":\"").c_str());
		return 0;
	}
	return -1;
}