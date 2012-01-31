#ifndef GUI_HPP
#define GUI_HPP


#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "Sprite.hpp"
#include "Screen.hpp"
#include "Input.hpp"
#include <string>
//#include <vector>
using std::string;

class GUI{
	private:
		TTF_Font *font;
		SDL_Surface *textbox;
		Screen *screen;
		
	public:
		GUI(Screen*);
		~GUI();
		
		void drawMessageBox(string);
};

class Widget{
	protected:
		SDL_Rect box;
		Sprite *graphic;
		Input *input;
		Screen* screen;
		TTF_Font *font;
		//SDL_Color textColor;
		
	public:
		Widget(Sprite*,Input*,Screen*,TTF_Font*);
		
		virtual void tick() = 0;
		virtual void render() = 0;
		//virtual void setText(int,string) = 0;
};

class textBox : public Widget{
	private:
		string text[3];
	
	public:
		textBox(Sprite*,Input*,Screen*,TTF_Font*);
		
		void setText(int,string);
		void tick();
		void render();
};

class button : public Widget{
	private:
		string label;
		int x, y;
		
		void (*funct)();
		
	public:
	
		bool isPressed;
		button(Sprite*,Input*,Screen*,TTF_Font*);
		
		void setLabel(string);
		void tick();
		void render();
		
		void setFunct(void(*p)());
		
		
		
		void setPos(int,int);
};

#endif
