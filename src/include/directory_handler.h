#pragma once
#include <string>
#include <map>

extern int state1;
extern std::map <int, std::string> pathlist;
extern std::string depPath1;
void populate_pathlist(std::string);
void showdir();

