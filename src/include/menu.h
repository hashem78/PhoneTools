#pragma once

#include <vector>
#include <string>

int getOption(int);
class Menu
{
protected:
	std::vector<std::string> elements;
public:
	void show();
	virtual void Commands(int)=0;
};
