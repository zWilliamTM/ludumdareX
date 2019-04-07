#pragma once
#ifndef _MENU_H
#define _MENU_H

#include "state.h"

// Forward
namespace graphics { class Screen; }
using namespace graphics;

namespace state
{
	class Menu : public State
	{
	public:
		Menu();
		~Menu();

		void release();
		void load();
		void handleEvent(SDL_Keycode e);
		void update(float);
		void render(Screen *screen);

	private:
	};
}

#endif
