#include "Sprite.hpp"

Sprite::Sprite(string filename){
	
	SDL_Surface *TempSurf = IMG_Load(filename.c_str());
	surf = SDL_DisplayFormat(TempSurf);
	SDL_FreeSurface(TempSurf);
	
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
