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
		//Constructor:
		PlayableCharacter(short unsigned int, unsigned int);

		//Handles non-keyboard events, like gravity:
		virtual void handleEvents() = 0;

		//Handles keyboard events:
		virtual void handleKeyboardEvents(sf::Window&) = 0;

		//Makes the character jump, or fall if they've jumped
		//too high:
		virtual void jump(float) = 0;

		//Setters:
		virtual void setFalling(bool) = 0;

		//Getters:
		short unsigned int getLives();
		unsigned int getScore();
		bool isJumping();
		bool isFalling();
};

#endif
