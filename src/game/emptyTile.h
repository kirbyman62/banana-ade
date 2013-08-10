// ---
// emptyTile.h
//
// Contains the class definition for an
// empty tile, perhaps the most common
// tile. It is completely transparent and
// is not solid.
// ---

/*
 *  This file is part of Banana-ade.
 *  Copyright (C) 2013 Kieran Hancock & Alex Kerr
 *
 *  Banana-ade is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Banana-ade is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Banana-ade.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef EMPTY_TILE_H
#define EMPTY_TILE_H
#include "tile.h"

class EmptyTile : public Tile
{
	private:
		//The image of the tile:
		static sf::Image _image;

	public:
		//Loads the image:
		static bool init();

		//Constructor:
		EmptyTile(float, float);
};

#endif
