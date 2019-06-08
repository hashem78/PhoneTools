#include "include/directory_handler.h"
#include "include/checkdependencies.h"

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <Windows.h>
int state1 = checkd();
std::string depPath1 = "cd dependencies & ";
std::map <int, std::string> pathlist;

std::string lastPath = "";
int level_offset = 0;
void populate_pathlist(std::string dirName)
{
	pathlist.clear(); //clear previous path
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

		int counter = 2;
		pathlist[1] = ".";
		while (std::getline(file, curPath))
			pathlist[counter++] = curPath;

		if (dirName != "/")//avoid duplicate first/
			lastPath += dirName + "/";
		else lastPath = "/";
		std::cin.ignore();
		std::cin.clear();
		file.close();
		system(("mode con: cols=40 lines=" + std::to_string(pathlist.size() + 15)).c_str());
		showdir();

	}
}
void showdir()
{

	system("CLS");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice;

	std::cout.flush();
	for (const auto& x : pathlist)
	{
		if (x.second.find('.') != std::string::npos)
			SetConsoleTextAttribute(hConsole, 10);
		else
			SetConsoleTextAttribute(hConsole, 15);
		std::cout << "(" << x.first << ")" << x.second << '\n';
	}
	std::cout << "\nEnter choice:";
	std::cin >> choice;

	if (choice == 1)
	{
		lastPath.erase(lastPath.find_last_of('/'));//remove last /
		lastPath.erase(lastPath.find_last_of('/')); //remove last /something

		populate_pathlist("");//empty so that lastpath can be used

		return;
	}

	while (pathlist[choice].find('.') != std::string::npos) {
		std::cout << pathlist[choice] << " is not a directory";
		std::cout << "\nEnter another choice:";
		std::cin >> choice;
	}
	populate_pathlist(pathlist[choice]);


}
