#include "helper_sdl.h"

#include <SDL.h>
#include <SDL_image.h>

#include <string>
#include <stdexcept>

namespace helper
{
	int* _get_data_png(const char* path, int width, int height)
	{
		SDL_Surface *t = IMG_Load("sheet_test.png");
		if (!t) throw std::runtime_error("Error load image: " + std::string(path));
		SDL_Surface *img = SDL_ConvertSurfaceFormat(t, SDL_PIXELFORMAT_RGB888, 0);
		SDL_FreeSurface(t);
		int *buffer = new int[width * height];
		for (int y=0; y<height; ++y)
			for (int x=0; x<width; ++x)
				buffer[x + y * width] = ((int*)img->pixels)[x + y * width];

		return buffer;
	}
}
