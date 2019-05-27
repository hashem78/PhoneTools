#include "include/checkdependencies.h"
#include <filesystem>
#include <iostream>

std::vector <std::string> filenames = {"adb.exe","AdbWinApi.dll","AdbWinUsbApi.dll","fastboot.exe"};

int checkd()
{
	for (auto x : filenames)
		if (!std::filesystem::exists("dependencies/"+x))
			return 1;
	return 0;
}