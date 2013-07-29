// ---
// tile.h
//
// Contains the class definition for a 'tile',
// a block which makes up a certain gameplay
// element (standard block, coin, spring etc).
// Levels are made from placing these tiles
// into a sequence.
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

#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>
#include "playableCharacter.h"

class Tile
{
	private:
		//The texture of the tile:
		sf::Texture _texture;

		//The tile's sprite:
		sf::Sprite _sprite;

		//If the tile is 'solid' or not.
		//The player cannot pass through
		//a 'solid' tile:
		bool _isSolid;

	public:
		//Gets the sprite:
		sf::Sprite& getSprite();

		//Handle any events that may occur.
		//Includes overloaded functions should
		//the tile require information on the
		//player, or the screen:
		virtual void handleEvents() = 0;
		virtual void handleEvents(sf::Window&) = 0;
		virtual void handleEvents(playableCharacter&) = 0;
};

#endif
