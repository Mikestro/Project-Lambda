#ifndef MAP_HPP
#define MAP_HPP

#include "Tile.hpp"
#include "Sprite.hpp"
#include "Entity.hpp"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Map{
	private:
		vector<Tile*> tiles;
		vector<Sprite*> *sprites;
		Screen *screen;
	public:
		Map(string,Screen*,vector<Sprite*>*);
		~Map();
		
		void render();
		//void reload();
		
		bool isCollide(Entity*);
		
		vector<Tile*> *getTiles();
};

#endif