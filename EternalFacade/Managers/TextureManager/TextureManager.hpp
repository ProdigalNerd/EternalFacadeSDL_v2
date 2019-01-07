//
// Created by Tyler Wilson on 3/29/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_TEXTUREMANAGER_HPP
#define ETERNAL_FACADE_SDL_V2_TEXTUREMANAGER_HPP

#include <string>
#include <map>

#include "../../Utils/ITexture/ITexture.hpp"

class TextureManager {
public:
    TextureManager();
    ~TextureManager();

    std::map<std::string, ITexture*> GetAllTextures();
    ITexture* GetTextureByKey(std::string key);

    void CreateTextureForKeyWithPath(std::string key, std::string path, SDL_Renderer* renderer);
private:
    std::map<std::string, ITexture*> textures;
};


#endif //ETERNAL_FACADE_SDL_V2_TEXTUREMANAGER_HPP
