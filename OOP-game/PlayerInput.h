#pragma once
#include "Controlls.h"
#include "timer.h"

#include <string>
#include <Windows.h>
#include <map>
#include <vector>
#include <iostream>


class PlyerInput
{
private:
	std::map<int, Controlls>& crls;
	Timer ti;
	long long frameRate;
	Controlls c;
public:
	PlyerInput(std::map<int, Controlls>& crls, long long frameRate) : crls(crls), frameRate(frameRate) {};

	Controlls action() {
		c = Controlls::nothing;
		ti.start();
		while (ti.elapsedMilliseconds() < frameRate) {
			for (const auto& el : crls) {
				if (GetAsyncKeyState(el.first)) {
					c = el.second;
				}
			}
		}
		ti.stop();
		return c;
	}
};

