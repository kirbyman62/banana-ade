#include "playableCharacter.h"

PlayableCharacter::PlayableCharacter(short unsigned int lives = 0, unsigned int score = 0)
{
	_lives = lives;
	_score = score;
}

short unsigned int PlayableCharacter::getLives()
{
	return _lives;
}

unsigned int PlayableCharacter::getScore()
{
	return _score;
}
