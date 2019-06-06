#pragma once

#include "../menu.h"
class AdbMenuListApps :public Menu
{
public:
	AdbMenuListApps();
	void Commands(int);
	void startScreen();
};
int adbshowuserapps();
int adbshowsystemapps();
int adbshowallapps();
 
