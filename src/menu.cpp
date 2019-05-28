#include "include/menu.h"
#include <vector>
#include <string>
#include <iostream>

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
void printMenu(Menu &M)
{
	system("CLS");
	
	int counter = 1;
	for (auto x : M.elements)
		std::cout << '(' << counter++ << ')' << ' ' << x << '\n';

	while (getOption(M.elements.size()) != 0)
		std::cout << "Wrong choice entered! please choose another.\n";

	M.Commands(option);
}