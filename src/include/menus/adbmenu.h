#pragma once

#include "../menu.h"

extern int state;
extern std::string depPath;
class AdbMenu : public Menu
{
public:
	AdbMenu();
	void Commands(int);
	void startScreen();
	int adbpush();
	int adbpull(std::string="",std::string="");
	int adbuninstall();
	int adbscreenrecord();

	int adbrebootoptions();//menu
	int adblistappsmenu();//menu
	int adbinstallmenu();//menu
	int adbdebuggingmenu();//menu


};