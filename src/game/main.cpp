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
#include <vector>
#include <SFML/Graphics.hpp>

#include "character.h"
#include "playableCharacter.h"
#include "banana.h"

#include "level.h"
#include "tiles.h"

#include "menu.h"
#include "menuItem.h"

#ifdef _WIN32
	const std::string fontPath = "assets\\fonts\\Full-Dece-Sans-1.0.ttf";
#else
	const std::string fontPath = "assets/fonts/Full-Dece-Sans-1.0.ttf";
#endif

bool initTiles();

void positionUI(PlayableCharacter*, sf::RenderWindow&, sf::View&, sf::Text[]);
float getAverageFPS(float);

//The current level, global so the player can get data from it:
Level* level = NULL;

//The menu stack, needed mostly so the 'Back'
//item knows where to go back to:
std::vector <Menu*> menuStack;

int main()
{
	if(! initTiles())
		return -1;

	if(! Banana::init())
		return -1;

	if(! MenuItem::init())
		return -1;

	if(! Menu::init())
		return -1;

	//Initialise the menu stack:
	menuStack.push_back(NULL);

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
	sf::Text text[3];
	text[0].setFont(font);
	text[0].setColor(sf::Color::Black);
	text[0].setCharacterSize(16);
	text[0].setString("Average FPS:");

	text[1].setFont(font);
	text[1].setColor(sf::Color::Black);
	text[1].setCharacterSize(16);
	text[1].setString("Lives:");

	text[2].setFont(font);
	text[2].setColor(sf::Color::Black);
	text[2].setCharacterSize(16);
	text[2].setString("Score:");

	//Position the UI:
	positionUI(player, window, view, text);

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
			}
		}

		player->handleEvents(frameTime);

		//Handle the tile events:
		for(unsigned int i = 0; i < level->getTiles().size(); i++)
		{
			level->getTiles()[i]->handleEvents();
			level->getTiles()[i]->handleEvents(*player);
		}

		//Checks if the left key is pressed:
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			player->move(DIRECTION_LEFT, frameTime);

		//Checks if the right key is pressed:
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			player->move(DIRECTION_RIGHT, frameTime);

		//Checks if the space bar is pressed:
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			player->jump();

		//Check if the player is offscreen:
		if(player->getSprite().getGlobalBounds().top > view.getSize().y)
			player->kill();

		//Checks if the player has lost all of their lives:
		if(player->getLives() <= 0)
		{
			std::cout << "Game Over!\n";
			window.close();
		}

		//Clear the screen white:
		window.clear(sf::Color::White);

		//Calculate the FPS:
		float fps_f = 1 / frameTime;

		//Write the FPS:
		if(getAverageFPS(fps_f) != -1)
		{
			std::stringstream fps_sstream;
			fps_sstream << "Average FPS: " << fps_f;
			text[0].setString(fps_sstream.str());
		}

		//Write the lives:
		{
			std::stringstream lives_sstream;
			lives_sstream << "Lives: " << player->getLives();
			text[1].setString(lives_sstream.str());
		}

		//Write the score:
		{
			std::stringstream score_sstream;
			score_sstream << "Score: " << player->getScore();
			text[2].setString(score_sstream.str());
		}

		//Draw the text:
		window.draw(text[0]);
		window.draw(text[1]);
		window.draw(text[2]);

		//Position the UI:
		positionUI(player, window, view, text);

		//Draw the player:
		window.draw(player->getSprite());

		//Draw the tiles:
		for(unsigned int i = 0; i < level->getTiles().size(); i++)
			window.draw(level->getTiles()[i]->getSprite());

		//Draw the menu text:
//		window.draw(menuStack.back()->getItems()[0]->getText());

		//Display the window:
		window.display();

		//Calculate the frame rate:
		frameTime = fps.restart().asSeconds();
	}
	delete level;
	delete player;
//	delete test;
	return 0;
}

bool initTiles()
{
	//Attempts to load the images:
	if(! SolidTile::init())
		return false;

	if(! EmptyTile::init())
		return false;

	if(! Coin::init())
		return false;

	if(! Spike::init())
		return false;

	return true;
}

void positionUI(PlayableCharacter* player, sf::RenderWindow& window, sf::View& view, sf::Text text[])
{
	//Reposition the view:
	float centreX = player->getSprite().getGlobalBounds().left;	
	float centreY = (window.getSize().y / 2);
	view.setCenter(centreX, centreY);
	window.setView(view);

	//Reposition the text:
	float textX = (view.getCenter().x + (view.getSize().x / 2)) - 200;
	float textY = (view.getCenter().y - (view.getSize().y / 2)) + 5;
	text[0].setPosition(textX, textY);	

	textX = (view.getCenter().x - (view.getSize().x / 2)) + 5;
	textY = (view.getCenter().y - (view.getSize().y / 2)) + 5;
	text[1].setPosition(textX, textY);

	textX = (view.getCenter().x - (view.getSize().x / 2)) + 5;
	textY = (view.getCenter().y - (view.getSize().y / 2)) + 25;
	text[2].setPosition(textX, textY);
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
