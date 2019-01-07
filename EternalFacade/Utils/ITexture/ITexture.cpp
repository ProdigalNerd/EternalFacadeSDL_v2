//
// Created by Tyler Wilson on 3/29/18.
//

#include "ITexture.hpp"

ITexture::ITexture() {
    texture = nullptr;
}

ITexture::~ITexture() {

}

ITexture* ITexture::GetTexture() {
    return this;
}

SDL_Texture* ITexture::GetSDLTexture() {
    return texture;
}

bool ITexture::loadFromFile(std::string* path, SDL_Renderer* renderer) {
    // in case a different texture was already loaded free it up
    free();

    // load support for the JPG and PNG image formats
    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted=IMG_Init(flags);
    if((initted&flags) != flags) {
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
        // handle error
    }

    //The final texture
    texture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path->c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path->c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( texture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path->c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            width = loadedSurface->w;
            height = loadedSurface->h;
        }

        SDL_FreeSurface( loadedSurface );
    }

    return texture != nullptr;
}

void ITexture::free() {
    if( texture != nullptr )
    {
        SDL_DestroyTexture( texture );
        texture = nullptr;
        width = 0;
        height = 0;
    }
}

void ITexture::render(int x, int y, SDL_Rect *clip, SDL_Renderer* renderer) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, width, height };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopy( renderer, texture, clip, &renderQuad );
}

int ITexture::getWidth() {
    return width;
}

int ITexture::getHeight() {
    return height;
}
