// ---
// solidTile.h
//
// Contains the class definition for a standard
// solid tile. It doesn't do anything except
// provide a platform for the player to stand on.
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
#ifndef SOLID_TILE_H
#define SOLID_TILE_H

class SolidTile : public Tile
{
	private:
		//The image of the tile:
		static sf::Image _image;

	public:
		//Loads the image:
		static bool init();

		//Initialiser:
		SolidTile(float, float);
};

#endif
