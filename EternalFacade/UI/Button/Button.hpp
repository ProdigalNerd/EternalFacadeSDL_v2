//
// Created by Tyler Wilson on 3/14/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_BUTTON_HPP
#define ETERNAL_FACADE_SDL_V2_BUTTON_HPP

#include <SDL2/SDL.h>
#include <SDL2_TTF/SDL_ttf.h>
#include <cstdio>
#include <string>
#include <glm/glm.hpp>

#include "../../Utils/RenderFont/RenderFont.hpp"

class Button {
public:
    Button(std::string fontName, std::string text,
           SDL_Color color,
           SDL_Color bgColor,
           int left, int top,
           int width, int height);
    ~Button();

    void Render(SDL_Renderer* renderer);
    bool CheckForClick(glm::vec2 coords);
private:
    TTF_Font* font;
    std::string renderText;
    SDL_Rect buttonRect;
    SDL_Color fontColor;
    SDL_Color backgroundColor;
};


#endif //ETERNAL_FACADE_SDL_V2_BUTTON_HPP
