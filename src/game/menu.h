// ---
// menu.h
//
// Includes the class definition for a menu, 
// a collection of MenuItems.
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
#ifndef MENU_H
#define MENU_H
#include "menuItem.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

//If compiling on Windows, use backslashes for the file path:
#ifdef _WIN32
	const std::string IMAGE = "assets\\menu.png";
#else
	const std::string IMAGE = "assets/menu.png";
#endif

class Menu
{
	private:
		//The image used by the menu:
		static sf::Image _image;

		//The texture:
		sf::Texture _texture;

		//The sprite:
		sf::Sprite _sprite;

		//The menu items:
		std::vector <MenuItem*> _items;

		//The currently selected menu item:
		unsigned short int _selection;

	public:
		//Loads the images:
		static bool init();

		//Constructor:
		Menu(std::vector <MenuItem*>&);

		//Destructor:
		~Menu();

		//Moves the selection up or down:
		void moveSelection(Direction);

		//Executes the selected option:
		void execute();

		//Reposition:
		void position(sf::View&);

		//Getters:
		sf::Sprite getSprite();
		std::vector <MenuItem*>& getItems();

		//Moves the menu back a stage:
		static void back();
};

#endif
