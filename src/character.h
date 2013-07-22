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
	COLLISION_TOPLEFT,
	COLLISION_TOPRIGHT,
	COLLISION_BOTTOMLEFT,
	COLLISION_BOTTOMRIGHT,
	COLLISION_LEFT,
	COLLISION_RIGHT,
	COLLISION_TOP,
	COLLISION_BOTTOM,
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
		//The sprite:
		sf::Sprite _sprite;

		//The animation frame and the timer:
		int _frame;
		sf::Clock _frameClock;

		//The direction the character is facing:
		Direction _direction;
	public:
		//Loads the images:
		//The images of each class are static, so the same images are
		//not loaded into memory an unnessecary amount of times. We could
		//still do with having the initialise function being polymorphic,
		//as different characters will have different images that need loading.
		virtual bool init() = 0;

		//Getters:
		//(Is giving full access to the sprite too much?)
		//(Perhaps just specific setters/getters for aspects we need)
		sf::Sprite& getSprite();

		//Checks for a collision with the given sprite or window:
		Collision checkCollision(sf::Sprite&) const;
		Collision checkCollision(sf::Window&) const;
};

#endif
