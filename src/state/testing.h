#pragma once
#ifndef _TESTING_H
#define _TESTING_H

#include "state.h"
#include "sprite_sheet.h"

#include <memory>

// Forward
namespace graphics { class Screen; }
using namespace graphics;
namespace input { class InputListener; }
using namespace input;

namespace state
{
	class Testing : public State
	{
	public:
		Testing();
		~Testing();

		void release();
		void load();
		void handleEvent(InputListener *il);
		void update(float);
		void render(Screen *screen);

	private:
		std::unique_ptr<SpriteSheet> sheet;
		int x;
		int y;
		int dir_x;
	};
}

#endif
