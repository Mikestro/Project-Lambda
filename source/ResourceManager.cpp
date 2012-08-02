#include "ResourceManager.hpp"

ResourceManager::~ResourceManager(){
	//TODO
	//Delete all resources
}

int ResourceManager::loadSprite(Sprite* s){
	if( s != NULL){
		vSprites.push_back(s);
		return vSprites.size() - 1;
	} else {
		return -1;
	}
}

Sprite* ResourceManager::getSpriteByID(int id){
	if ( id <= vSprites.size()){
		return vSprites[id];
	} else {
		return NULL;
	}
}
