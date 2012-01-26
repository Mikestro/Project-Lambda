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
class State;

struct gameVars{
	Screen* screen;
	vector<Sprite*> *vSprites;
	vector<Entity*> *vEntities;
	TTF_Font *font;
	Input *input;
	State** statePointer;
};

class State{
	protected:
		State *prevState, *nextState;
		State **statePointer;
		
		Screen* screen;
		vector<Sprite*> *vSprites;
		vector<Entity*> *vEntities;
		TTF_Font *font;
		Input *input;
	public:
		State(gameVars);
		State(gameVars,State*);
		
		void setNextState(State*);
		void setPrevState(State*);
		
		void startNextState();
		void startPrevState();
		
		virtual void tick() = 0;
		virtual void render() = 0;
		virtual void move() = 0;
};

class TestRoom : public State{
	public:
		TestRoom(gameVars);
		void tick();
		void render();
		void move();
	
};

#endif