#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string> 
#include <iostream>
using namespace std; 

const int SCREEN_WIDTH = 800 ; 
const int SCREEN_HEIGHT = 600; 

struct Button {
	SDL_Rect rect; 
	SDL_Color color; 
	string label ;
}; 
void createButton(SDL_Renderer* renderer , TTF_Font* font ){
	Button button ;
	button.rect = {300, 200 , 200 ,100 } ; 
	button.color = {0,128,255,255}; 
	button.label = "Click me!" ; 	
	SDL_SetRenderDrawColor(renderer,button.color.r, button.color.g , button.color.b , button.color.a);
	SDL_RenderFillRect(renderer, &button.rect); 	
	SDL_RenderPresent(renderer); 
}
void openWindow(){
	if (SDL_Init(SDL_INIT_VIDEO)< 0 ) {
		cerr << "SDL cannot be connected " << SDL_GetError() << endl  ;
		return ;	
	}	
	if (TTF_Init() == - 1 ){
		cerr << "TTF cannot be initialized " << TTF_GetError() << endl; 
		SDL_Quit(); 
		return ;
	}
	SDL_Window* window = SDL_CreateWindow("Calculator", SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , SCREEN_WIDTH , SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
	if (!window){
		cerr << "Unable to create window" << SDL_GetError() << endl; 
		SDL_Quit();
		return ;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); 
	if (!renderer){
		cerr << "Renderer not functioning" << SDL_GetError() << endl; 
		SDL_DestroyWindow(window); 
		SDL_Quit(); 
		return  ;
	}
	TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSansMono-Oblique.ttf" ,24 ) ; 
	if (!font){
		cerr << "Unable to generate font" << SDL_GetError() << endl; 
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return; 
		
	}
	SDL_Event e ; 	
	bool quit = false; 
	while (!quit){
		while(SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true; 
			}
		}
		SDL_SetRenderDrawColor(renderer, 255, 255 ,255 ,255 ) ; 
		SDL_RenderClear(renderer); 
		createButton(renderer,font );
	}
	TTF_CloseFont(font); 
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit(); 
	SDL_Quit();
}
int main (int argc , char* argv[]){
	openWindow();
}
