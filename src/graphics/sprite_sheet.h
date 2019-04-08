#pragma once
#ifndef _SPRITE_SHEET_H
#define _SPRITE_SHEET_H

#include <string>

namespace graphics
{
	class SpriteSheet
	{
	public:
		SpriteSheet(const std::string& path, int size);
		~SpriteSheet();

	private:
		void load();

	public:
		int SIZE;
		int SPRITE_WIDTH;
		int SPRITE_HEIGHT;
		int *pixels;

	private:
		int width;
		int height;
		std::string path;
	};
}

#endif
