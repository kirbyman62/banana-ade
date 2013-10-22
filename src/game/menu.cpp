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
#include "menu.h"

sf::Image Menu::_image;

bool Menu::init()
{
	//Loads the files:
	if(! _image.loadFromFile(IMAGE))
		return false;

	//Sets the colour key transparent on all loaded images:
	_image.createMaskFromColor(COLOUR_KEY);

	return true;
}

Menu::Menu(std::vector <MenuItem*>& items)
{
	_items = items;
	_selection = 0;
}

Menu::~Menu()
{
	//Deletes the menu items:
	for(unsigned int i = 0; i < _items.size(); i++)
		delete _items[i];
}

void Menu::moveSelection(Direction d)
{
	//Moves the selection up or down if possible:
	switch(d)
	{
		case DIRECTION_UP:   if(_selection > 0) _selection--; break;
		case DIRECTION_DOWN: if(_selection < _items.size()) _selection++; break;
		default: throw "Error!"; break;
	}
}

void Menu::execute()
{
	_items[_selection]->execute();
}

sf::Sprite Menu::getSprite()
{
	return _sprite;
}

std::vector <MenuItem*>& Menu::getItems()
{
	//Sets the highlight:
	for(unsigned int i = 0; i < _items.size(); i++)
	{
		if(i == _selection)
			_items[i]->highlight(true);
		else
			_items[i]->highlight(false);
	}

	return _items;
}

void Menu::back()
{
	menuStack.pop_back();
}
