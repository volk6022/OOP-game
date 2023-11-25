#pragma once
#include "Controlls.h"
#include <string>
#include <Windows.h>
#include <map>
#include <vector>


class PlyerInput
{
private:
	std::map<int, Controlls>* crls;

public:
	PlyerInput(std::map<int, Controlls>* crls) : crls(crls) {};

	Controlls action() {
		for (const auto& el : *crls) {
			if (GetKeyState(el.first)) {
				return el.second;
			}
		}
	}
};

