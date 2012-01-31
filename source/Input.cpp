#include "Input.hpp"

bool Input::isKeyDown(eKey key){
	if(events.key.keysym.sym == key)
		return true;
	else
		return false;
}

MouseState Input::getMouseState(){
	//TODO write mousestate retrieval code
}

bool Input::isQuit(){
	if(events.type == SDL_QUIT)
		return true;
	else
		return false;
}

