#include "Screen.hpp"

Screen::Screen(){
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	display = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Project Lambda",NULL);
}

Screen::~Screen(){
	TTF_Quit();
	SDL_Quit();
}

void Screen::draw(SDL_Surface* source,int x,int y,SDL_Rect* clip = NULL){
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	
	SDL_BlitSurface(source,clip,display,&offset);
}

void Screen::refresh(){
	SDL_Flip(display);
	SDL_FillRect(display,NULL, 0x000000);
}
