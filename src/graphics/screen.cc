#include "screen.h"
#include "sprite_sheet.h"

namespace graphics
{
	Screen::Screen(int width, int height)
		: width(width), height(height), xOffset(0), yOffset(0)
	{
		pixels = new int[width * height];
	}

	Screen::~Screen() { delete[] pixels; }

	void Screen::clear(int color)
	{
		unsigned s = width * height;
		for (unsigned i=0; i<s; ++i) pixels[i] = color;
	}

	void Screen::render(int const *spixels)
	{
		for (int y=0; y<height; ++y)
		{
			for (int x=0; x<width; ++x)
			{
				pixels[x + y * width] = spixels[x + y * width];
			}
		}
	}

	void Screen::render(SpriteSheet *sheet, int xp, int yp, bool fixed)
	{
		if (fixed) { xp -= xOffset; yp -= yOffset; }

		int w_s = sheet->getWidth();
		int h_s = sheet->getHeight();
		int *px = sheet->pixels;

		for (int y=0; y<h_s; ++y)
		{
			int yo = yp + y;
			if (yo < 0 || yo > height) continue;
			for (int x=0; x<w_s; ++x)
			{
				int xo = xp + x;
				if (xo < 0 || xo > width) continue;
				pixels[xo + yo * width] = px[x + y * w_s];
			}
		}
	}

	void Screen::render(Sprite *sprite, int xp, int yp, bool fixed)
	{
		if (fixed) { xp -= xOffset; yp -= yOffset; }

		int w_s = sprite->SIZE;
		int h_s = sprite->SIZE;
		int *px = sprite->pixels;

		for (int y=0; y<h_s; ++y)
		{
			int yo = yp + y;
			if (yo < 0 || yo > height) continue;
			for (int x=0; x<w_s; ++x)
			{
				int xo = xp + x;
				if (xo < 0 || xo > width) continue;
				pixels[xo + yo * width] = px[x + y * w_s];
			}
		}
	}

	void Screen::drawpoint(int x, int y, int color)
	{
		if (x < 0 || x > width || y < 0 || y > height) return;
		pixels[x + y * width] = color;
	}

	void Screen::drawRect(int xp, int yp, int width, int height, int color, bool fixed)
	{
		if (fixed) { xp -= xOffset; yp -= yOffset; }

		for (int x=xp; x<xp+width; ++x)
		{
			if (x<0 || x>=this->width || yp>=this->height) continue;
			if (yp>0) pixels[x + yp * this->width] = color;
			if (yp+height>=this->height) continue;
			if (yp+height>0) pixels[x + (yp + height) * this->width] = color;
		}

		for (int y=yp; y<=yp+height; ++y)
		{
			if (xp>=this->width || y<0 || y>=this->height) continue;
			if (xp>0) pixels[xp + y * this->width] = color;
			if (xp+width>=this->width) continue;
			if (xp+width>0) pixels[(xp+width) + y * this->width] = color;
		}
	}

	void Screen::fillRect(int xp, int yp, int width, int height, int color, bool fixed)
	{
		if (fixed) { xp -= xOffset; yp -= yOffset; }

		for (int y=0; y<height; ++y)
		{
			int yo = yp + y;
			if (yo<0 || yo>this->height) continue;
			for (int x=0; x<width; ++x)
			{
				int xo = xp + x;
				if (xo<0 || xo>this->width) continue;
				pixels[xo + yo * this->width] = color;
			}
		}
	}

	void Screen::setOffset(int x, int y) { xOffset = x; yOffset = y; }
}
