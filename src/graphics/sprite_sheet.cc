#include "sprite_sheet.h"

#include <SDL_.h>
#include <SDL_image.h>

#include "helper_sdl.h"

#include <stdexcept>

using namespace helper;
namespace graphics
{
	SpriteSheet::SpriteSheet(const std::string& path, int width, int height)
		: path(path)
	{
		SIZE = -1;
		SPRITE_WIDTH = width;
		SPRITE_HEIGHT = height;
		pixels = new int[SPRITE_WIDTH * SPRITE_HEIGHT];
		load();
	}

	SpriteSheet::~SpriteSheet()
	{
		delete[] pixels;
	}

	void SpriteSheet::load()
	{
		try
		{
			int *buffer = _get_data_png(path.c_str(), width, height);
			for (int y=0; y<height; ++y)
				for (int x=0; x<width; ++x)
					pixels[x + y * width] = buffer[x + y * width];
		}
		catch (std::exception& e)
		{
			std::runtime_error(e.what());
		}
		
	}
}
