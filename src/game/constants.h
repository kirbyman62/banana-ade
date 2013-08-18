// ---
// constants.h
//
// Contains various constants used
// throughout the program.
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

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <SFML/Graphics.hpp>

//The background colour to set transparent:
const int RED = 24;
const int GREEN = 111;
const int BLUE = 17;
const sf::Color COLOUR_KEY = sf::Color(RED, GREEN, BLUE);

//The collision types:
enum Collision
{
	TOPLEFT,
	TOPRIGHT,
	BOTTOMLEFT,
	BOTTOMRIGHT,
	LEFT,
	RIGHT,
	TOP,
	BOTTOM,
	NONE,
};

//Movement directions:
enum Direction
{
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
};

#endif
