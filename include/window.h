//
// Created by Patataa on 19/03/2016.
//
#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>
#include <string>
class Window {
public:
    std::string _title;
    int _width;
    int _height;
    SDL_Window *_window;
    SDL_Renderer *_mainRenderer;

    Window(const std::string &title, int width, int height, int flags = 0) :
            _title(title),
            _width(width),
            _height(height) {
        SDL_Init(SDL_INIT_EVERYTHING);
        _window = SDL_CreateWindow(
                _title.c_str(),
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                width,
                height,
                flags
        );
        _mainRenderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
        if (!_mainRenderer) {
            throw std::runtime_error(SDL_GetError());
        }
    }

    virtual ~Window() {
        SDL_DestroyWindow(_window);
    }

    void clean() {
        SDL_RenderClear(_mainRenderer);
    }

    void display() {
        SDL_RenderPresent(_mainRenderer);
    }
};

#endif WINDOW_H