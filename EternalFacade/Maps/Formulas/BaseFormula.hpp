//
// Created by Tyler Wilson on 3/26/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_BASEFOMULA_HPP
#define ETERNAL_FACADE_SDL_V2_BASEFOMULA_HPP

#include <string>
#include <map>
#include <libconfig.h++>

#include "GameObjects/DungeonObject/DungeonObject.hpp"

class BaseFormula {
public:
    BaseFormula();
    virtual ~BaseFormula();

    virtual std::map<std::pair<int, int>, DungeonObject *> GenerateGrid(unsigned int level) = 0;

    std::string name;
    std::string gen_type;
    std::string biome;
    unsigned int max_x;
    unsigned int max_y;
    unsigned int level_min;
    unsigned int level_max;
    bool isRandom;
    bool fillEmpty;

    // cellular automata
    int wall_probability;
    int generations;

    std::list<std::pair<int, int>> floor_tiles;
    std::list<std::pair<int, int>> wall_tiles;
};


#endif //ETERNAL_FACADE_SDL_V2_BASEFOMULA_HPP
