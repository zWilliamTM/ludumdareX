#pragma once
#ifndef _LOADING_H
#define _LOADING_H

#include "state.h"

// Forward
namespace graphics { class Screen; }
using namespace graphics;
namespace input { class InputListener; }
using namespace input;

namespace state
{
	class Loading : public State
	{
	public:
		Loading();
		~Loading();

		void release();
		void load();
		void handleEvent(InputListener *il);
		void update(float);
		void render(Screen *screen);

	private:
	};
}

#endif
