//
// Created by Tyler Wilson on 4/18/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_ENVIRONMENT_HPP
#define ETERNAL_FACADE_SDL_V2_ENVIRONMENT_HPP

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <libconfig.h++>
#include <memory>

#include "../Utils/ITexture/ITexture.hpp"
#include "MapGenerator.hpp"

class Environment {
public:
    Environment();
    ~Environment();

    void Update();
    void Draw(SDL_Renderer *renderer, ITexture *texture, int startX, int startY, int viewX, int viewY);

    bool CanMoveToTile(int x, int y);
    void GoToLevel(unsigned int level);

    int GetMapWidth();
    int GetMapHeight();
    int GetTileSize();

    std::pair<int, int> GetRandomFloorCoords();
private:
    MapGenerator* mapGenerator;

    unsigned int currentLevel;
    int tiles_x;
    int tiles_y;
    const int tile_size = 32;
};


#endif //ETERNAL_FACADE_SDL_V2_ENVIRONMENT_HPP
