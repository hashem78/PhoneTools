#ifndef ADB_MENU_H
#define ADB_MENU_H
#include "../menu.h"

extern int state;
extern std::string depPath;
class AdbMenu : public Menu
{
public:
	AdbMenu();
	void Commands(int);

	int adbpush();
	int adbpull();

	int adblistpackages();
	int adbinstall();
	int adbinstallbatch();
	int adbinstallsingle();
	int adbuninstall();
	
};
#endif