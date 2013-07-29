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

//The constants specific to 'Banana':
namespace Bn
{
	//The number of images to load:
	const int IMAGES = 1;

	//If compiling on Windows, use backslashes for the file path:
	#ifdef _WIN32
		const std::string STATIONARY_IMAGE = "assets\\banana.png";
	#else
		const std::string STATIONARY_IMAGE = "assets/banana.png";
	#endif

	//The various labels for the images:
	enum
	{
		STATIONARY
	};

	//The maximum jump height:
	const float MAX_JUMP_HEIGHT = 100.0;

	//The X and Y velocity:
	const float X_VELOCITY = 80.0;
	const float Y_VECLOITY = 100.0;
}

class Banana : public PlayableCharacter
{
	private:
		//The images and texture:
		static sf::Image _images[Bn::IMAGES];
		sf::Texture _texture;

	public:
		//Loads the images:
		static bool init();

		//Handles non-keyboard events, like gravity:
		void handleEvents();

		//Handles keyboard events:
		void handleKeyboardEvents(sf::Window&);

		//Makes the character jump, or fall if they've jumped
		//too high:
		void jump(float) = 0;

		//Setters:
		void setFalling(bool) = 0;
};

#endif
