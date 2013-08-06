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
#include "emptyTile.h"

sf::Image emptyTile::_image;

bool emptyTile::init()
{
	//Since the image is just a transparent square we don't have to 
	//bother with loading it from a file, we can just make it with SFML:
	_image.create(TILE_WIDTH, TILE_HEIGHT, sf::Color::Transparent);

	//Creating an image this way is a void function, so we have to return
	//true because apparently it can't fail:
	return true;
}

EmptyTile::EmptyTile(float x, float y)
{
	//Loads the texture from the image:
	if(! _texture.loadFromImage(_image))
		throw "Failed to load texture";

	//Sets the solid property:
	_isSolid = false;

	//Sets the sprite, and thus the tile's, postition:
	_sprite.setPosition(x, y);
}
