#include "Game.hpp"
#include "GUI.hpp"

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

void Game::run(){
	Entity *mine;
	mine = new Player(input,screen,sprites[0]);
	
	//Sprite *message = new Sprite("resource/blue-message.png");
	GUI *gui = new GUI(screen);
	SDL_Surface *message;// = gui->makeMessageBox("Testing.. 1.. 2.. 3..");
	bool showmessage = false;
	/*TTF_Font *font = TTF_OpenFont("resource/game_over.ttf",72);
	SDL_Color textColor = {255,255,255};
	SDL_Surface *line1 = TTF_RenderText_Solid(font,"I am a motherfucking message box.",textColor);
	SDL_Surface *line2 = TTF_RenderText_Solid(font,"Bow before me, bitches.",textColor);
	*/
	//test->render();
	mine->render();
	screen->refresh();
	while (running){
		int timer = SDL_GetTicks();
		while(SDL_PollEvent(&input->events)){
			mine->tick();
		
			if((input->events.type == SDL_KEYDOWN)){
				switch(input->events.key.keysym.sym){
					case SDLK_m: showmessage = !showmessage; break;
					default: break;
				}
			}
				
			if(input->isQuit())
				running = false;
		}
		
		mine->move();
		//test->render();
		mine->render();
		
		if(showmessage){
			//screen->draw(message,0,480-180,NULL);
			/*screen->draw(line1,0,300,NULL);
			screen->draw(line2,0,330,NULL);*/
			gui->drawMessageBox("");
			
		}
		
		
		screen->refresh();
		
		if((SDL_GetTicks()-timer) < 1000 / 30 ){
			SDL_Delay((1000/30)-(SDL_GetTicks()-timer));
		}
	}
	
	/*SDL_FreeSurface(line1);
	SDL_FreeSurface(line2);
	TTF_CloseFont(font);*/
	
	//delete mine;
	delete message;
	delete this;
}

void Game::startStateMachine(){
	bool running = true;
	State *currentState;
	sprites.push_back(new Sprite("resource/red.png"));
	entities.push_back(new Player(input,screen,sprites[0]));
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

void Game::update(){
	//TODO Update code
	//NOTE Am I even going to do anything with this at all?
}

void Game::draw(){
	screen->refresh();
}

void Game::loadFiles(){
	
	sprites.push_back(new Sprite("resource/red.png"));
	sprites.push_back(new Sprite("resource/tileset.png"));
	sprites[1]->clips[0].x = 0;
	sprites[1]->clips[0].y = 0;
	sprites[1]->clips[0].h = 32;
	sprites[1]->clips[0].w = 32;
	sprites[1]->clips[1].x = 32;
	sprites[1]->clips[1].y = 0;
	sprites[1]->clips[1].w = 32;
	sprites[1]->clips[1].h = 32;
	sprites[1]->clips[2].x = 64+32;
	sprites[1]->clips[2].y = 0;
	sprites[1]->clips[2].w = 32;
	sprites[1]->clips[2].h = 32;
	
	sprites.push_back(new Sprite("resource/blue-message.png"));
	sprites.push_back(new Sprite("resource/blue-purple-buttons.png"));
	entities.push_back(new Player(input,screen,sprites[0]));
	font = TTF_OpenFont("resource/game_over.ttf",72);
	
}

int main(int argc, char *args[]){
	Game *g = new Game;
	g->loadFiles();
	g->startStateMachine();
	
	return 0;
}