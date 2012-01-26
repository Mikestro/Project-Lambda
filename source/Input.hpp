#ifndef INPUT_HPP
#define INPUT_HPP

#include "SDL/SDL.h"

struct MouseState{
	bool left;
	bool right;
	bool middle;
	int x, y;
};

enum eKey{
	key_up = SDLK_UP,
	key_down = SDLK_DOWN,
	key_left = SDLK_LEFT,
	key_right = SDLK_RIGHT,
	key_m = SDLK_m
};

class Input{
	public:
		SDL_Event events;
		bool isKeyDown(eKey);
		bool isQuit();
		MouseState getMouseState();
};

#endif