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
#include "coin.h"
#include <string>

sf::Image Coin::_image;

//The path to the image:
#ifdef _WIN32
	const std::string image = "assets\\tiles\\coin.png";
#else
	const std::string image = "assets/tiles/coin.png";
#endif 

bool Coin::init()
{
	//Loads the image from the file:
	if(! _image.loadFromFile(image))
		return false;	

	//Remove the green for transparency:
	_image.createMaskFromColor(COLOUR_KEY);

	return true;
}

Coin::Coin(float x, float y)
{
	//Loads the texture from the image:
	if(! _texture.loadFromImage(_image))
		throw "Failed to load texture";

	_sprite.setTexture(_texture);

	//Sets the solid property:
	_isSolid = false;

	//Sets the sprite, and thus the tile's, postition:
	_sprite.setPosition(x, y);

	//The coin has not yet been acquired:
	_isAcq = false;
}

void Coin::handleEvents(PlayableCharacter& player)
{
	//If the player collides with the coin:
	if((player.checkCollision(_sprite)) && (! _isAcq))
	{
		//Increases the player's score:
		player.addScore(100);

		//Create a transparent image, as the coin has now dissapeared:
		_image.create(TILE_WIDTH, TILE_HEIGHT, sf::Color::Transparent);
		_texture.update(_image);

		//The coin is now acquired:
		_isAcq = true;
	}
}
