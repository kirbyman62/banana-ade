// ---
// playableCharacter.h
//
// Contains the class definiton for a playable
// character, the character the player controls
// during the game.
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

#ifndef PLAYABLE_CHARACTER_H
#define PLAYABLE_CHARACTER_H
#include "character.h"

class PlayableCharacter : public Character
{
	protected:
		//The texture:
		sf::Texture _texture;

		//The lives remaining:
		short unsigned int _lives;

		//The current score:
		unsigned int _score;		

		//The height jumped:
		float _heightJumped;

		//If the character is jumping, or falling:
		bool _isJumping;
		bool _isFalling;

		//The timer on the character's 'special',
		//so it has a cooldown period so it can't
		//be spammed over and over.
		sf::Clock _specialClock;

	public:
		//Virtual destructor:
		virtual ~PlayableCharacter() { }

		//Moves the player in the specified direction,
		//factoring in collisions with tiles, enemies and 
		//projectiles:
		virtual void move(Direction, float) = 0;

		//Use the character's 'special' move:
		virtual void special(float) = 0;

		//Subtracts a life:
		void kill();

		//Adds to score:
		void addScore(unsigned int);

		//Setters:
		virtual void setFalling(bool) = 0;
		virtual void jump() = 0;

		//Getters:
		short unsigned int getLives();
		unsigned int getScore();
		bool isJumping();
		bool isFalling();
};

#endif
