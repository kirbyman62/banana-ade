// ---
// level.h
//
// The class definiton for a 'level',
// a collection of tiles, enemies,
// projectiles and other objects that
// the player runs about in.
// ---

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

#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <string>
#include "tile.h"
//#include "enemy.h" //This does not yet exist
//#include "projectile.h" //This does not yet exist

class Level
{
	private:
		//Various metadata tags about the level:
		//[No clue if having them 'const' will work, let's find out]
		const std::string _name, _author;

		//The tiles that make up the level:
		std::vector <Tile*> _tiles;

		//The enemies in the level:
//		std::vector <Enemy*> _enemies;

		//The various projectiles:
//		std::vector <Projectile*> _projectiles;

	public:
		//Constructor:
		Level(std::string);

		//Destructor:
		~Level();

		//Getters:
		std::string& getName() const;
		std::string& getAuthor() const;
};

#endif
