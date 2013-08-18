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
#include "level.h"
#include "tile.h"
//#include "enemy.h" //Does not currently exist
//#include "projectile.h" //Does not currently exist

//The level which contains all the objects, such
//as enemies, tiles and projectiles, that will need to be
//checked against in collision detection:
extern Level* level; 

//The static array of images:
sf::Image Banana::_images[IMAGES];

//Loads the images:
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

//Sets the score, lives and texture:
Banana::Banana(short unsigned int lives, unsigned int score)
{
	_lives = lives;
	_score = score;

	if(! _texture.loadFromImage(_images[STATIONARY]))
		throw "Failed to load texture";

	_sprite.setTexture(_texture);

	//Set the default co-ordinates (not final):
	_sprite.setPosition(400, 300);
}

//Moves the Banana in the specified direction:
void Banana::move(Direction direction, float frameTime)
{
	Collision collision = NONE;

	//If the player isn't jumping or falling, set the image:
	/*if((! _isFalling) && (! _isJumping))
	{
		if(_frameClock.getElapsedTime().asSeconds() > 0.25)
		{
			_frame++;
			if(_frame > 3)
				_frame = 1;
			
			switch(frame)
			{
				case 1: _texture.update(_images[MOVE1]); break;
				case 2: _texture.update(_images[MOVE2]); break;
				case 3: _texture.update(_images[MOVE3]); break;
			}
			_frameClock.reset();
		}
	}
	else
		_frame = 0;*/

	if(direction == DIRECTION_LEFT)
	{
		//Move left:
		_sprite.move((-X_VELOCITY * frameTime), 0);

		//Checks for a collision with a tile, and moves back if there is one:
		for(unsigned int i = 0; i < level->getTiles().size(); i++)
		{
			if(level->getTiles()[i]->isSolid())
			{
				collision = checkCollision(level->getTiles()[i]->getSprite());
				if((collision == LEFT) || (collision == TOPLEFT) ||	(collision == BOTTOMLEFT))
				{
					_sprite.move((X_VELOCITY * frameTime), 0);
					break;
				}
			}
		}
	}
	if(direction == DIRECTION_RIGHT)
	{
		//Move left:
		_sprite.move((X_VELOCITY * frameTime), 0);

		//Checks for a collision with a tile, and moves back if there is one:
		for(unsigned int i = 0; i < level->getTiles().size(); i++)
		{
			if(level->getTiles()[i]->isSolid())
			{
				collision = checkCollision(level->getTiles()[i]->getSprite());
				if((collision == RIGHT) || (collision == TOPRIGHT) || (collision == BOTTOMRIGHT))
				{
					_sprite.move((-X_VELOCITY * frameTime), 0);
					break;
				}
			}
		}
	}
}

void Banana::special(float frameTime)
{
}

void Banana::handleEvents(float frameTime)
{
	Collision collision = NONE;

	if(_isJumping)
	{
		//Moves the sprite up:
		_sprite.move(0, (-Y_VELOCITY * frameTime));

		//Adds the distance to the height jumped:
		_heightJumped += Y_VELOCITY * frameTime;

		//Checks if the max jump height has been exceeded:
		if(_heightJumped > MAX_JUMP_HEIGHT)
		{
			//If so, set the player to falling:
			setFalling(true);
			_heightJumped = 0;

			//Move back:
			_sprite.move(0, (Y_VELOCITY * frameTime));
		}
		else
		{
			//Otherwise, checks if there are any collisions:
			for(unsigned int i = 0; i < level->getTiles().size(); i++)
			{
				if(level->getTiles()[i]->isSolid())
				{
					collision = checkCollision(level->getTiles()[i]->getSprite());
					if((collision == TOP) || (collision == TOPLEFT) || (collision == TOPRIGHT))
					{
						//If so, set the player to falling:
						setFalling(true);
						_heightJumped = 0;

						//Move back:
						_sprite.move(0, (Y_VELOCITY * frameTime));

						break;
					}
				}
			}
		}
	}
	else if(_isFalling)
	{
		//Moves the sprite down:
		_sprite.move(0, (Y_VELOCITY * frameTime));

		//Checks if there are any collisions:
		for(unsigned int i = 0; i < level->getTiles().size(); i++)
		{
			if(level->getTiles()[i]->isSolid())
			{
				collision = checkCollision(level->getTiles()[i]->getSprite());
				if((collision == BOTTOM) || (collision == BOTTOMLEFT) || (collision == BOTTOMRIGHT))
				{
					//If so, the player is no longer falling:
					setFalling(false);

					//Move to the top of the tile collided with:
					float top = level->getTiles()[i]->getSprite().getGlobalBounds().top - 
					_sprite.getGlobalBounds().height;
					_sprite.setPosition(_sprite.getGlobalBounds().left, top);

					break;
				}
			}
		}	
	}
	//If the player is not jumping or falling, check if they are standing on a tile, and if not,
	//set the player to 'falling'.
	else
	{
		//Checks if there are any collisions:
		for(unsigned int i = 0; i < level->getTiles().size(); i++)
		{
			if(level->getTiles()[i]->isSolid())
			{
				collision = checkCollision(level->getTiles()[i]->getSprite());
				if((collision == BOTTOM) || (collision == BOTTOMLEFT) || (collision == BOTTOMRIGHT))
					break;
			}
		}	
		//If there are none:
		if((collision != BOTTOM) && (collision != BOTTOMLEFT) && (collision != BOTTOMRIGHT))
			setFalling(true);
	}
}

void Banana::jump()
{
	//If the character isn't falling, they're now jumping:
	if(! _isFalling)
	{
		_isJumping = true;
		//set image
	}
} 

void Banana::setFalling(bool isFalling)
{
	_isFalling = isFalling;

	if(_isFalling)
		_isJumping = false;

	//set image
}
