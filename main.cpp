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
		window = SDL_CreateWindow("SDL Tutorial" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL ) {
			cout << "winodw could not be created " << endl; 
		}
		else {
			screenSurface = SDL_GetWindowSurface(window); 
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB(screenSurface->format,0xFF,0xFF,0xFF));
			SDL_UpdateWindowSurface(window);
			SDL_Event e ; 
			bool quit = false; 
			while (quit == false )
			{
				while (SDL_PollEvent( &e))
				{
					if (e.type == SDL_QUIT) quit = true; 
				}
			}
		}
	}
	SDL_DestroyWindow( window); 
	SDL_Quit();
	return 0 ; 

}
