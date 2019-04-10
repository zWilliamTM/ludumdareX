#pragma once

#ifndef _HELPER_SDL_H
#define _HELPER_SDL_H

#include <cstddef>

namespace helper
{
	int* _get_data_png(const char* path, int width, int height);
	void _reset_buffer(int **buffer, std::size_t size, int color = 0);
}

#endif
