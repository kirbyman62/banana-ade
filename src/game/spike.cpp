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
#include "spike.h"

sf::Image Spike::_image;

//The path to the image:
#ifdef _WIN32
	const std::string image = "assets\\tiles\\spikes.png";
#else
	const std::string image = "assets/tiles/spikes.png";
#endif

bool Spike::init()
{
	//Loads the image from the file:
	if(! _image.loadFromFile(image))
		return false;

	//Remove the green for transparency:
	_image.createMaskFromColor(COLOUR_KEY);

	return true;
}

Spike::Spike(float x, float y)
{
	//Loads the texture from the image:
	if(! _texture.loadFromImage(_image))
		throw "Failed to load texture";

	_sprite.setTexture(_texture);

	//Sets the solid property:
	_isSolid = false;

	//Sets the sprite, and thus the tile's, postition:
	_sprite.setPosition(x, y);
}

void Spike::handleEvents(PlayableCharacter& player)
{
	if(player.checkCollision(_sprite) != NONE)
		player.kill();
}