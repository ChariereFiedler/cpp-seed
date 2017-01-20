//
// Created by cedriccf on 20/01/17.
//

#ifndef CPP_SEED_ENGINE_H
#define CPP_SEED_ENGINE_H

#include <SDL2/SDL.h>
#include <SDL_image.h>

#include <iostream>
#include "window.h"
#include "properties.h"

class Engine {

    Window _window;
    bool _end;
    float _frameRate;

    void init() {

        //Img Init
        if(IMG_Init(~0) == -1) {
            std::cout<<"cannot open audio" << std::endl;
            throw std::runtime_error(std::string("Cannot Init Img"));
        }

    }

    void display(){
        _window.display();
    }

public:
    Engine():
        _window(Properties::Window::TITLE,Properties::Window::WIDTH, Properties::Window::HEIGHT ),
        _frameRate(60),
        _end(false)
    {
        init();
    }

    void start(){
        while(!_end) {
            Uint32 before = SDL_GetTicks();
            _window.clean();
            display();
            Uint32 now = SDL_GetTicks();
            Uint32 diff = now - before;
            if(diff < _frameRate ) {
                SDL_Delay(Uint32(_frameRate) - diff);
            }
        }
    }
};

#endif //CPP_SEED_ENGINE_H
