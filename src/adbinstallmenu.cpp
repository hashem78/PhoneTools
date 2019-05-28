#include "include/menus/adbmenu_install_apk.h"
#include "include/menus/adbmenu.h"
#include <iostream>
#include <filesystem>


AdbInstallMenu::AdbInstallMenu()
{
	elements = { "Install single apk file","Batch Install apk files" };
}
void AdbInstallMenu::Commands(int x)
{
	switch (x)
	{
	case 1:
		adbinstallsingle();
		break;
	case 2:
		adbinstallbatch();
		break;
	}
}
int adbinstallbatch()
{
	if (state == 0) {
		system("CLS");
		std::string path_on_pc;
		std::string c = "adb install -r ";
		std::cout << "Please enter path of folder to install apks from: ";
		std::cin >> path_on_pc;
		std::cout << '\n';
		for (const auto& entry : std::filesystem::directory_iterator(path_on_pc))
		{
			std::cout << "Installing: " << entry.path().generic_string() << '\n';
			system((depPath + c + entry.path().generic_string()).c_str());
			//std::cout << entry.path().generic_string() << std::endl;
		}

		return 0;
	}

	return -1;

}
int adbinstallsingle()
{
	if (state == 0) {
		system("CLS");
		std::string path_on_pc;
		std::string c = "adb install ";
		std::cout << "Please enter path of apk: ";
		std::cin >> path_on_pc;
		std::cout << '\n';

		system((depPath + c + path_on_pc).c_str());


		return 0;
	}

	return -1;

}