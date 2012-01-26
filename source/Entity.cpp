#include "Entity.hpp"

Entity::Entity(Screen* s,Sprite* sp){
	sprite = sp;
	screen = s;
	c = 0;
	box.x = 0;
	box.y = 0;
	yvel = 0;
	xvel = 0;
}

Entity::~Entity(){
	delete sprite;
}

void Entity::tick(){	
}

void Entity::move(){
	box.x += xvel;
	box.y += yvel;
}

void Entity::render(){
	screen->draw(sprite->surf,box.x,box.y,NULL);
	//&sprite->clips[c]
}