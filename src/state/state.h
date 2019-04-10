#pragma once
#ifndef _STATE_H
#define _STATE_H

#include <SDL.h>

// Forward
namespace graphics { class Screen; }
using namespace graphics;
namespace input { class InputListener; }

namespace state
{
	class State
	{
	public:
		virtual ~State() { }

		virtual void release() = 0;
		virtual void load() = 0;
		virtual void handleEvent(InputListener *il) = 0;
		virtual void update(float) = 0;
		virtual void render(Screen *screen) = 0;

		int *pixels;
	};
}

#endif
