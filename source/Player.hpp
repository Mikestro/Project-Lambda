#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "Input.hpp"
#include <vector>
using std::vector;

class Player : public Entity{
	private:
		//int speed;
	public:
		Input *input;
		Player(Input*,Screen*,Sprite*);
		~Player();
		void tick();
		//void move(vector<Tile*>*);
		// void render();
		
		void handleInput();
		
		//void handleInput();
};

#endif
