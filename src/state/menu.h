#pragma once
#ifndef _MENU_H
#define _MENU_H

#include "state.h"

// Forward
namespace graphics { class Screen; }
using namespace graphics;
namespace input { class InputListener; }
using namespace input;

namespace state
{
	class Menu : public State
	{
	public:
		Menu();
		~Menu();

		void release();
		void load();
		void handleEvent(InputListener *il);
		void update(float);
		void render(Screen *screen);

	private:
	};
}

#endif
