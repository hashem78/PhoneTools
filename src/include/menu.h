#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

class Menu
{
protected:
	std::vector<std::string> elements;
public:
	friend void printMenu(Menu &);
	virtual void Commands(int)=0;
};

#endif