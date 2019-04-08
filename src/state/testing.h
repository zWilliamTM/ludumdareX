#pragma once
#ifndef _TESTING_H
#define _TESTING_H

#include "state.h"

// Forward
namespace graphics { class Screen; }
using namespace graphics;

namespace state
{
	class Testing : public State
	{
	public:
		Testing();
		~Testing();

		void release();
		void load();
		void handleEvent(SDL_Keycode e);
		void update(float);
		void render(Screen *screen);

	private:
	};
}

#endif
