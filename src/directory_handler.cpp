#include "include/directory_handler.h"
#include "include/checkdependencies.h"

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <iomanip>

int state1 = checkd();
std::string depPath1 = "cd dependencies & ";
std::map <int, std::string> pathlist;

std::string lastPath = "";

void populate_pathlist(std::string dirName)
{
	if (state1 == 0)
	{
		system((depPath1 + "adb shell \"ls " + lastPath + dirName + " > /sdcard/pathlist.txt\"").c_str());
		system((depPath1 + "adb pull /sdcard/pathlist.txt > nul").c_str());

		std::ifstream file("dependencies/pathlist.txt");
		if (!file.is_open())
		{
			std::cout << "Something went wrong\n";
			return;
		}
		std::string curPath = "";
		int counter = 1;

		pathlist.clear(); //clear previous path

		while (std::getline(file, curPath))
			pathlist[counter++] = curPath;

		lastPath += dirName + "/"; // so you can go up a dir

		showdir();
		std::cin.ignore();
		std::cin.clear();
		file.close();
	}
}
void showdir()
{
	system("CLS");
	int choice;

	std::cout.flush();
	int counter = 1;
	for (const auto& x : pathlist)
		std::cout << "(" << x.first << ")" << x.second << '\n';

	std::cout << "\nEnter choice:";
	std::cin >> choice;

	while (pathlist[choice].find('.') != std::string::npos) {
		std::cout << pathlist[choice] << " is not a directory";
		std::cout << "\nEnter another choice:";
		std::cin >> choice;
	}
	populate_pathlist(pathlist[choice]);
	

}
