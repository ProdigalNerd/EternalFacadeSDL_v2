//
// Created by Tyler Wilson on 3/14/18.
//

#include "Button.hpp"

#include <iostream>

Button::Button(std::string fontName, std::string text, SDL_Color color, SDL_Color bgColor, int left, int top, int width,
               int height) {
    // Load the font
    std::string base_path = SDL_GetBasePath();
    const char* fontfile = base_path.append("Fonts/NotoMono-Regular.ttf").c_str();
    font = TTF_OpenFont(fontfile, 36);

    // set the button rectangle
    buttonRect.x = left;
    buttonRect.y = top;
    buttonRect.w = width;
    buttonRect.h = height;

    // set font color
    fontColor = color;

    // set background color
    backgroundColor = bgColor;

    // set the text to be rendered
    renderText = text;
}

Button::~Button() {

}

void Button::Render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer,
                           backgroundColor.r,
                           backgroundColor.g,
                           backgroundColor.b,
                           backgroundColor.a);
    const SDL_Rect* rect = &buttonRect;
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderDrawRect(renderer, rect);

    SDL_Surface* renderedFont = RenderFontWithColor(renderText, font, fontColor);

    SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer, renderedFont);

    SDL_FreeSurface(renderedFont);

    SDL_Rect sourceRect, destRect;

    // query to get h/w of the font texture that was created
    SDL_QueryTexture(fontTexture, NULL, NULL, &sourceRect.w, &sourceRect.h);

    sourceRect.x = 0;
    sourceRect.y = 0;
    destRect.x = (buttonRect.x + ((buttonRect.w / 2) - (sourceRect.w / 2))); // center the text horizontally
    destRect.y = (buttonRect.y + ((buttonRect.h / 2) - (sourceRect.h / 2))); // center the text vertically
    destRect.w = sourceRect.w;
    destRect.h = sourceRect.h;

    SDL_RenderCopy(renderer, fontTexture, &sourceRect, &destRect);

    SDL_DestroyTexture(fontTexture);
}

bool Button::CheckForClick(glm::vec2 coords) {
    if(coords.x >= buttonRect.x && coords.x <= (buttonRect.x + buttonRect.w)
            && coords.y >= buttonRect.y && coords.y <= (buttonRect.y + buttonRect.h)){
        return true;
    }
    return false;
}
