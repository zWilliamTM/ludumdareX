#pragma once
#ifndef _SCREEN_H
#define _SCREEN_H

namespace graphics
{
	class Screen
	{
	public:
		Screen(int width, int height);
		~Screen();

		void clear(int color = 0);

		// renderable
		void render(int const *spixels);
		

		// shape
		void drawpoint(int x, int y, int color = 0xFFFFFF);
		void drawRect(int xp, int yp, int width, int height, int color, bool fixed);
		void fillRect(int xp, int yp, int width, int height, int color, bool fixed);

		void setOffset(int x, int y);

		int *pixels;
		int width;
		int height;
		int xOffset, yOffset;
	};
}



#endif
