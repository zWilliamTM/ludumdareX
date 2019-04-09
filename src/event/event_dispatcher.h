#pragma once
#ifndef _EVENT_DISPATCHER_H
#define _EVENT_DISPATCHER_H

#include "event.h"

namespace event
{
	// Forward
	class EventHandler;

	class EventDispatcher
	{
	public:
		EventDispatcher(const Event& event);

		void dispatch(Type type, EventHandler& handler);

	private:
		Event event;
	};
}

#endif
