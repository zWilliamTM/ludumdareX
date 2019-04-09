#include "event_dispatcher.h"
#include "abstract_event.h"

namespace event
{
	EventDispatcher::EventDispatcher(const Event& event)
		: event(event)
	{
	}

	void EventDispatcher::dispatch(Type type, EventHandler& handler)
	{
		if (event.handled) return;
		if (event.getType() == type) event.handled = handler.onEvent(event);
	}
}
