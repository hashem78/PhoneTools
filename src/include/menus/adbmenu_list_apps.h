#ifndef ADBMENU_LIST_PACKAGES
#define ADBMENU_LIST_PACKAGES

#include "../menu.h"
class AdbMenuListApps :public Menu
{
public:
	AdbMenuListApps();
	void Commands(int);
};

#endif 
