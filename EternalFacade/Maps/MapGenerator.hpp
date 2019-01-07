//
// Created by Tyler Wilson on 3/26/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_MAPGENERATOR_HPP
#define ETERNAL_FACADE_SDL_V2_MAPGENERATOR_HPP

#include <cstdio>
#include <map>

#include "GameObjects/DungeonObject/DungeonObject.hpp"
#include "Formulas/FormulaList.hpp"

class MapGenerator {
public:
    MapGenerator();
    ~MapGenerator();

    std::map<std::pair<int, int>, DungeonObject*> GetDungeonMap();
    DungeonObject* GetObjectAtCoords(int x, int y);
    void GenerateDungeonLevel(unsigned int level);
    int GetMaxTilesX();
    int GetMaxTilesY();
    std::pair<int, int> GetPlayerStart();
    DungeonObject* GetTileForCoords(int x, int y);
private:
    std::map<std::pair<int, int>, DungeonObject*> dungeonMap;
    std::pair<int, int> playerStart;
    int maxTilesX;
    int maxTilesY;
    int tile_size;
    FormulaList* formulaList;
};


#endif //ETERNAL_FACADE_SDL_V2_MAPGENERATOR_HPP
