#pragma once

#include "../menu.h"
class AdbInstallMenu :public Menu
{
public:
	AdbInstallMenu();
	void Commands(int);
};
int adbinstallbatch();
int adbinstallsingle();
