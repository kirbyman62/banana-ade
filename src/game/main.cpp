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
#include <sstream>
#include <SFML/Graphics.hpp>

#include "character.h"
#include "playableCharacter.h"
#include "banana.h"

#include "level.h"
#include "tiles.h"

#ifdef _WIN32
	const std::string fontPath = "assets\\fonts\\Full-Dece-Sans-1.0.ttf";
#else
	const std::string fontPath = "assets/fonts/Full-Dece-Sans-1.0.ttf";
#endif

float getAverageFPS(float);

//The current level, global so the player can get data from it:
Level* level = NULL;

int main()
{
	//Attempts to load the images:
	if(! Tiles::init())
		return -1;

	if(! Banana::init())
		return -1;

	//Loads the font:
	sf::Font font;
	if(! font.loadFromFile(fontPath))
		return -1;

	//Creates a window:
	sf::RenderWindow window(sf::VideoMode(800, 600), "Banana-ade");

	//Creates a view of the level:
	sf::View view = window.getDefaultView();

	//The player:
	PlayableCharacter* player = new Banana(3, 0);
			
	//Moves the view to the player:
	float centreX = player->getSprite().getGlobalBounds().left;
	float centreY = (window.getSize().y / 2);
	view.setCenter(centreX, centreY);
	window.setView(view);

	//Creates the text:
	sf::Text text;
	text.setFont(font);
	text.setColor(sf::Color::Black);
	text.setCharacterSize(16);
	text.setString("Average FPS:");

	//Position the text:
	float textX = (view.getCenter().x + (view.getSize().x / 2)) - 200;
	float textY = (view.getCenter().y - (view.getSize().y / 2)) + 35;	
	text.setPosition(textX, textY);

	//Loads the level:
	try
	{
		level = new Level("assets/levels/test02.blv");
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

	//Measures the framerate:
	sf::Clock fps;

	//The time of one frame, used for movement calculations:
	float frameTime = 0.016;

	//The main loop:
	while(window.isOpen())
	{
		//Check the events:
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();

			//Handles the window being resized:
			if(event.type == sf::Event::Resized)
			{
				//Resize the view:
				view.setSize(event.size.width, event.size.height);
				window.setView(view);

				//Position the text:
				textX = (view.getCenter().x + (view.getSize().x / 2)) - 200;
				textY = (view.getCenter().y - (view.getSize().y / 2)) + 35;
				text.setPosition(textX, textY);
			}
		}

		player->handleEvents(frameTime);

		//Checks if the left key is pressed:
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			//Move the player left:
			player->move(DIRECTION_LEFT, frameTime);

			//Moves the view to the player:
			float centreX = player->getSprite().getGlobalBounds().left;
			float centreY = (window.getSize().y / 2);
			view.setCenter(centreX, centreY);
			window.setView(view);

			//Position the text:
			textX = (view.getCenter().x + (view.getSize().x / 2)) - 200;
			textY = (view.getCenter().y - (view.getSize().y / 2)) + 35;
			text.setPosition(textX, textY);
		}

		//Checks if the right key is pressed:
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			//Move the player right:
			player->move(DIRECTION_RIGHT, frameTime);

			//Moves the view to the player:
			float centreX = player->getSprite().getGlobalBounds().left;
			float centreY = (window.getSize().y / 2);
			view.setCenter(centreX, centreY);
			window.setView(view);

			//Position the text:
			textX = (view.getCenter().x + (view.getSize().x / 2)) - 200;
			textY = (view.getCenter().y - (view.getSize().y / 2)) + 35;
			text.setPosition(textX, textY);
		}

		//Checks if the space bar is pressed:
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			player->jump();

		//Clear the screen white:
		window.clear(sf::Color::White);

		//Calculate the FPS:
		float fps_f = 1 / frameTime;

		//Write the FPS:
		if(getAverageFPS(fps_f) != -1)
		{
			std::stringstream fps_sstream;
			fps_sstream << "Average FPS: " << fps_f;
			text.setString(fps_sstream.str());
		}

		//Draw the text:
		window.draw(text);

		//Draw the player:
		window.draw(player->getSprite());

		//Draw the tiles:
		for(unsigned int i = 0; i < level->getTiles().size(); i++)
			window.draw(level->getTiles()[i]->getSprite());

		//Display the window:
		window.display();

		//Calculate the frame rate:
		frameTime = fps.restart().asSeconds();
	}
	delete level;
	delete player;
	return 0;
}

float getAverageFPS(float time)
{
	static float times[150];
	static int i = 0;

	if(i < 150)
	{
		times[i++] = time;
		return -1;
	}
	else
	{
		float total = 0;
		for(int j = 0; j < 150; j++)
			total += times[j];
		i = 0;
		return total / 150;
	}
}
