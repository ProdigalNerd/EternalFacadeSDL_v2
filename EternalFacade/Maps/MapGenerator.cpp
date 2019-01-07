//
// Created by Tyler Wilson on 3/26/18.
//

#include "MapGenerator.hpp"
#include <random>
#include "../Utils/AStar/AStar.hpp"
#include "../Utils/AStar/Node/Node.hpp"

MapGenerator::MapGenerator() {
    this -> tile_size = 32;
    formulaList = new FormulaList();
}

MapGenerator::~MapGenerator() {

}

int MapGenerator::GetMaxTilesX() {
    return maxTilesX;
}

int MapGenerator::GetMaxTilesY() {
    return maxTilesY;
}

std::map<std::pair<int, int>, DungeonObject *> MapGenerator::GetDungeonMap() {
    return dungeonMap;
}

DungeonObject* MapGenerator::GetObjectAtCoords(int x, int y) {
    return dungeonMap[std::make_pair(x, y)];
}

void MapGenerator::GenerateDungeonLevel(unsigned int level) {
    BaseFormula* mapFormula = formulaList->GetRandomFormulaForLevel(level);
    maxTilesX = mapFormula->max_x;
    maxTilesY = mapFormula->max_y;
    dungeonMap = mapFormula->GenerateGrid(level);

    std::mt19937 mt(level);
    int ft_length = (int)mapFormula->floor_tiles.size();
    int wt_length = (int)mapFormula->wall_tiles.size();

    bool bStartCreated = false;

    std::uniform_int_distribution<int> floorDist(0, ft_length - 1);
    std::uniform_int_distribution<int> wallDist(0, wt_length - 1);
    std::uniform_int_distribution<int> rndPct(0, 100);

    AStar pathFinder(this);
    std::pair<int, int> lastFloorTile;
    std::map<std::pair<int, int>, DungeonObject*>::iterator dmIt;
    for(dmIt = dungeonMap.begin(); dmIt != dungeonMap.end(); ++dmIt) {
        std::pair<int, int> key = dmIt->first;
        TileType type = dmIt->second->GetTileType();

        auto rfit = mapFormula->floor_tiles.begin();
        std::advance(rfit, floorDist(mt));
        std::pair<int, int> texture_coord = (*rfit);

        SDL_Rect floorRect;
        floorRect.x = (int)std::get<0>(texture_coord);
        floorRect.y = (int)std::get<1>(texture_coord);
        floorRect.w = tile_size;
        floorRect.h = tile_size;

        dmIt->second->AddClipRect(floorRect);

        std::pair<int, int> texture_coord2;
        std::list<std::pair<int, int>>::iterator rwit;
        switch(type) {
            case TileType::Wall:
                rwit = mapFormula->wall_tiles.begin();
                std::advance(rwit, wallDist(mt));
                texture_coord2 = (*rwit);

                SDL_Rect wallRect;
                wallRect.x = (int)std::get<0>(texture_coord2);
                wallRect.y = (int)std::get<1>(texture_coord2);
                wallRect.w = tile_size;
                wallRect.h = tile_size;

                dmIt->second->AddClipRect(wallRect);
                break;

            case TileType::Floor:
                if(!bStartCreated) {
                    playerStart = dmIt->first;
                    bStartCreated = true;
                }
                break;
        }
    }

    if(!pathFinder.DoesPathExist(playerStart, dmIt->first)) {
        std::list<Node*> pathToEnd = pathFinder.BruteForcePath(playerStart, dmIt->first);

        std::list<Node*>::iterator nIt;
        for(nIt = pathToEnd.begin(); nIt != pathToEnd.end(); ++nIt) {
            dungeonMap[(*nIt)->pos]->SetTileType(TileType::Floor);
            dungeonMap[(*nIt)->pos]->ClearClipRects();

            auto rfit = mapFormula->floor_tiles.begin();
            std::advance(rfit, floorDist(mt));
            std::pair<int, int> texture_coord = (*rfit);

            SDL_Rect floorRect;
            floorRect.x = (int)std::get<0>(texture_coord);
            floorRect.y = (int)std::get<1>(texture_coord);
            floorRect.w = tile_size;
            floorRect.h = tile_size;

            dungeonMap[(*nIt)->pos]->AddClipRect(floorRect);
        }
    }

    delete mapFormula;
}

std::pair<int, int> MapGenerator::GetPlayerStart() {
    return playerStart;
}

DungeonObject *MapGenerator::GetTileForCoords(int x, int y) {
    return dungeonMap[std::pair<int, int>(x, y)];
}

