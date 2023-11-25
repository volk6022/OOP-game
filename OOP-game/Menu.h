#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <conio.h>

#define LVL_DIR "/OOP/OOP/lvls"
#define QUIT "\0"

class Menu
{
public:
	Menu() {}
	std::string MainMenu() {
	start:
		std::cout << "Press q to quit the game\nPress l to print list of lvls\n";
		char ch = _getch();
		if (ch == 'q') {
			std::string e;
			return e;
		}
		if (ch != 's') {
			goto start;
		}
		std::vector <std::string> lst;
		int counter = 0;
		std::cout << "available lvls\n";
		for (const auto& entry : std::filesystem::directory_iterator(LVL_DIR)) {
			// remake if{} - it must check for dir and for files in it
			if (std::filesystem::is_character_file(entry)) {
				lst.push_back(entry.path().string());
				std::cout << counter << ": " << lst.back() << '\n';
				++counter;
			}
		}
		std::cout << counter << "default lvl\n";

		if (lst.size() == 0) {
			std::cout << "looks like you have no lvls yet\n";
			std::string e;
			return e;
		}

	choose_lvl:
		std::cout << "\nenter lvl numder 0 to " << lst.size()-1 << ": ";
		int l = 0;
		std::cin >> l;
		if (l >= lst.size()) {
			std::cout << "enter correct number\n";
			goto choose_lvl;
		}
		return lst[l];
	}
	// press q - quit
	// press l - indexed list of lvls
};

