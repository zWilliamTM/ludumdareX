#pragma once
#ifndef _SPRITE_SHEET_H
#define _SPRITE_SHEET_H

#include <string>
#include <vector>
#include <memory>

namespace graphics
{
	// Forward
	class Sprite;

	class SpriteSheet
	{
	public:
		SpriteSheet(SpriteSheet *sheet, int x, int y, int width, int height, int spriteSize);
		SpriteSheet(const std::string& path, int size);
		SpriteSheet(const std::string& path, int width, int height);
		~SpriteSheet();

		std::vector<std::unique_ptr<Sprite>>& getSprites();

		int getWidth();
		int getHeight();

		int* getPixels();


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
		std::vector<std::unique_ptr<Sprite>> sprites;
	};
}

#endif
