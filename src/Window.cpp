/* 
 * File:   SceneSDL.cpp
 * Author: Cedric Chariere Fiedler
 * 
 * Created on 29 septembre 2014, 22:34
 */

#include <iostream>
#include <stdexcept>
#include <assert.h>

#include "Window.h"

Window::Window(
        std::string title,
        int x,
        int y,
        int w,
        int h,
        Uint32 flags
):
        x(x),
        y(y),
        w(w),
        h(h),
        m_flags(flags)

{
}


Window::~Window() {
    destroy();
}
void Window::destroy(){
    if(m_displayable){
        SDL_DestroyWindow(m_window);
    }
}

void Window::display(){
    SDL_Surface * screenSurface = SDL_GetWindowSurface(m_window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF ) );
    SDL_UpdateWindowSurface(m_window);
}


void Window::load(){
}
