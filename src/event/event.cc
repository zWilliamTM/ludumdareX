#include "event.h"

namespace event
{
	Event::Event(Type type)
		: type(type)
	{
	}

	Type Event::getType()
	{
		return type;
	}
}
