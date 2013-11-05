// ---
//
// menuItem.h
//
// Contains the class definition for a menu item,
// an sf::Text that does something when selected.
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
#ifndef MENU_ITEM_H
#define MENU_ITEM_H
#include <SFML/Graphics.hpp>
#include <string>
#include "constants.h"

const std::string MENU_FONT = FULL_DECE_SANS;

class MenuItem
{
	private:
		//The text that gets drawn to the screen:
		sf::Text _text;

		//The font used:
		static sf::Font _font;

		//The function executed when the item is selected:
		void (*_func)();

	public:
		//Loads the font:
		static bool init();

		//Constructor:
		MenuItem(std::string, void (*func)());

		//Executes the function:
		void execute();

		//Sets the text highlight:
		void highlight(bool);

		//Positions the text:
		void position(float, float);

		//Getters:
		sf::Text getText();
};

#endif
