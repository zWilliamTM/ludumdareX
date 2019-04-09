#pragma once
#ifndef _EVENT_H
#define _EVENT_H

namespace event
{
	enum Type
	{
		MOUSE_PRESSED,
		MOUSE_RELEASED,
		MOUSE_MOVED
	};

	class Event
	{
	public:
		Type getType();

		bool handled;

	protected:
		Event(Type type);

	private:
		Type type;
	};
}

#endif
