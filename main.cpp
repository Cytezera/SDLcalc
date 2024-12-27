#include <SDL2/SDL.h>
#include <iostream>
using namespace std; 
const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 480 ; 

int main( int argc, char* args[]) {
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL ;
	if (SDL_Init(SDL_INIT_VIDEO) < 0 ){
		cout << "SDL could not be initialized " << SDL_GetError() ; 
	}else {
		window = SDL_CreateWindow("SDL Tutorial" , SDL_WINDOWPOS_UNDEFINED , SDL_WINODWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL ) {
			cout << "winodw could not be created " << endl; 
		}
	}

}
