#pragma once
#include <string>
#include <map>


struct pathlisttype
{
	std::string name;
	bool isDir;
};

extern int state1;//stores value of checkd()
extern std::map <int, pathlisttype> pathlist;//final directory names holder
extern std::string depPath1;//path to adb
void populate_pathlist(std::string);
void showdir();
void clean_and_sort();

