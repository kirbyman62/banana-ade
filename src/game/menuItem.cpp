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
#include "menuItem.h"

sf::Font MenuItem::_font;

bool MenuItem::init()
{
	//Attempts to load the font:
	if(! _font.loadFromFile(MENU_FONT))
		return false;

	return true;
}

MenuItem::MenuItem(std::string text, void (*func)())
{
	//Initialises the text:
	_text.setFont(_font);
	_text.setColor(sf::Color::Black);
	_text.setCharacterSize(72);
	_text.setString(text);

	_func = func;
}

void MenuItem::execute()
{
	(*_func)();
}

void MenuItem::highlight(bool highlight)
{
	if(highlight)
		_text.setColor(sf::Color::Red);
	else
		_text.setColor(sf::Color::Black);
}

void MenuItem::position(float x, float y)
{
	_text.setPosition(x, y);
}

sf::Text MenuItem::getText()
{
	return _text;
}
