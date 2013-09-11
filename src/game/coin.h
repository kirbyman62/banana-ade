// ---
// coin.h
//
// Contains the class definition for the coin,
// a tile which gives the player points when
// they come into contact with it.
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
#ifndef COIN_H
#define COIN_H
#include "tile.h"

class Coin : public Tile
{
	private:
		//The coin's image:
		static sf::Image _image;	

		//Checks if the coin has already been acquired:
		bool _isAcq;

	public:
		//Loads the image:
		static bool init();

		//Constructor:
		Coin(float, float);

		//Event handlers:
		void handleEvents() { }
		void handleEvents(PlayableCharacter&);
};

#endif
