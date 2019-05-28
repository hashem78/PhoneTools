#pragma once

#include <vector>
#include <string>

int getOption(int);
class Menu
{
protected:
	std::vector<std::string> elements;
public:
	friend void printMenu(Menu &);
	virtual void Commands(int)=0;
};
