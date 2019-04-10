#include "sprite_sheet.h"
#include "sprite.h"

#include <SDL.h>
#include <SDL_image.h>

#include "helper_sdl.h"

#include <iostream>
#include <stdexcept>
#include <exception>

namespace graphics
{
	SpriteSheet::SpriteSheet(SpriteSheet *sheet, int x, int y, int width, int height, int spriteSize)
		: SIZE(width == height ? width : -1)
		, SPRITE_WIDTH(width), SPRITE_HEIGHT(height)
	{
		int xx = x * spriteSize;
		int yy = y * spriteSize;
		int w = width * spriteSize;
		int h = height * spriteSize;
		pixels = new int[w * h];
		for (int y0=0; y0<h; ++y0)
		{
			int yp = yy + y0;
			for (int x0=0; x0<w; ++x0)
			{
				int xp = xx + x0;
				pixels[x0 + y0 * w] = sheet->pixels[xp + yp * sheet->SPRITE_WIDTH];
			}
		}
		int frames = 0;

		sprites = std::vector<std::unique_ptr<Sprite>>(width * height);
		for (int ya=0; ya<height; ++ya)
		{
			for (int xa=0; xa<width; ++xa)
			{
				int *spritePixels = new int[spriteSize * spriteSize];
				for (int y0=0; y0<spriteSize; ++y0)
				{
					for (int x0=0; x0<spriteSize; ++x0)
					{
						spritePixels[x0 + y0 * spriteSize] =
							pixels[(x0 + xa * spriteSize) + (y0 + ya * spriteSize) * SPRITE_WIDTH];
					}
				}
				sprites[frames++].reset(new Sprite(spritePixels, spriteSize, spriteSize));
			}
		}
	}

	SpriteSheet::SpriteSheet(const std::string& path, int size)
		: path(path)
		, SIZE(size)
		, SPRITE_WIDTH(size), SPRITE_HEIGHT(size)
	{
		load();
	}

	SpriteSheet::SpriteSheet(const std::string& path, int width, int height)
		: path(path)
		, width(width), height(height)
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

	std::vector<std::unique_ptr<Sprite>>& SpriteSheet::getSprites()
	{
		return sprites;
	}

	int SpriteSheet::getWidth()
	{
		return width;
	}

	int SpriteSheet::getHeight()
	{
		return height;
	}

	int* SpriteSheet::getPixels()
	{
		return pixels;
	}

	void SpriteSheet::load()
	{
		try
		{
			helper::_reset_buffer(&pixels, width * height);
			int *buffer = helper::_get_data_png(path.c_str(), width, height);
			for (int y=0; y<height; ++y)
				for (int x=0; x<width; ++x)
					pixels[x + y * width] = buffer[x + y * width];
		}
		catch (std::exception& e)
		{
			// TODO.
			std::cout << e.what() << std::endl;
		}
		
	}
}
