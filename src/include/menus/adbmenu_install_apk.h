#pragma once

#include "../menu.h"
class AdbInstallMenu :public Menu
{
public:
	AdbInstallMenu();
	void Commands(int);
	void startScreen();
};
int adbinstallbatch();
int adbinstallsingle();
