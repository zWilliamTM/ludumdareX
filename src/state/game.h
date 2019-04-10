#pragma once
#ifndef _GAME_H
#define _GAME_H

#include "state.h"

// Forward
namespace graphics { class Screen; }
using namespace graphics;
namespace input { class InputListener; }
using namespace input;

namespace state
{
	class Game : public State
	{
	public:
		Game();
		~Game();

		void release();
		void load();
		void handleEvent(InputListener *il);
		void update(float);
		void render(Screen *screen);

	private:
	};
}

#endif
