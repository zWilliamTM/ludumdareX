#pragma once
#ifndef _TILE_COORDINATE_H
#define _TILE_COORDINATE_H

namespace level
{
	class TileCoordinate
	{
		const int TILE_SIZE = 16;
	public:
		TileCoordinate(int x, int y) : x(x * TILE_SIZE), y(y * TILE_SIZE) { }

		int x;
		int y;
	};
}

#endif
