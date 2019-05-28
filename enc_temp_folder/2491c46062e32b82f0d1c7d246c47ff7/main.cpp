#include <iostream>
#include "include/menus/mainmenu.h"

using namespace std;

int main()
{
	Menu* p = new MainMenu;
	printMenu(*p);

	delete p;
	//system("cd dependencies & adb push");
}