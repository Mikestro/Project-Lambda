#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SDL/SDL.h"
#include "Sprite.hpp"
#include "Screen.hpp"
class Tile;
#include <vector>
using std::vector;
//#include "Debug.hpp"

class Entity{
	protected:
		SDL_Rect box;
		int xvel,yvel, c, speed;
	public: 
		Sprite *sprite;
		Screen *screen;
		Entity(Screen*,Sprite*);
		~Entity();
		
		virtual void tick();
		virtual void move(vector<Tile*>*);
		virtual void render();

		void transform(int,int);

		bool isCollidingWith(Entity*);
		
};

#include "Tile.hpp"
#endif
