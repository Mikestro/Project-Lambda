#include "GUI.hpp"

GUI::GUI(Screen* s){
	screen = s;
	TTF_Init();
	font = TTF_OpenFont("resource/game_over.ttf",72);
	textbox = IMG_Load("resource/blue-message.png");
}

GUI::~GUI(){
	SDL_FreeSurface(textbox);
	TTF_CloseFont(font);
	TTF_Quit();
}

void GUI::drawMessageBox(string text){

	SDL_Color textColor = {255,255,255};
	
	SDL_Surface *line1 = TTF_RenderText_Solid(font,text.c_str(),textColor);
	//SDL_Surface *line2 = TTF_RenderText_Solid(font,"Bow before me, bitches.",textColor);
	
	screen->draw(textbox,0,300,NULL);
	screen->draw(line1,0,300,NULL);
	//screen->draw(line1,0,330,NULL);
	
}

Widget::Widget(Sprite* spr,Input* i, Screen* s,TTF_Font* f){
	graphic = spr;
	input = i;
	screen = s;
	font = f;
}	

textBox::textBox(Sprite* spr,Input* i, Screen* s,TTF_Font* f) : Widget(spr,i,s,f){
	text[0] = " ";
	text[1] = " ";
	text[2] = " ";
}

void textBox::setText(int i, string t){
	text[i] = t;
}

void textBox::render(){
	SDL_Color textColor = {255,255,255}; 
	screen->draw(graphic->surf,0,300,NULL);
	SDL_Surface *lines[3];
	
	for(int i = 0; i < 3; i++)
		lines[i] = TTF_RenderText_Solid(font,text[i].c_str(),textColor);
		
	screen->draw(lines[0],0,300,NULL);
	screen->draw(lines[1],0,330,NULL);
	screen->draw(lines[2],0,360,NULL);
}

void textBox::tick(){
}

button::button(Sprite* spr,Input* i, Screen* s,TTF_Font* f) : Widget(spr,i,s,f){
	box.x = 0;
	box.y = 0;
	box.w = 128;
	box.h = 64;
	
	graphic->clips[0].x = 0;
	graphic->clips[0].y = 0;
	graphic->clips[0].w = 128;
	graphic->clips[0].h = 64;
	
	graphic->clips[1].x = 128;
	graphic->clips[1].y = 0;
	graphic->clips[1].w = 128;
	graphic->clips[1].h = 64;
	
	graphic->clips[2].x = 0;
	graphic->clips[2].y = 64;
	graphic->clips[2].w = 128;
	graphic->clips[2].h = 64;
	
	graphic->c = &graphic->clips[0];
	
	label = "Default";
	
	isPressed = false;
}

void button::tick(){
	int x =0,y=0;
	
	if(input->events.type == SDL_MOUSEMOTION){
		x = input->events.motion.x;
		y = input->events.motion.y;
		
		if(( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h )){
			graphic->c = &graphic->clips[1];
		} else {
			graphic->c = &graphic->clips[0];
		}
	}
	
	if(input->events.type == SDL_MOUSEBUTTONDOWN){
		if(input->events.button.button == SDL_BUTTON_LEFT){
			x = input->events.button.x;
			y = input->events.button.y;
			
			 if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) ){
				graphic->c = &graphic->clips[2];
				isPressed = true;
			 }
		}
		
	}
	
	if(input->events.type == SDL_MOUSEBUTTONUP){
		if(input->events.button.button == SDL_BUTTON_LEFT){
			x = input->events.button.x;
			y = input->events.button.y; 
			if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) ){
				graphic->c = &graphic->clips[0];
				isPressed = false;
			}
		}
	}
}

void button::render(){
	SDL_Color textColor = { 255,255,255};
	screen->draw(graphic->surf,x,y,graphic->c);
	SDL_Surface *lbl = TTF_RenderText_Solid(font,label.c_str(),textColor);
	screen->draw(lbl,x,y,NULL);
	SDL_FreeSurface(lbl);
}

void button::setPos(int ox, int oy){
	x = ox;
	y = oy;
	
	box.x = x;
	box.y = y;
}

void button::setLabel(string t){
	label = t;
}

