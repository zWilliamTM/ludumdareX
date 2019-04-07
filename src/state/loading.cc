#include "loading.h"
#include "screen.h"

using namespace graphics;
namespace state
{
	Loading::Loading()
	{
		pixels = new int[300 * 168];
	}

	Loading::~Loading()
	{
		delete[] pixels;
	}

	void Loading::release()
	{
	}

	void Loading::load()
	{
		for (int y=0; y<168; ++y)
		{
			for (int x=0; x<300; ++x)
			{
				pixels[x + y * 300] = 0xFF0000;
			}
		}
	}

	void Loading::handleEvent(SDL_Keycode e)
	{
	}

	void Loading::update(float)
	{
	}

	void Loading::render(Screen *screen)
	{
		screen->render(pixels);
	}
}
