#ifndef STATES_HPP
#define STATES_HPP

#include "Screen.hpp"
#include "Input.hpp"
#include "Sprite.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "GUI.hpp"

#include <vector>
using std::vector;

struct envVars{
	Screen *screen;
	Input *input;
	vector<Sprite*> sprites;
	TTF_Font *font;
	vector<Entity*> entities;
};

class State{
	protected:
		envVars *currentEnvironmentVariables;
		State *lastState, *nextState;
	public:
		State(State*,envVars*);
		
		void startState(State*);
		virtual void run() = 0;
		virtual void tick() = 0;
		
		void setNextState(State*);
		void startNextState();
		
		void runLastState();
};

class TitleScreen : public State{
	public:
		TitleScreen(State*,envVars*);
		void run();
		
		void tick();
		void draw();
};

class TestRoom : public State{
	public:
		TestRoom(State*,envVars*);
		void run();
		
		void tick();
		void draw();
};

#endif