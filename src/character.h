// ---
// character.h
//
// Contains the class definition for a character, the
// base class for all 'characters', meaning:
// * Playable characters
// * NPCs
// * Enemies
// * Bosses
// ---

#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>

//The background colour to set transparent:
const int RED = 0;
const int GREEN = 0;
const int BLUE = 0;
const sf::Color COLOUR_KEY = sf::Color(RED, GREEN, BLUE);

//The collision types:
enum Collision
{
	COLLISION_LEFT,
	COLLISION_RIGHT,
	COLLISION_UP,
	COLLISION_DOWN,
	COLLISION_NONE,
};

//Movement directions:
enum Direction
{
	LEFT,
	RIGHT,
};

class Character
{
	protected:
		//The sprite and images:
		sf::Sprite _sprite;
		static sf::Image _images[];

		//The animation frame and the timer:
		int _frame;
		sf::Clock _frameClock;

		//The direction the character is facing:
		Direction _direction;
	public:
		//Getters:
		//(Is giving full access to the sprite too much?)
		//(Perhaps just specific setters/getters for aspects we need)
		sf::Sprite& getSprite();

		//Checks for a collision with the given sprite or window:
		Collision checkCollision(sf::Sprite&) const;
		Collision checkCollision(sf::Window&) const;
};

#endif
