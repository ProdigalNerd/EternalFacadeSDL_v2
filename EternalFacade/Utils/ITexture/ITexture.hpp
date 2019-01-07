//
// Created by Tyler Wilson on 3/29/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_ITEXTURE_HPP
#define ETERNAL_FACADE_SDL_V2_ITEXTURE_HPP

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <SDL2_IMAGE/SDL_image.h>
#include <string>

class ITexture {
public:
    ITexture();
    ~ITexture();

    //Loads image at specified path
    bool loadFromFile( std::string* path, SDL_Renderer* renderer );

    //Deallocates texture
    void free();

    // Return the texture to store in the Texture Manager
    ITexture* GetTexture();
    SDL_Texture* GetSDLTexture();

    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip, SDL_Renderer* renderer);

    //Gets image dimensions
    int getWidth();
    int getHeight();
private:
    SDL_Texture* texture;

    //Image dimensions
    int width;
    int height;
};


#endif //ETERNAL_FACADE_SDL_V2_ITEXTURE_HPP
