#pragma once
#ifndef _LAYER_H
#define _LAYER_H

#include "event.h"

namespace event { class Event; }
namespace graphics { class Screen; }
using namespace event;
using namespace graphics;
namespace graphics::layers
{
	class Layer
	{
	public:
		virtual void onEvent(Event& event) = 0;
		virtual void update() = 0;
		virtual void render(Screen *event) = 0;
	};
}

#endif
