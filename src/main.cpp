#include <SDL2/SDL.h>
#include <iostream>
#include <engine.h>

#include "window.h"

int main(int argc, char** argv) {
	std::cout<<"Hello"<<std::endl;
	
	Engine e= Engine();
    e.start();

	return 1;
}
