#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

class Screen{
private:
	SDL_Surface *display;
	
public:
	Screen();
	~Screen();

	void refresh();
	void draw(SDL_Surface*,int,int,SDL_Rect*);
};


#endif