#ifndef ADB_MENU_INSTALL
#define ADB_MENU_INSTALL


#include "../menu.h"
class AdbInstallMenu :public Menu
{
public:
	AdbInstallMenu();
	void Commands(int);
};
int adbinstallbatch();
int adbinstallsingle();

#endif