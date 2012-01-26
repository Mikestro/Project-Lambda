#include "States.hpp"

State::State(State* last,envVars* other){
	lastState = last;
	currentEnvironmentVariables = other;
}

void State::setNextState(State* n){
	nextState = n;
}

void State::startNextState(){
	nextState->run();
}

void State::runLastState(){

	if(lastState != NULL)
		lastState->run();
}


void TestRoom::run(){
	/*bool running = true;
	bool showmessage=false;
	bool showbutton=false;
	Entity *p = new Player(input,"resource/red.png",screen);
	p->render();
	
	TTF_Init();
	TTF_Font *font = TTF_OpenFont("resource/game_over.ttf",72);
	Sprite *b = new Sprite("resource/blue-message.png");
	Sprite *q = new Sprite("resource/blue-purple-buttons.png");
	
	textBox *w = new textBox(b,input,screen,font);
	w->setText(0,"Use the arrow keys to move around");
	w->setText(1,"Presing 'm' will bring up this shitty dialogue box");
	w->setText(2,"-Random filler text goes here-");
	
	button *blah = new button(q,input,screen,font);
	blah->setPos(300,200);
	while(running){
		int timer = SDL_GetTicks();
		while(SDL_PollEvent(&input->events)){
			p->tick();
			blah->tick();
		
			if((input->events.type == SDL_KEYDOWN)){
				switch(input->events.key.keysym.sym){
					case SDLK_m: showmessage = !showmessage; break;
					case SDLK_b: showbutton = !showbutton; break;
					default: break;
				}
			}
				
			if(input->isQuit())
				running = false;
		}
		
		p->move();
		p->render();
		if(showbutton)
			blah->render();
		
		if(showmessage){
			w->render();		
		}
		
		
		
		screen->refresh();
		
		if((SDL_GetTicks()-timer) < 1000 / 30 ){
			SDL_Delay((1000/30)-(SDL_GetTicks()-timer));
		}
	}
	
	delete w;
	delete b;
	delete blah;
	delete q;
	
	TTF_CloseFont(font);
	TTF_Quit();
	delete p;*/
	
}

void TestRoom::tick(){

}

void TestRoom::draw(){

}

TestRoom::TestRoom(State* p,envVars* other) : State(p,other){
	lastState = p;
}

TitleScreen::TitleScreen(State* p,envVars* other) : State(p,other){
	lastState = p;
}

void TitleScreen::tick(){

}

void TitleScreen::run(){
	bool running = true;
	//Sprite *buttonSprites = new Sprite("resource/blue-purple-buttons.png");
	button *buttonStartGame = new button(currentEnvironmentVariables->sprites[2],currentEnvironmentVariables->input,currentEnvironmentVariables->screen,currentEnvironmentVariables->font);
	
	buttonStartGame->setPos(300,200);
	buttonStartGame->setLabel("Start");
	
	currentEnvironmentVariables->entities.push_back(new Player(currentEnvironmentVariables->input,currentEnvironmentVariables->screen,currentEnvironmentVariables->sprites[0]));
	vector<Entity*> *cEntity = &currentEnvironmentVariables->entities;
	
	while(running){
		int timer = SDL_GetTicks();
		while(SDL_PollEvent(&currentEnvironmentVariables->input->events)){
			buttonStartGame->tick();
			*cEntity[0].tick();
			if(currentEnvironmentVariables->input->isQuit())
				running = false;
		}
		
		cEntity[0].move();
		cEntity[0].render();
		
		buttonStartGame->render();
		
		
		currentEnvironmentVariables->screen->refresh();
		
		if((SDL_GetTicks()-timer) < 1000 / 30 ){
			SDL_Delay((1000/30)-(SDL_GetTicks()-timer));
		}
		
		//if(buttonStartGame->isPressed){
			//nextState = new TestRoom(this,screen,input);
			//running = false;
		//}
	}
	
	//TTF_CloseFont(font);
	//delete buttonSprites;
	delete buttonStartGame;
	nextState->run();
	//delete nextState;
}