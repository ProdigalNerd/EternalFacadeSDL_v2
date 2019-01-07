//
// Created by Tyler Wilson on 3/26/18.
//

#include "CellularAutomata.hpp"

#include <random>

using namespace std;

CellularAutomata::CellularAutomata() {

}

CellularAutomata::~CellularAutomata() {

}

map<pair<int, int>, DungeonObject *> CellularAutomata::GenerateGrid(unsigned int level) {
    map<pair<int, int>, DungeonObject*> newGrid;
    map<pair<int, int>, DungeonObject*> gridCopy;

    // initialize the random engine
    std::mt19937 mt(level);
    std::uniform_int_distribution<int> dist(0, 99);

    // create the base grid initialized as FLOORs
    for(int y = 0; y < max_y; y++) {
        for(int x = 0; x < max_x; x++) {
            newGrid[pair<int, int>(x, y)] = new DungeonObject();
            newGrid[pair<int, int>(x, y)]->SetTileType(TileType::Floor);
        }
    }

    gridCopy = newGrid;

    // cycle through the grid to place some random walls
    map<pair<int, int>, DungeonObject*>::iterator it;
    for(it = newGrid.begin(); it != newGrid.end(); ++it) {
        if (dist(mt) > wall_probability) {
            gridCopy[it->first]->SetTileType(TileType::Wall);
        }
        else {
            gridCopy[it->first]->SetTileType(TileType::Floor);
        }
    }

    newGrid = gridCopy;

    // start processing generations
    for(int i = 0; i < generations; i++) {
        newGrid = ProcessGeneration(newGrid);
    }

    return newGrid;
}

map<pair<int, int>, DungeonObject *> CellularAutomata::ProcessGeneration(map<pair<int, int>, DungeonObject *> &map_grid) {
    map<pair<int, int>, DungeonObject*> tmp_map = map_grid;
    map<pair<int, int>, DungeonObject*>::iterator mapit;
    for(mapit = map_grid.begin(); mapit != map_grid.end(); ++mapit) {
        pair<int, int> coord = mapit->first;

        if(coord.first == 0
           || coord.second == 0
           || coord.first == (max_x - 1)
           || coord.second == (max_y - 1)) {
            tmp_map[coord]->SetTileType(TileType::Wall);
        }
        else {
            tuple<int, int> matches = CheckTileMatch(coord,
                                                     TileType::Wall,
                                                     map_grid);
            int adj = get<0>(matches);
            int diag = get<1>(matches);
            DungeonObject* current = mapit->second;

            if((adj + diag) > 4) {
                tmp_map[coord]->SetTileType(TileType::Wall);
            }
            else if((adj + diag) < 4) {
                tmp_map[coord]->SetTileType(TileType::Floor);
            }
            else {
                tmp_map[coord] = current;
            }
        }
    }

    return tmp_map;
}

std::tuple<int, int> CellularAutomata::CheckTileMatch(std::pair<int, int> coord, TileType tile,
                                                      std::map<std::pair<int, int>, DungeonObject *> &map_ref) {
    int min_x = coord.first - 1;
    int max_x = coord.first + 1;
    int min_y = coord.second - 1;
    int max_y = coord.second + 1;

    int adj = 0;
    int diag = 0;

    for(int cy = min_y; cy <= max_y; cy++) {
        for(int cx = min_x; cx <= max_x; cx++) {
            pair<int, int> key = pair<int, int>(cx, cy);

            auto keyCheck = map_ref.find(key);
            if(keyCheck == map_ref.end()) {
                continue;
            }

            if(key.first == coord.first and key.second == coord.second) {
                continue;
            }

            if(map_ref[key]->GetTileType() == tile) {
                if(key.first == coord.first || key.second == coord.second) {
                    adj++;
                }
                else {
                    diag++;
                }
            }
        }
    }

    return make_tuple(adj, diag);
}
