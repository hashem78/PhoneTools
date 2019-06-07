#pragma once
#include "../menu.h"
class AdbMenuDebugging : public Menu
{
public:
	AdbMenuDebugging();
	void startScreen();
	void Commands(int x);
	void takelogcat();
	void takekmsg();
	void takedmsg();
	void takedump();


};

