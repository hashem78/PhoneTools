#include "include/menu.h"
#include <vector>
#include <string>
#include <iostream>
#include<chrono>
#include <thread>

int option;

int getOption(int elsize)
{
	std::cout << "Enter choice: ";
	std::cin >> option;
	std::cout << '\n';

	if (std::cin.good() && option >= 0 && option <= elsize)
		return 0;
	else {
		std::cin.clear();
		std::cin.ignore();
		return -1;
	}
}
void Menu::show()
{
	system("CLS");
	
	int counter = 1;

	for (auto x : elements)
		std::cout << '(' << counter++ << ')' << ' ' << x << '\n';
	 

	while (getOption(elements.size()) != 0)
	{
		std::cout << "Wrong choice entered! please choose another.\n";
		std::chrono::seconds time_to_sleep(1); //stackoverflow <3
		std::this_thread::sleep_for(time_to_sleep);
		this->show();
	}
	Commands(option);
}