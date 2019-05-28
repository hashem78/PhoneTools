#ifndef ADBMENU_REBOOT_OPTIONS
#define ADBMENU_REBOOT_OPTIONS

#include "../menu.h"
class AdbMenuRebootOptions : public Menu
{
public:
	AdbMenuRebootOptions();
	void Commands(int);
};
int adbreboot();
int adbsoftreboot();
int adbrebootrecovery();
int adbrebootbootloader();

#endif // !ADBMENU_REBOOT_OPTIONS
