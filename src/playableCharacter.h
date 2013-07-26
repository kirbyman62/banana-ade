// ---
// playableCharacter.h
//
// Contains the class definiton for a playable
// character, the character the player controls
// during the game.
// ---

#ifndef PLAYABLE_CHARACTER_H
#define PLAYABLE_CHARACTER_H
#include "character.h"

class PlayableCharacter
{
	protected:
		//The lives remaining:
		short unsigned int _lives;

		//The current score:
		unsigned int _score;		

		//The height jumped:
		float _heightJumped;

		//If the character is jumping, or falling:
		bool _isJumping;
		bool _isFalling;

		//The timer on the character's 'special',
		//so it has a cooldown period so it can't
		//be spammed over and over.
		sf::Clock _specialClock;

	public:
		//Constructor:
		PlayableCharacter(short unsigned int, unsigned int);

		//Handles non-keyboard events, like gravity:
		virtual void handleEvents() = 0;

		//Handles keyboard events:
		virtual void handleKeyboardEvents(sf::Window&) = 0;

		//Makes the character jump, or fall if they've jumped
		//too high:
		virtual void jump(float) = 0;

		//Setters:
		virtual void setFalling() = 0;

		//Getters:
		short unsigned int getLives();
		unsigned int getScore();
		bool isJumping();
		bool isFalling();
};

#endif
