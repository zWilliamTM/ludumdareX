#pragma once
#ifndef _ABSTRACT_EVENT_H
#define _ABSTRACT_EVENT_H

namespace event
{
	// Forward
	class Event;

	class EventListener
	{
	public:
		virtual void onEvent(Event &event) = 0;
	};

	class EventHandler
	{
	public:
		virtual bool onEvent(Event &event) = 0;
	};
}

#endif
