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
#include "banana.h"
using namespace Bn;

//The static array of images:
sf::Image Banana::_images[IMAGES];

bool Banana::init()
{
	//Loads the files:
	if(! _images[STATIONARY].loadFromFile(STATIONARY_IMAGE))
		return false;

	//Sets the colour key transparent on all loaded images:
	for(int i = 0; i < IMAGES; i++)
		_images[i].createMaskFromColor(COLOUR_KEY);

	return true;
}

void Banana::handleEvents()
{
	//stuff
}

void Banana::handleKeyboardEvents(sf::Window& window)
{
	//stuff
}

void Banana::jump(float height)
{
	_heightJumped += height;
	_isJumping = true;
	if(_heightJumped > MAX_JUMP_HEIGHT)
	{
		this->setFalling(true);
		_isJumping = false;
		_heightJumped = 0;
	}
} 

void Banana::setFalling(bool isFalling)
{
	_isFalling = isFalling;
	
}
