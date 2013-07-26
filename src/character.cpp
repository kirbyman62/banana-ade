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
Collision Character::checkCollision(sf::Sprite& target) const
{
	//Gets the sides of the character:
	//These are represented as 1 pixel wide rectangles:
	sf::FloatRect A = _sprite.getGlobalBounds();
	sf::FloatRect topA(A.left, A.top, A.width, 1);
	sf::FloatRect bottomA(A.left, (A.top + A.height), A.width, 1);
	sf::FloatRect leftA(A.left, A.top, 1, A.height);
	sf::FloatRect rightA((A.left + A.width), A.top, 1, A.height);

	//The rectangle of the target sprite, we will check to see
	//if the character is inside this rectangle:
	sf::FloatRect B = target.getGlobalBounds();

	//Checks for collisions in the corners:
	//Top left:
	if((B.intersects(topA)) && (B.intersects(leftA)))
		return COLLISION_TOPLEFT;

	//Top right:
	if((B.intersects(topA)) && (B.intersects(rightA)))
		return COLLISION_TOPRIGHT;

	//Bottom left:
	if((B.intersects(bottomA)) && (B.intersects(leftA)))
		return COLLISION_BOTTOMLEFT;

	//Bottom right:
	if((B.intersects(bottomA)) && (B.intersects(rightA)))
		return COLLISION_BOTTOMRIGHT;

	//Otherwise, it is a single side:
	//Top:
	if(B.intersects(topA))
		return COLLISION_TOP;

	//Bottom:
	if(B.intersects(bottomA))
		return COLLISION_BOTTOM;
	
	//Left:
	if(B.intersects(leftA))
		return COLLISION_LEFT;

	//Right:
	if(B.intersects(rightA))
		return COLLISION_LEFT;

	//Otherwise, there is no collision:
	return COLLISION_NONE;
}

//Checks for a collision between the character and the passed window:
Collision Character::checkCollision(sf::Window& window) const
{	
	//Gets the sides of the character:
	float topA, bottomA, leftA, rightA;
	topA = _sprite.getGlobalBounds().top;
	bottomA = _sprite.getGlobalBounds().height + topA;
	leftA = _sprite.getGlobalBounds().left;
	rightA = _sprite.getGlobalBounds().width + leftA;

	//Top:
	if(topA < 0)
		return COLLISION_TOP;

	//Bottom:
	if(bottomA > window.getSize().y)
		return COLLISION_BOTTOM;

	//Left:
	if(leftA < 0) 
		return COLLISION_LEFT;

	//Right:
	if(rightA > window.getSize().x)
		return COLLISION_RIGHT;

	//Otherwise there is no collision:
	return COLLISION_NONE;
}
