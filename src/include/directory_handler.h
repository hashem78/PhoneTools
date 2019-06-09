#pragma once
#include <string>
#include <map>


struct pathlisttype
{
	std::string name;
	bool isDir;
};

extern int state1;
extern std::map <int, pathlisttype> pathlist;
extern std::string depPath1;
void populate_pathlist(std::string);
void showdir();
void clean_and_sort();

