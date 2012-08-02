#ifndef RESOURCE_MANAGER
#define RESOURCE_MANAGER

#include <vector>
using std::vector;

#include "Sprite.hpp"

class ResourceManager{
	private:
		vector<Sprite*> vSprites;
	public:
		~ResourceManager();

		int loadSprite(Sprite*);
		Sprite* getSpriteByID(int);
};

#endif
