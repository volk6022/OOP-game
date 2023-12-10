#include "PlayerInput.h"

#include <Windows.h>

Controlls PlayerInput::action() {
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

// system("stty raw")
// system("stty cooked")
