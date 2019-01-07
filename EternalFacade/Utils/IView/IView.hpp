//
// Created by Tyler Wilson on 3/15/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_IVIEW_HPP
#define ETERNAL_FACADE_SDL_V2_IVIEW_HPP

#include <cstdio>
#include <iostream>
#include <string>
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <libconfig.h++>

class IView {
public:
    IView();
    ~IView();

    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual void Update() = 0;
    virtual void Draw(SDL_Renderer* renderer) = 0;
protected:
    void LoadViewConfig();

    std::string viewConfigName;
    SDL_Rect viewRect;
    bool isActive;
};


#endif //ETERNAL_FACADE_SDL_V2_IVIEW_HPP
