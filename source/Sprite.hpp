#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
using std::string;

class Sprite{
	public:
		SDL_Surface *surf;
		SDL_Rect clips[10];
		SDL_Rect *c;

		Sprite(string);
		~Sprite();
		
		void setClip(int,int,int,int,int);
};

#endif