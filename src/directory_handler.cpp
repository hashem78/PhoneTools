#include "include/directory_handler.h"
#include "include/checkdependencies.h"//for checkd()

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <Windows.h> //for console colors

int state1 = checkd();//check for deps
std::string depPath1 = "cd dependencies & "; //path to adb
std::map <int, pathlisttype> pathlist;//final map with sorted files and folders
std::string lastPath = "";//global var to track paths


int longest_string = 0, shortest_string = INT_MAX;//to set correct console witdh and height
/*
clean_and_sort()
to separate directories from files properly

uses std::map to hold directory and file names
generates file numbers based on odd and even
then merges both into pathlist

if no files or folders are found the map is reordered

*/
void clean_and_sort()
{
	std::ifstream file("dependencies/pathlist.txt");
	if (!file.is_open())
		return;
	std::map<int, pathlisttype> dirs;//holds directories
	std::map<int, pathlisttype> files;//holds files
	int counter_even = 2, counter_odd = 3;
	std::string curr = "";//to store current string being handled in loop

	while (std::getline(file, curr))
	{
		if (curr[0] == 'd') {

			curr = curr.substr(curr.find(':') + 4);//ls -lL provides really good output here
			dirs[counter_even].name = curr;
			dirs[counter_even].isDir = true;
			counter_even += 2;
			if (curr.length() > longest_string)
				longest_string = curr.length();
			if (curr.length() < shortest_string)
				shortest_string = curr.length();

		}
		if (curr[0] == '-') {
			curr = curr.substr(curr.find(':') + 4);
			files[counter_odd].name = curr;
			files[counter_odd].isDir = false;
			counter_odd += 2;
			if (curr.length() > longest_string)
				longest_string = curr.length();
			if (curr.length() < shortest_string)
				shortest_string = curr.length();

		}

	}
	pathlist[1].name = ".";//add back a level to map
	pathlist[1].isDir = true;

	//merge
	pathlist.merge(dirs);
	pathlist.merge(files);

	if (dirs.empty() || files.empty())//if there were no files or dirs sort items correctly
	{
		int m = 1;
		for (auto& x : pathlist)
		{
			auto nh = pathlist.extract(x.first); //again stackover flow for the rescue
			nh.key() = m++;
			pathlist.insert(std::move(nh));
		}
	}
	file.close();
}
void populate_pathlist(std::string dirName)
{
	pathlist.clear(); //clear previous path
	if (state1 == 0)
	{

		system((depPath1 + "adb shell \"ls -lL " + lastPath + dirName + " > /sdcard/pathlist.txt\"").c_str());
		//system("PAUSE");
		system((depPath1 + "adb pull /sdcard/pathlist.txt > nul").c_str());

		clean_and_sort();

		std::ifstream file("dependencies/pathlist.txt");
		if (!file.is_open())
		{
			std::cout << "Something went wrong\n";
			return;
		}
		std::string curPath = "";

		if (dirName != "/")//avoid duplicate first/
			lastPath += dirName + "/";
		else lastPath = "/";
		std::cin.ignore();//precautions
		std::cin.clear();
		file.close();
		system(("mode con: cols="+std::to_string(longest_string+3) +"lines=" + std::to_string(pathlist.size()+5)).c_str());
		showdir();

	}
}
void showdir()
{

	system("CLS");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//change console color
	int choice;

	std::cout.flush();
	for (const auto& x : pathlist)
	{
		if (x.second.isDir == false)
			SetConsoleTextAttribute(hConsole, 10);//actual console color change(green)
		else
			SetConsoleTextAttribute(hConsole, 15);//actual console color change(white)
		std::cout << "(" << x.first << ")" << x.second.name << '\n';
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
	//handle wrong choices
	while (pathlist[choice].isDir == false) {
		std::cout << pathlist[choice].name << " is not a directory";
		std::cout << "\nEnter another choice:";
		std::cin >> choice;
	}
	populate_pathlist(pathlist[choice].name);


}
