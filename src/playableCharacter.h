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

	public:
		//Constructor:
		PlayableCharacter(short unsigned int, unsigned int);

		//Handles non-keyboard events, like gravity:
		virtual void handleEvents() = 0;

		//Handles keyboard events:
		virtual void handleKeyboardEvents(sf::Window&) = 0;

		//Getters:
		short unsigned int getLives();
		unsigned int getScore();
};

#endif
