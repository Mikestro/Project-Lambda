#include "Game.hpp"
#include "GUI.hpp"

bool useHD = false;

Game::Game(){
	running = true;
	paused = false;

	screen = new Screen;
	input = new Input;
	TTF_Init();
}

Game::~Game(){
	TTF_CloseFont(font);
	TTF_Quit();
	sprites.clear();
	entities.clear();
	
	delete screen;
	delete input;
}

void Game::startStateMachine(){
	bool running = true;
	State *currentState;
	sprites.push_back(new Sprite("resource/red.png"));
	//entities.push_back(new Player(input,screen,sprites[0]));
	gameVars gvars = {screen,&sprites,&entities,font,input};
	currentState = new TestRoom(gvars);
	
	while (running){
		int timer = SDL_GetTicks();
		while(SDL_PollEvent(&input->events)){
			currentState->tick();
			
			if(input->events.type == SDL_QUIT)
				running = false;
		}
		
		currentState->move();
		currentState->render();
		screen->refresh();
		if((SDL_GetTicks()-timer) < 1000 / 30 ){
			SDL_Delay((1000/30)-(SDL_GetTicks()-timer));
		}
	}
	
	delete currentState;
}

void Game::loadFiles(){
	
	sprites.push_back(new Sprite("resource/red.png"));
	if(useHD)
		sprites.push_back(new Sprite("hd-texturepack.png"));
	else
		sprites.push_back(new Sprite("resource/tileset.png"));
	sprites[1]->clips[0].x = 0;
	sprites[1]->clips[0].y = 0;
	sprites[1]->clips[0].h = 32;
	sprites[1]->clips[0].w = 32;
	sprites[1]->clips[1].x = 32;
	sprites[1]->clips[1].y = 0;
	sprites[1]->clips[1].w = 32;
	sprites[1]->clips[1].h = 32;
	sprites[1]->clips[2].x = 64;
	sprites[1]->clips[2].y = 0;
	sprites[1]->clips[2].w = 32;
	sprites[1]->clips[2].h = 32;
	sprites[1]->clips[3].x = 96;
	sprites[1]->clips[3].y = 0;
	sprites[1]->clips[3].w = 32;
	sprites[1]->clips[3].h = 32;
	sprites[1]->clips[4].x = 128;
	sprites[1]->clips[4].y = 0;
	sprites[1]->clips[4].w = 32;
	sprites[1]->clips[4].h = 32;
	
	sprites.push_back(new Sprite("resource/blue-message.png"));
	sprites.push_back(new Sprite("resource/blue-purple-buttons.png"));
	entities.push_back(new Player(input,screen,sprites[0]));
	entities[0]->transform(300,0);
	font = TTF_OpenFont("resource/game_over.ttf",72);
	
}

int main(int argc, char *args[]){
	if((argc > 1)&&(args[1]=="-HD"))
		useHD = true;// std::cout << *args[1];
	Game *g = new Game;
	g->loadFiles();
	g->startStateMachine();
	
	return 0;
}
