#include "keyboard.h"

namespace input
{
	Keyboard::Keyboard()
	{
		up=down=left=right=false;
	}

	Keyboard::~Keyboard()
	{
	}

	void Keyboard::update()
	{
		up = keys[SDLK_w];
		down = keys[SDLK_s];
		left = keys[SDLK_a];
		right = keys[SDLK_d];
	}

	void Keyboard::keyPressed(SDL_Keycode key)
	{
		keys[key] = true;
	}

	void Keyboard::keyReleased(SDL_Keycode key)
	{
		keys[key] = false;
	}
}
