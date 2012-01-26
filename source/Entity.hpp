#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SDL/SDL.h"
#include "Sprite.hpp"
#include "Screen.hpp"
//#include "Debug.hpp"

class Entity{
	protected:
		SDL_Rect box;
		int xvel,yvel, c;
	public: 
		Sprite *sprite;
		Screen *screen;
		Entity(Screen*,Sprite*);
		~Entity();
		
		virtual void tick();
		virtual void move();
		virtual void render();
		
};

#endif