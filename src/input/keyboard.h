#pragma once
#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <SDL.h>
#include <unordered_map>

namespace input
{
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();

		void update();
		void keyPressed(SDL_Keycode key);
		void keyReleased(SDL_Keycode key);

	private:
		std::unordered_map<SDL_Keycode, bool> keys;

	public:
		bool up, down, left, right;
	};
}

#endif
