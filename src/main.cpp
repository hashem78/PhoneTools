#include <iostream>
#include "include/menus/mainmenu.h"

using namespace std;

int main()
{
	Menu* p = new MainMenu;
	p->show();

	delete p;
}
