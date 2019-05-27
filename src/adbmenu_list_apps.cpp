#include "include/menus/adbmenu_list_apps.h"
#include "include/menus/adbmenu.h"

AdbMenuListApps::AdbMenuListPackages()
{
	elements = {"Show user packages","Show system packages","Show all packages"};
}
void AdbMenuListApps::Commands(int x)
{
	AdbMenu M;
	switch (x)
	{
	case 1:
		M.adbshowuserapps();
		break;
	case 2:
		M.adbshowsystemapps();
		break;
	case 3:
		M.adbshowallapps();
		break;
	}
}