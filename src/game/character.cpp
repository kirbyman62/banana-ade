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
#include "character.h"

//Returns the sprite (check the header, is this overkill?)
sf::Sprite& Character::getSprite()
{
	return _sprite;
}

//Checks for a collision between the character and the passed sprite:
bool Character::checkCollision(sf::Sprite& target) const
{
	return _sprite.getGlobalBounds().intersects(target.getGlobalBounds());	
}

//Flips the character's sprite to face the passed direction:
void Character::flip(Direction d)
{
	sf::IntRect rect = _sprite.getTextureRect();
	if(d != _direction)
	{
		rect.left += rect.width;
		rect.width = -rect.width;
	}
	_sprite.setTextureRect(rect);
	_direction = d;
}
