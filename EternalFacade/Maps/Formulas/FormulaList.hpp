//
// Created by Tyler Wilson on 3/26/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_FORMULALIST_HPP
#define ETERNAL_FACADE_SDL_V2_FORMULALIST_HPP

#include "FormulaIncludes.hpp"

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <libconfig.h++>

#include <iostream>
#include <string>
#include <map>
#include <list>

class FormulaList {
public:
    FormulaList();
    ~FormulaList();

    BaseFormula* GetRandomFormulaForLevel(unsigned int level);
    BaseFormula* GetFormulaByName(std::string formulaName);
private:
    void InitializeFileNames();
    void InitializeList();
    std::list<std::pair<int, int>> ParseTileList(libconfig::Setting& setting);
    std::list<std::string> fileNames;
    std::map<std::string, BaseFormula*> formulaList;
};


#endif //ETERNAL_FACADE_SDL_V2_FORMULALIST_HPP
