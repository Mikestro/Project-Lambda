#ifndef GAME_HPP
#define GAME_HPP

#include "Screen.hpp"
#include "Input.hpp"
#include "Sprite.hpp"
#include "Entity.hpp"
#include "Player.hpp"
//#include "ResourceManager.hpp"
//#include "States.hpp"

class Game{
	private:
		bool running, paused, debug;
		Screen *screen;
		Input *input;
		TTF_Font *font;
		//ResourceManager rMan;
		//vector<Sprite*> sprites;
		//vector<Entity*> entities;
	public:
		Game();
		~Game();
		
		void run();
		//void startStateMachine(State*);
		
		//void loadFiles();
		
};


#endif
