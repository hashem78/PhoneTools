#include "include/menus/adbmenu_install_apk.h"
#include "include/menus/adbmenu.h"


AdbMenu M;
AdbInstallMenu::AdbInstallMenu()
{
	elements = { "Install single apk file","Batch Install apk files" };
}
void AdbInstallMenu::Commands(int x)
{
	switch (x)
	{
	case 1:
		M.adbinstall();
		break;
	case 2:
		M.adbinstallbatch();
		break;
	}
}
