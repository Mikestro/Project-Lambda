#include "Tile.hpp"
#include "Entity.hpp"

Tile::Tile(Screen* s,Sprite* spr, int t,int tx,int ty) : Entity(s,spr){
	box.w = 32;
	box.h = 32;
	box.x = tx;
	box.y = ty;
	yvel = xvel = 0;

	type = t;
	sprite->c = &sprite->clips[t];

	//Set the tile's solidity
	if((type==WATER)||(type==STONE)||(type==BLACK))
		solid = 1;
	else
		solid = 0;
}

void Tile::tick(){
}

//void Tile::move(){
//}

void Tile::render(){
	screen->draw(sprite->surf,box.x,box.y,&sprite->clips[type]);
}

int Tile::gType(){
	return solid;
}
