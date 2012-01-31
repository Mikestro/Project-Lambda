#include "Player.hpp"

Player::Player(Input* i, Screen* s,Sprite* spr) : Entity(s,spr){
	input = i;
	//sprite = new Sprite("resource/player.png");
//	box.w = 32;
	//box.h = 32;
	//speed = 8;
}

Player::~Player(){
	delete sprite;
}

void Player::tick(){
	handleInput();

	//std::cout << "Box.w of player is " << box.w << std::endl;
}

/*void Player::move(vector<Tile*> *tiles){
	box.x += xvel;
	
	if((box.x < 0)||(box.x+box.w > 640)*||(*tiles)[6]->isCollidingWith(this)*)
//		box.x -=xvel;
		
//	box.y += yvel;
	
//	if((box.y < 0)||(box.y+box.h > 480)&&((*tiles)[6]->isCollidingWith(this)))
//		box.y -= yvel;
//}*/

// void Player::render(){
	
// }

void Player::handleInput(){
	if(input->events.type == SDL_KEYDOWN){
		switch(input->events.key.keysym.sym){
			case key_up: yvel -= speed; break;
			case key_down: yvel += speed; break;
			case key_left: xvel -= speed; break;
			case key_right: xvel += speed; break;
			default: break;
		}
		
	}else if(input->events.type == SDL_KEYUP){
		switch(input->events.key.keysym.sym){
			case key_up: yvel += speed; break;
			case key_down: yvel -= speed; break;
			case key_left: xvel += speed; break;
			case key_right: xvel -= speed; break;
			default: break;
		}
	}
	
}
