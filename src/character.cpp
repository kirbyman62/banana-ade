#include "character.h"

//Returns the sprite (check the header, is this overkill?)
sf::Sprite& Character::getSprite()
{
	return _sprite;
}

//Checks for any collisions between the character and a sprite:
Collision Character::checkCollision(sf::Sprite& spriteB) const
{	
	//Calculates the 4 'sides' of object A, the character:
	float topA, bottomA, leftA, rightA;
	float topB, bottomB, leftB, rightB;
	topA = _sprite.GetPosition().y;
	bottomA = (_sprite.GetPosition().y + _sprite.GetSize().y);
	leftA = _sprite.GetPosition().x;
	rightA = (_sprite.GetPosition().x + _sprite.GetSize().x);

	//Calculates the 4 'sides' of object B, the given sprite:
	topB = spriteB.GetPosition().y;
	bottomB = (spriteB.GetPosition().y + spriteB.GetSize().y);
	leftB = spriteB.GetPosition().x;
	rightB = (spriteB.GetPosition().x + spriteB.GetSize().x);

	//Top and bottom:
	if((leftA <= rightB) && (rightA >= leftB))
	{
		//Top:
		if((topA <= bottomB) && (topA >= topB))
			return COLLISION_UP;

		//Bottom:
		if((bottomA >= topB) && (bottomA <= bottomB))
			return COLLISION_DOWN;
	}
	//Left and right:
	if((topA <= bottomB) && (bottomA >= topB))
	{
		//Left:
		if((leftA <= rightB) && (leftA >= leftB))
			return COLLISION_LEFT;

		//Right:
		if((rightA >= leftB) && (rightA <= rightB))
			return COLLISION_RIGHT;

	}
	return COLLISION_NONE;
}

//Checks for any collisions between the character and a window:
Collision Character::checkCollision(sf::Window& window) const
{
	//Calculates the 4 'sides' of object A, the character:
	float topA, bottomA, leftA, rightA;

	//Calculates the 4 'sides' of object B, the window:
	topA = _sprite.GetPosition().y;
	bottomA = (_sprite.GetPosition().y + _sprite.GetSize().y);
	leftA = _sprite.GetPosition().x;
	rightA = (_sprite.GetPosition().x + _sprite.GetSize().x);

	//Top:
	if(topA < 0)
		return COLLISION_UP;

	//Bottom:
	if(bottomA > window.GetHeight())
		return COLLISION_DOWN;

	//Left:
	if(leftA < 0) 
		return COLLISION_LEFT;

	//Right:
	if(rightA > window.GetWidth())
		return COLLISION_RIGHT;

	//Otherwise there is no collision:
	return COLLISION_NONE;
}
