/* 
 * File:   SceneSDL.h
 * Author: Cedric Chariere Fiedler
 *
 * Created on 29 septembre 2014, 22:34
 */

#ifndef SCENESDL_H
#define	SCENESDL_H
#include <string>
#include <SDL2/SDL.h>

class Window {
    std::string m_title;
    int x, y, w, h;
    Uint32 m_flags;
    SDL_Window* m_window;
    SDL_GLContext m_OpenGLContext;
    bool m_displayable;

public:
    Window(std::string title = "Window",
                int x =  50, 
                int y =  50, 
                int w = 800,
                int h = 600,
                Uint32 flags = SDL_WINDOW_SHOWN);
    Window(const Window & orig);
    virtual ~Window();
    void load();
    void destroy();
    void display();

    int getW() const {
        return w;
    }

    int getH() const {
        return h;
    }
};

#endif	/* SCENESDL_H */

