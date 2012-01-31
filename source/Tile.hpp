#ifndef TILE_HPP
#define TILE_HPP

#include "Screen.hpp"
#include "Sprite.hpp"

#define TILE_WIDTH 32
#define TILE_HEIGHT 32
#define TILES_PER_SCREEN 300
#define TOTAL_TILES 5
#include "Screen.hpp"
#include "Sprite.hpp"
#include "Entity.hpp"
#include <fstream>
#include <iostream>

const int BLACK = 0;
const int GRASS = 1;
const int WATER= 2;
const int STONE = 3;
const int DIRT = 4;

class Tile : public Entity{
	private:
		int type, solid;
		
	public:
		Tile(Screen*,Sprite*,int,int,int);
		
		void tick();
		//void move();
		void render();

		int gType();
		
};

#endif
