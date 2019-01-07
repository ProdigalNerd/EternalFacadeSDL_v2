//
// Created by Tyler Wilson on 3/26/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_CELLULARAUTOMATA_HPP
#define ETERNAL_FACADE_SDL_V2_CELLULARAUTOMATA_HPP

#include "../BaseFormula.hpp"
#include "../../../DataModels/Enums/TileType.hpp"

class CellularAutomata : public BaseFormula {
public:
    CellularAutomata();
    ~CellularAutomata();

    std::map<std::pair<int, int>, DungeonObject *> GenerateGrid(unsigned int level) override;
private:
    std::map<std::pair<int, int>, DungeonObject *> ProcessGeneration(std::map<std::pair<int, int>, DungeonObject*>& map_grid);
    std::tuple<int, int> CheckTileMatch(std::pair<int, int> coord,
                                        TileType tile,
                                        std::map<std::pair<int, int>, DungeonObject *> &map_ref);
};


#endif //ETERNAL_FACADE_SDL_V2_CELLULARAUTOMATA_HPP
