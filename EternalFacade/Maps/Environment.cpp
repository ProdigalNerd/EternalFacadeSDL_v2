//
// Created by Tyler Wilson on 4/18/18.
//

#include "Environment.hpp"

#include <random>

Environment::Environment() {
    mapGenerator = new MapGenerator();
    GoToLevel(1);
}

Environment::~Environment() {

}

void Environment::Update() {

}

void Environment::Draw(SDL_Renderer *renderer, ITexture *texture, int startX, int startY, int viewX, int viewY) {
    for (int y = 0; y < viewY; y++) {
        for (int x = 0; x < viewX; x++) {
            if ((startX + x) >= 0 && (startY + y) >= 0 && (startX + x) < mapGenerator->GetMaxTilesX() &&
                (startY + y) < mapGenerator->GetMaxTilesY()) {
                DungeonObject* tile = mapGenerator->GetTileForCoords(startX + x, startY + y);
                std::list<SDL_Rect> tileRects = tile->GetClipRects();

                for (auto it = tileRects.begin(); it != tileRects.end(); ++it) {
                    texture->render(x * tile_size, y * tile_size, &(*it), renderer);
                }
            }
        }
    }
}

bool Environment::CanMoveToTile(int x, int y) {
    DungeonObject* destTile = mapGenerator->GetTileForCoords(x, y);

    if(destTile->GetTileType() == TileType::Floor) {
        return true;
    }
    return false;
}

void Environment::GoToLevel(unsigned int level) {
    currentLevel = level;
    mapGenerator->GenerateDungeonLevel(level);
}

int Environment::GetMapWidth() {
    return tiles_x;
}

int Environment::GetMapHeight() {
    return tiles_y;
}

int Environment::GetTileSize() {
    return tile_size;
}

std::pair<int, int> Environment::GetRandomFloorCoords() {
    return mapGenerator->GetPlayerStart();
}
