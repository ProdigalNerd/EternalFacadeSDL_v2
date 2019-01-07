//
// Created by Tyler Wilson on 3/14/18.
//

#include "RenderFont.hpp"

SDL_Surface* RenderFontWithColor(std::string text, TTF_Font *font, SDL_Color color) {
    SDL_Surface* text_surface;
    if(!(text_surface = TTF_RenderText_Solid(font, text.c_str(), color))) {

    }
    return text_surface;
}
