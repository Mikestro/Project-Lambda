#include "Sprite.hpp"

Sprite::Sprite(string filename){
	surf = IMG_Load(filename.c_str());
	
}

Sprite::~Sprite(){
	SDL_FreeSurface(surf);
}

void Sprite::setClip(int indice, int x, int y, int w, int h){
	clips[indice].x = x;
	clips[indice].y = y;
	clips[indice].w = w;
	clips[indice].h = h;
}
