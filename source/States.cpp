#include "States.hpp"

State::State(gameVars v){
	screen = v.screen;
	input = v.input;
	vSprites = v.vSprites;
	vEntities = v.vEntities;
	font = v.font;
	statePointer = v.statePointer;
}

State::State(gameVars v,State* prev){
	screen = v.screen;
	input = v.input;
	vSprites = v.vSprites;
	vEntities = v.vEntities;
	font = v.font;
	statePointer = v.statePointer;
	
	prevState = prev;
}

void State::setNextState(State* next){
	nextState = next;
}

void State::setPrevState(State* prev){
	prevState = prev;
}

void State::startNextState(){
	*statePointer = nextState;
}

void State::startPrevState(){
	*statePointer = prevState;
}

TestRoom::TestRoom(gameVars v) : State(v){

}

void TestRoom::tick(){
	(*vEntities)[0]->tick();
}

void TestRoom::move(){
	(*vEntities)[0]->move();
}

void TestRoom::render(){
	(*vEntities)[0]->render();
}