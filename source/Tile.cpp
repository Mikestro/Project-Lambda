#include "Tile.hpp"

Tile::Tile(Screen* s,Sprite* spr, int t,int tx,int ty) : Entity(s,spr){
	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;
	box.x = tx;
	box.y = ty;
	
	type = t;
	sprite->c = &sprite->clips[t];
}

void Tile::tick(){
	
}

void Tile::move(){
}

void Tile::render(){
	screen->draw(sprite->surf,box.x,box.y,&sprite->clips[type]);
}