#include "sprite.h"
#include "sprite_sheet.h"

#include <cmath>
#include <cfenv>

#pragma STDC FENV_ACCESS ON
constexpr double pi = std::acos(-1);

namespace graphics
{
	Sprite::Sprite(SpriteSheet *sheet, int width, int height)
		: SIZE(width == height ? width : -1)
		, width(width), height(height)
		, sheet(sheet)
	{
	}

	Sprite::Sprite(SpriteSheet *sheet, int x, int y, int size)
		: SIZE(size)
		, width(size), height(size)
		, x(x * size), y(y * size)
		, sheet(sheet)
	{
		pixels = new int[SIZE * SIZE];
		load();
	}

	Sprite::Sprite(int width, int height, int colour)
		: SIZE(-1)
		, width(width), height(height)
	{
		pixels = new int[width * height];
		setColour(colour);
	}

	Sprite::Sprite(int size, int colour)
		: SIZE(size)
		, width(size), height(size)
	{
		pixels = new int[SIZE * SIZE];
		setColour(colour);
	}

	Sprite::Sprite(int *pixels, int width, int height)
		: SIZE(width == height ? width : -1)
		, width(width), height(height)
	{
		std::size_t xxx = width * height;
		pixels = new int[xxx];
		for (int i=0; i<xxx; ++i)
			this->pixels[i] = pixels[i];
	}

	Sprite::Sprite(int *pixels, int size)
		: SIZE(size)
		, width(size), height(size)
	{
		this->pixels = pixels;
	}

	std::unique_ptr<Sprite> Sprite::rotate(Sprite *sprite, double angle)
	{
		return std::make_unique<Sprite>(
			rotate(sprite->pixels, sprite->width, sprite->height, angle),
					sprite->width, sprite->height);
	}

	std::vector<std::unique_ptr<Sprite>> split(SpriteSheet *sheet)
	{
		int w = sheet->getWidth();
		int h = sheet->getHeight();
		int sp_w = sheet->SPRITE_WIDTH;
		int sp_h = sheet->SPRITE_HEIGHT;
		int *sheet_pixel = sheet->getPixels();

		int amount = (w * h) / (sp_w * sp_h);

		std::vector<std::unique_ptr<Sprite>> sprites(amount);
		int current = 0;
		int *pixels = new int[sp_w * sp_h];
		for (int yp=0; yp<h / sp_h; ++yp)
		{
			for (int xp=0; xp<w / sp_w; ++xp)
			{
				for (int y=0; y<sp_h; ++y)
				{
					for (int x=0; x<sp_w; ++x)
					{
						int xo = x + xp * sp_w;
						int yo = y + yp * sp_h;
						pixels[x + y * sp_w] = sheet_pixel[xo + yo * w];
					}
				}
				sprites[current++].reset(new Sprite(pixels, sp_w, sp_h));
			}
		}

		return std::move(sprites);
	}

	int Sprite::getWidth()
	{
		return width;
	}

	int Sprite::getHeight()
	{
		return height;
	}

	int* Sprite::rotate(int *pixels, int width, int height, double angle)
	{
		int *result = new int[width*height];

		double nx_x = rot_x(-angle, 1.0, 0.0);
		double nx_y = rot_y(-angle, 1.0, 0.0);
		double ny_x = rot_x(-angle, 0.0, 1.0);
		double ny_y = rot_y(-angle, 0.0, 1.0);

		double x0 = rot_x(-angle, -width / 2.0, -height / 2.0) + width / 2.0;
		double y0 = rot_y(-angle, -width / 2.0, -height / 2.0) + height / 2.0;

		for (int y=0; y<height; ++y)
		{
			double x1 = x0;
			double y1 = y0;
			for (int x=0; x<width; ++x)
			{
				int xx = static_cast<int>(x1);
				int yy = static_cast<int>(y1);
				int col = 0;
				if (xx < 0 || xx >= width || yy < 0 || yy >= height) col = 0xff00ff;
				else col = pixels[xx + yy * width];
				result[x + y * width] = col;
				x1 += nx_x;
				y1 += nx_y;
			}
			x0 += ny_x;
			y0 += ny_y;
		}
		return result;
	}

	double Sprite::rot_x(double angle, double x, double y)
	{
		double cos = std::cos(angle - pi / 2);
		double sin = std::sin(angle - pi / 2);
		return x * cos + y * -sin;
	}

	double Sprite::rot_y(double angle, double x, double y)
	{
		double cos = std::cos(angle - pi / 2);
		double sin = std::sin(angle - pi / 2);
		return x * sin + y * cos;
	}

	void Sprite::setColour(int colour)
	{
		std::size_t xxx = width * height;
		for (int i=0; i<xxx; ++i) pixels[i] = colour;
	}

	void Sprite::load()
	{
		for (int y=0; y<height; ++y)
			for (int x=0; x<width; ++x)
				pixels[x + y * width] = 
					sheet->pixels[(x + this->x) + (y + this->y) * sheet->SPRITE_WIDTH];
	}
}
