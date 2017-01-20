#include <SDL2/SDL.h>
#include <iostream>

#include "Window.h"

int main(int argc, char** argv) {
	std::cout<<"Hello"<<std::endl;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Cannot init SDL2 : " << SDL_GetError()<< std::endl;
 	} else {
		Window w = Window();
		for(;;) {
			w.display();
			SDL_Delay(200);
		}	
	}

	return 1;
}
