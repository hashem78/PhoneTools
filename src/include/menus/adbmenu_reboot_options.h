#pragma once

#include "../menu.h"
class AdbMenuRebootOptions : public Menu
{
public:
	AdbMenuRebootOptions();
	void startScreen();
	void Commands(int);
};
int adbreboot();
int adbsoftreboot();
int adbrebootrecovery();
int adbrebootbootloader();
