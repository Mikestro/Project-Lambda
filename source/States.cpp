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
	rLoad();
	msg = new textBox((*vSprites)[2],input,screen,font);
	msg->setText(0,"Houston,");
	msg->setText(1,"We have tilemap.");
}

void TestRoom::rLoad(){
	vTiles.clear();
	
	std::ifstream map("foo.map");
	int x = 0, y = 0;
	
	
	for(int t = 0; t < TILES_PER_SCREEN; t++){
		int tileType = -1;
		map >> tileType;
		
		if((tileType >= 0)&&(tileType < TOTAL_TILES)){
			vTiles.push_back(new Tile(screen,(*vSprites)[1],tileType,x,y));
		}
		
		x += TILE_WIDTH;
		
		if(x >= 640){
			x = 0;
			y += TILE_HEIGHT;
		}
	}
	
	std::cout << vTiles.max_size() << std::endl;
	std::cout << vTiles.size() << std::endl;
	
	map.close();
}

TestRoom::~TestRoom(){
	vTiles.clear();
}

void TestRoom::tick(){

	(*vEntities)[0]->tick();
	
	if(input->events.type == SDLK_DOWN){
		switch(input->events.key.keysym.sym){
			case key_up: rLoad(); std::cout << "Reloading map...\n"; break;
			default: break;
		}
	}
	
	rLoad();
	
}

void TestRoom::move(){
	(*vEntities)[0]->move();
}

void TestRoom::render(){
	
	for(int i = 0; i < vTiles.size(); i++){
		vTiles[i]->render();
	}
	
	(*vEntities)[0]->render();
	msg->render();
}