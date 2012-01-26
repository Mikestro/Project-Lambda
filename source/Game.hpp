#ifndef GAME_HPP
#define GAME_HPP

#include "Screen.hpp"
#include "Input.hpp"
#include "Sprite.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "States.hpp"

class Game{
	private:
		bool running, paused, debug;
		Screen *screen;
		Input *input;
		TTF_Font *font;
		vector<Sprite*> sprites;
		vector<Entity*> entities;
	public:
		Game();
		~Game();
		
		void run();
		
		void startStateMachine();
		
		void loadFiles();
		
		void update();
		void draw();
};


#endif