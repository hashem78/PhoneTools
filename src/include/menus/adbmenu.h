#pragma once

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
	int adbuninstall();


	int adbrebootoptions();//menu
	int adblistappsmenu();//menu
	int adbinstallmenu();//menu

};