#include "include/menus/adbmenu_reboot_options.h"
#include "include/menus/adbmenu.h"

AdbMenu M;
AdbMenuRebootOptions::AdbMenuRebootOptions()
{
	elements = {"Normal reboot","Soft reboot","Reboot to recovery","Reboot to bootloader"};
}
void AdbMenuRebootOptions::Commands(int x)
{
	switch (x)
	{
	case 1:
		M.adbreboot();
		break;
	case 2:
		M.adbsoftreboot();
		break;
	case 3:
		M.adbrebootrecovery();
		break;
	case 4:
		M.adbrebootbootloader();
		break;
	}
}