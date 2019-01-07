//
// Created by Tyler Wilson on 3/26/18.
//

#include "FormulaList.hpp"
#include <random>

FormulaList::FormulaList() {
    InitializeFileNames();
    InitializeList();
}

FormulaList::~FormulaList() {

}

/**
 * Find all formula that contain the level being created
 * then using the level as the random seed
 * grab a random formula from the list
 * @param level
 * @return
 */
BaseFormula* FormulaList::GetRandomFormulaForLevel(unsigned int level) {
    if(!formulaList.empty()) {
        std::list<BaseFormula *> potentialList;
        std::map<std::string, BaseFormula *>::iterator flIt;
        for (flIt = formulaList.begin(); flIt != formulaList.end(); ++flIt) {
            if (flIt->second->level_min <= level && flIt->second->level_max >= level) {
                potentialList.push_back(flIt->second);
            }
        }

        srand(level);

        // TODO use the c++ 11 library. Might already be a wrapper class worth using
        unsigned long rndLvl = std::rand() % potentialList.size();

        // based on ide recommendation use auto instead of long hand type
        auto it = std::next(potentialList.begin(), rndLvl);

        return (*it);
    }

    return nullptr;
}

BaseFormula* FormulaList::GetFormulaByName(std::string formulaName) {
    return formulaList[formulaName];
}

void FormulaList::InitializeFileNames() {
    std::string baseFilePath = SDL_GetBasePath();
    // TODO populate off of formulas directory
    fileNames.push_back(baseFilePath.append("Configs/formulas/forest.cfg"));
}

/**
 * Generate the list of formulas used in the game.
 * parse the libconfig into baseformula objects that will be used to generate the map
 * Any formulas that have tilesets need to have them passed into the constructor to initialize constants
 */
void FormulaList::InitializeList() {
    std::list<std::string>::iterator fnIt;
    for(fnIt = fileNames.begin(); fnIt != fileNames.end(); ++fnIt) {
        libconfig::Config formulaConfig;

        // Load the config file to define screen properties
        try {
            formulaConfig.setIncludeDir("Configs");
            std::string base_path = SDL_GetBasePath();
            const char* filename = fnIt->c_str();
            formulaConfig.readFile(filename);

            const libconfig::Setting& root = formulaConfig.getRoot();

            BaseFormula* newFormula;

            std::string type = root["gen_type"].c_str();

            if(type == "automata") {
                // pass the tilesets into the constructor to initialize the const references
                newFormula = new CellularAutomata();

                if(root.exists("wall_probability")) {
                    newFormula->wall_probability = root["wall_probability"];
                }

                if(root.exists("generations")) {
                    newFormula->generations = root["generations"];
                }
            }

            newFormula->name = root["name"].c_str();
            newFormula->biome = root["biome"].c_str();
            newFormula->gen_type = root["gen_type"].c_str();
            newFormula->max_x = root["max_x"];
            newFormula->max_y = root["max_y"];
            newFormula->level_min = root["level_min"];
            newFormula->level_max = root["level_max"];
            newFormula->isRandom = root["random"];
            newFormula->fillEmpty = root["fill_empty"];

            if(root["floor_tiles"].getLength() > 0) {
                newFormula->floor_tiles = ParseTileList(root["floor_tiles"]);
            }

            if(root["wall_tiles"].getLength() > 0) {
                newFormula->wall_tiles = ParseTileList(root["wall_tiles"]);
            }

            formulaList[newFormula->name] = newFormula;
        }
        catch(const libconfig::FileIOException& fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
        }
        catch(const libconfig::ParseException &pex)
        {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                      << " - " << pex.getError() << std::endl;
        }
    }
}

std::list<std::pair<int, int>> FormulaList::ParseTileList(libconfig::Setting& setting) {
    std::list<std::pair<int, int>> tmpList;

    for(int i = 0; i < setting.getLength(); i++) {
        int x, y;
        setting[i].lookupValue("x", x);
        setting[i].lookupValue("y", y);
        tmpList.emplace_back(std::pair<int, int>(x, y));
    }

    return tmpList;
}
