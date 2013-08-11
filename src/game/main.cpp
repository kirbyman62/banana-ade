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
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "level.h"
#include "tiles.h"

int main()
{
	//Attempts to load the images for the tiles:
	if(! EmptyTile::init())
		return -1;

	if(! SolidTile::init())
		return -1;

	//Creates a window:
	sf::RenderWindow window(sf::VideoMode(800, 600), "Banana-ade");

	//Creates a view of the level:
	sf::View view = window.getDefaultView();

	Level* level = NULL;

	//Loads the level:
	try
	{
		level = new Level("assets/levels/test01.blv");
	}
	catch(const char* e)
	{
		std::cerr << e << std::endl;
		return -1;
	}

	//Output the level's metadata:
	std::cout << "Name: " << level->getName() << std::endl;
	std::cout << "Author: " << level->getAuthor() << std::endl;

	sf::Event event;

	//The main loop:
	while(window.isOpen())
	{
		//Check the events:
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();

			//Resizes the view if the window is resized:
			if(event.type == sf::Event::Resized)
			{
				view.setSize(event.size.width, event.size.height);
				window.setView(view);
			}
		}

		//Checks if the left key is pressed:
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			//Moves the view left:
			view.move(-3, 0);
			window.setView(view);
		}

		//Checks if the right key is pressed:
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			//Moves the view right:
			view.move(3, 0);
			window.setView(view);
		}

		//Clear the screen white:
		window.clear(sf::Color::White);

		//Draw the tiles:
		for(unsigned int i = 0; i < level->getTiles().size(); i++)
			window.draw(level->getTiles()[i]->getSprite());

		//Display the window:
		window.display();
	}
	delete level;
	return 0;
}
