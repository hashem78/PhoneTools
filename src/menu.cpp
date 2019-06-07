#include "include/menu.h"
#include "include/menus/mainmenu.h"
#include "include/menus/adbmenu.h"
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

int option;
int level = 0;
std::unique_ptr <Menu> p;
int getOption(int elsize)
{
	std::cout << "Enter choice: ";
	std::cin >> option;
	std::cout << '\n';

	if (option == -1)
		return 0;

	if (std::cin.good() && option >= 0 && option <= elsize)
		return 0;
	else {
		std::cin.clear();
		std::cin.ignore();
		return -1;
	}
}
int Menu::show()
{
	system("CLS");
	this->startScreen();
	int counter = 1;

	for (const auto& x : elements)
		std::cout << '(' << counter++ << ')' << ' ' << x << '\n';
	std::cout << "(0) Exit\n";
	if(level!=0)
	std::cout << "(-1) Back\n";

	while (getOption(elements.size()) != 0)
	{
		std::cout << "Wrong choice entered! please choose another.\n";
		std::this_thread::sleep_for(std::chrono::seconds(1)); //stackoverflow <3
		this->show();
	}
	if (option == -1) {
		level--;
		switch (level)
		{
		case 0:
			p.reset(new MainMenu);
			p->show();
			return 0;
			break;
		case 1:
			p.reset(new AdbMenu);
			p->show();
			return 0;
			break;
		}
	}
	else level++;
	if (option == 0)
		return 0;
	Commands(option);

	return 0;
}