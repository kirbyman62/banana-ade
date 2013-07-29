// ---
// character.h
//
// Contains the class definition for a character, the
// base class for all 'characters', meaning:
// * Playable characters
// * NPCs
// * Enemies
// * Bosses
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

#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>

//The background colour to set transparent:
const int RED = 0;
const int GREEN = 0;
const int BLUE = 0;
const sf::Color COLOUR_KEY = sf::Color(RED, GREEN, BLUE);

//The collision types:
enum Collision
{
	COLLISION_TOPLEFT,
	COLLISION_TOPRIGHT,
	COLLISION_BOTTOMLEFT,
	COLLISION_BOTTOMRIGHT,
	COLLISION_LEFT,
	COLLISION_RIGHT,
	COLLISION_TOP,
	COLLISION_BOTTOM,
	COLLISION_NONE,
};

//Movement directions:
enum Direction
{
	LEFT,
	RIGHT,
};

class Character
{
	protected:
		//The sprite:
		sf::Sprite _sprite;

		//The animation frame and the timer:
		int _frame;
		sf::Clock _frameClock;

		//The direction the character is facing:
		Direction _direction;
	public:
		//Getters:
		//(Is giving full access to the sprite too much?)
		//(Perhaps just specific setters/getters for aspects we need)
		sf::Sprite& getSprite();

		//Checks for a collision with the given sprite or window:
		Collision checkCollision(sf::Sprite&) const;
		Collision checkCollision(sf::Window&) const;
};

#endif
