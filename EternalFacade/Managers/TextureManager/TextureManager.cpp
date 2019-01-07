//
// Created by Tyler Wilson on 3/29/18.
//

#include "TextureManager.hpp"

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {
    std::map<std::string, ITexture*>::iterator it;
    for(it = textures.begin(); it != textures.end(); ++it) {
        it->second->free();
    }
}

std::map<std::string, ITexture*> TextureManager::GetAllTextures() {
    return textures;
}

ITexture* TextureManager::GetTextureByKey(std::string key) {
    return textures[key]->GetTexture();
}

void TextureManager::CreateTextureForKeyWithPath(std::string key, std::string path, SDL_Renderer* renderer) {
    textures[key] = new ITexture();
    if(!textures[key]->loadFromFile(&path, renderer)) {
        printf("Error creating texture");
    }
}
