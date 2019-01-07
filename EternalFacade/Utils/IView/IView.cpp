//
// Created by Tyler Wilson on 3/15/18.
//

#include "IView.hpp"

IView::IView() {

}

IView::~IView() {

}

void IView::LoadViewConfig() {
    libconfig::Config _screenCfg;
    // Load the config file to define screen properties
    try {
        _screenCfg.setIncludeDir("Resources/Configs");
        std::string base_path = SDL_GetBasePath();
        const char* filename = base_path.append("Configs/Views/" + viewConfigName + ".cfg").c_str();
        _screenCfg.readFile(filename);

        const libconfig::Setting& root = _screenCfg.getRoot();

        viewRect.w = root["width"];
        viewRect.h = root["height"];
        viewRect.x = root["offset_x"];
        viewRect.y = root["offset_y"];
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
