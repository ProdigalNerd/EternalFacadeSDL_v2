//
// Created by Tyler Wilson on 3/14/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_RENDERFONT_HPP
#define ETERNAL_FACADE_SDL_V2_RENDERFONT_HPP


#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>

SDL_Surface* RenderFontWithColor(std::string text,
                                 TTF_Font* font,
                                 SDL_Color color);


#endif //ETERNAL_FACADE_SDL_V2_RENDERFONT_HPP
