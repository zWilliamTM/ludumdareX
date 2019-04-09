#pragma once
#ifndef _SPRITE_H
#define _SPRITE_H

#include <vector>
#include <memory>

namespace graphics
{
	// Forward
	class SpriteSheet;

	class Sprite
	{
	public:
		Sprite(SpriteSheet *sheet, int width, int height);
		Sprite(SpriteSheet *sheet, int x, int y, int size);
		Sprite(int width, int height, int colour);
		Sprite(int size, int colour);
		Sprite(int *pixels, int width, int height);
		Sprite(int *pixels, int size);

		static std::unique_ptr<Sprite> rotate(Sprite *sprite, double angle);
		static std::vector<std::unique_ptr<Sprite>> split(SpriteSheet *sheet);

		int getWidth();
		int getHeight();

	private:
		static int* rotate(int *pixels, int width, int height, double angle);
		static double rot_x(double angle, double x, double y);
		static double rot_y(double angle, double x, double y);

		void setColour(int colour);

		void load();

	protected:
		SpriteSheet *sheet;

	public:
		int SIZE;
		int *pixels;

	private:
		int x, y;
		int width;
		int height;
	};
}

#endif
