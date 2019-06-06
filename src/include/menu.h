#pragma once

#include <vector>
#include <string>
#include <memory>

int getOption(int);
extern int option;
extern int level;
class Menu
{
protected:
	std::vector<std::string> elements;
public:
	int show();
	virtual void Commands(int) = 0;
	virtual void startScreen() = 0;
};
extern std::unique_ptr <Menu> p;