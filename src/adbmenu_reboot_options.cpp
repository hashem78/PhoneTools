#include "include/menus/adbmenu_reboot_options.h"
#include "include/menus/adbmenu.h"
#include <iostream>

AdbMenuRebootOptions::AdbMenuRebootOptions()
{
	elements = {"Normal reboot","Soft reboot","Reboot to recovery","Reboot to bootloader"};
}
void AdbMenuRebootOptions::Commands(int x)
{
	switch (x)
	{
	case 1:
		adbreboot();
		break;
	case 2:
		adbsoftreboot();
		break;
	case 3:
		adbrebootrecovery();
		break;
	case 4:
		adbrebootbootloader();
		break;
	}
}
void AdbMenuRebootOptions::startScreen()
{
	std::cout << "///Reboot Options///\n";
}
int adbreboot()
{
	if (state == 0)
	{
		system((depPath + "adb reboot").c_str());
		return 0;
	}

	return -1;
}
int adbsoftreboot()
{
	if (state == 0)
	{
		system((depPath + "adb reboot").c_str());
		return 0;
	}

	return -1;
}
int adbrebootrecovery()
{
	if (state == 0)
	{
		system((depPath + "adb reboot recovery").c_str());
		return 0;
	}

	return -1;
}
int adbrebootbootloader()
{
	if (state == 0)
	{
		system((depPath + "adb reboot booloader").c_str());
		return 0;
	}

	return -1;
}