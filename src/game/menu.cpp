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

//The margin around the background:
const unsigned int MARGIN = 10;

//The spacing between the text items:
const unsigned int SPACING = 3;

//The menu stack:
extern std::vector <Menu*> menuStack;

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

	_texture.loadFromImage(_image);
	_sprite.setTexture(_texture);
	
	//Gets the required data to calculate the transformation.
	//This assumes all the MenuItems have the same character size:
	sf::FloatRect size = _sprite.getGlobalBounds();
	_sprite.setOrigin((size.height / 2), (size.width / 2));
	unsigned int characterSize = _items[0]->getText().getCharacterSize();
	unsigned int numberOfItems = _items.size();
	unsigned int longestItem = 0;
	for(unsigned int i = 0; i < _items.size(); i++)
		if(_items[i]->getText().getString().getSize() > longestItem)
			longestItem = _items[i]->getText().getString().getSize();

	//Calculates the required scale factor:
	unsigned int height = ((2 * MARGIN) + (numberOfItems * (characterSize + SPACING)));
	unsigned int width = ((2 * MARGIN) + (longestItem * characterSize));
	float scaleFactorX = width / size.height;
	float scaleFactorY = height / size.width;

	_sprite.scale(scaleFactorX, scaleFactorY);

	//Sets the position of the MenuItems:
	float x = _sprite.getGlobalBounds().left + MARGIN;
	float y = _sprite.getGlobalBounds().top + MARGIN;
	for(unsigned int i = 0; i < _items.size(); i++)
	{
		_items[i]->position(x, y);
		y += (SPACING + characterSize);
	}
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
		case DIRECTION_DOWN: if(_selection < (_items.size() - 1)) _selection++; break;
		default: throw "Error!"; break;
	}
}

void Menu::execute()
{
	_items[_selection]->execute();
}

void Menu::position(sf::View& view)
{
	//Positions the background:
	_sprite.setPosition(view.getCenter());

	unsigned int characterSize = _items[0]->getText().getCharacterSize();

	//Sets the position of the MenuItems:
	unsigned int x = _sprite.getGlobalBounds().left + MARGIN;
	unsigned int y = _sprite.getGlobalBounds().top + MARGIN;
	for(unsigned int i = 0; i < _items.size(); i++)
	{
		_items[i]->position(x, y);
		y += (SPACING + characterSize);
	}
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
