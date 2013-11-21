// ---
// banana.h
//
// Contains the class definition for the 'banana'
// character. The characters attributes are:
// * Fast movement speed
// * Weak attack power
// * [SPECIAL]: High Jump
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

#ifndef BANANA_H
#define BANANA_H
#include "playableCharacter.h"
#include <string>

//The number of images to load:
const int IMAGES = 5;

//If compiling on Windows, use backslashes for the file path:
#ifdef _WIN32
	const std::string STATIONARY_IMAGE = "assets\\test-stationary.png";
	const std::string MOVE1_IMAGE = "assets\\test-move1.png";
	const std::string MOVE2_IMAGE = "assets\\test-move2.png";
	const std::string MOVE3_IMAGE = "assets\\test-move3.png";
	const std::string JUMP_IMAGE = "assets\\test-jump.png";
#else
	const std::string STATIONARY_IMAGE = "assets/test-stationary.png";
	const std::string MOVE1_IMAGE = "assets/test-move1.png";
	const std::string MOVE2_IMAGE = "assets/test-move2.png";
	const std::string MOVE3_IMAGE = "assets/test-move3.png";
	const std::string JUMP_IMAGE = "assets/test-jump.png";
#endif

//The various labels for the images:
enum
{
	STATIONARY,
	MOVE1,
	MOVE2,
	MOVE3,
	JUMP,
};

//The maximum jump height:
const float MAX_JUMP_HEIGHT = 100.0;

//The X and Y velocity:
const float X_VELOCITY = 130.0;
const float Y_VELOCITY = 150.0;

class Banana : public PlayableCharacter
{
	private:
		//The images and texture:
		static sf::Image _images[IMAGES];

	public:
		//Loads the images:
		static bool init();

		//The constructor:
		Banana(short unsigned int, unsigned int);

		//Moves the player in the specified direction,
		//factoring in collisions with tiles, enemies and 
		//projectiles:
		void move(Direction, float);

		//Sets the stationary image:
		void stationary();

		//Use the character's 'special' move:
		void special(float);

		//Handles all events that require no player interaction:
		void handleEvents(float);

		//Setters:
		void jump();
		void setFalling(bool);
};

#endif
