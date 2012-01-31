#include "Entity.hpp"

Entity::Entity(Screen* s,Sprite* sp){
	sprite = sp;
	screen = s;
	c = 0;
	box.x = 0;
	box.y = 0;
	yvel = 0;
	xvel = 0;
	box.w = 32;
	box.h = 32;
	speed = 8;
}

Entity::~Entity(){
	delete sprite;
}

void Entity::tick(){	
}

void Entity::move(vector<Tile*> *tiles){
	bool xcoll = false;
	bool ycoll = false;


	box.x += xvel;

	if((box.x < 0)||(box.x+box.w > 640)){
		box.x -= xvel;
	}		 
	for(int i = 0; i < tiles->size(); i++){
		if(((xvel != 0))&&(!(*tiles)[i]->isCollidingWith(this))&&((*tiles)[i]->gType() == 1)&&(!xcoll)){
			if(xvel > 0) 
				box.x = (*tiles)[i]->box.x - box.w;
			else if(xvel < 0)
				box.x = (*tiles)[i]->box.x + box.w;
		}
	}

	
	box.y += yvel;

	if((box.y < 0)||(box.y+box.h>480)){
		box.y -= yvel;
	}
	for(int i = 0; i <tiles->size(); i++){
		if((yvel != 0)&&(!(*tiles)[i]->isCollidingWith(this))&&((*tiles)[i]->gType() == 1)&&(!ycoll)){
			if(yvel > 0)
				box.y = (*tiles)[i]->box.y - box.h;
			else if(yvel < 0)
				box.y = (*tiles)[i]->box.y + box.h;
		}
	}
}

void Entity::render(){
	screen->draw(sprite->surf,box.x,box.y,NULL);
	//&sprite->clips[c]
}

bool Entity::isCollidingWith(Entity* other){
	int topA, topB;
	int bottomA, bottomB;
	int leftA, leftB;
	int rightA, rightB;

	topA = box.y;
	bottomA = box.y + box.h;
	leftA = box.x;
	rightA = box.x + box.w;

	topB = other->box.y;
	bottomB = other->box.y + other->box.h;
	leftB = other->box.x;
	rightB = other->box.x + other->box.w;


	if((topA >= bottomB)||(bottomA <= topB)){
		return true;
	}

	if((leftA >= rightB)||(rightA <= leftB)){
		return true;
	}

	//If no collision with other was found
	return false;
}

void Entity::transform(int tx, int ty){
	box.x = tx;
	box.y = ty;
}
