cmake_minimum_required(VERSION 3.9)
project(Eternal_Facade_SDL_V2)

set(CMAKE_CXX_STANDARD 11)

SET(GCC_COVERAGE_LINK_FLAGS    "-lconfig++")

#Set your directories.  The dot representes the root application folder.
#Thus my the path to my domain folder:
set(APP_DOMAIN ./EternalFacade)

#Include the directories and now your cpp files will recognize your headers
include_directories(${APP_DOMAIN})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

find_package(SDL2 REQUIRED)
find_package(SDL2_TTF REQUIRED)
find_package(SDL2_image REQUIRED >=2.0.0)

find_library(CONFIG++_LIBRARY NAMES config++ PATH /usr/lib /usr/local/lib)

add_executable(Eternal_Facade_SDL_V2
        EternalFacade/EternalFacade.cpp
        EternalFacade/EternalFacade.hpp
        main.cpp EternalFacade/Managers/InputManager/InputManager.hpp
        EternalFacade/Managers/InputManager/InputManager.cpp
        EternalFacade/GameStates/GameState.hpp
        EternalFacade/GameStates/GameState.cpp
        EternalFacade/GameStates/RunningState/RunningState.hpp
        EternalFacade/GameStates/RunningState/RunningState.cpp
        EternalFacade/DataModels/ScreenConfig.hpp
        EternalFacade/GameStates/GameStateIncludes.hpp
        EternalFacade/GameStates/MainMenuState/MainMenuState.cpp
        EternalFacade/GameStates/MainMenuState/MainMenuState.hpp
        EternalFacade/GameStates/ExitingState/ExitingState.cpp
        EternalFacade/GameStates/ExitingState/ExitingState.hpp
        EternalFacade/UI/Button/Button.cpp
        EternalFacade/UI/Button/Button.hpp
        EternalFacade/Utils/RenderFont/RenderFont.cpp
        EternalFacade/Utils/RenderFont/RenderFont.hpp
        EternalFacade/Managers/StateManager/StateManager.cpp
        EternalFacade/Managers/StateManager/StateManager.hpp
        EternalFacade/Utils/IGame/IGame.cpp
        EternalFacade/Utils/IGame/IGame.hpp
        EternalFacade/GameStates/PlayingState/PlayingState.cpp
        EternalFacade/GameStates/PlayingState/PlayingState.hpp
        EternalFacade/Utils/IView/IView.cpp
        EternalFacade/Utils/IView/IView.hpp
        EternalFacade/Views/DungeonView/DungeonView.cpp
        EternalFacade/Views/DungeonView/DungeonView.hpp
        EternalFacade/GameObjects/GameObject.cpp
        EternalFacade/GameObjects/GameObject.hpp
        EternalFacade/Views/ViewIncludes.hpp
        EternalFacade/Maps/MapGenerator.cpp
        EternalFacade/Maps/MapGenerator.hpp
        EternalFacade/Maps/Formulas/FormulaList.cpp
        EternalFacade/Maps/Formulas/FormulaList.hpp
        EternalFacade/Maps/Formulas/CellularAutomata/CellularAutomata.cpp
        EternalFacade/Maps/Formulas/CellularAutomata/CellularAutomata.hpp
        EternalFacade/Maps/Formulas/BaseFormula.cpp
        EternalFacade/Maps/Formulas/BaseFormula.hpp
        EternalFacade/GameObjects/DungeonObject/DungeonObject.cpp
        EternalFacade/GameObjects/DungeonObject/DungeonObject.hpp
        EternalFacade/Utils/ITexture/ITexture.cpp
        EternalFacade/Utils/ITexture/ITexture.hpp
        EternalFacade/Managers/TextureManager/TextureManager.cpp
        EternalFacade/Managers/TextureManager/TextureManager.hpp
        EternalFacade/Maps/Formulas/FormulaIncludes.hpp
        EternalFacade/DataModels/Enums/TileType.hpp
        EternalFacade/GameObjects/Character/Player/Player.cpp
        EternalFacade/GameObjects/Character/Player/Player.hpp
        EternalFacade/Maps/Environment.cpp EternalFacade/Maps/Environment.hpp
        EternalFacade/GameObjects/Character/Character.cpp
        EternalFacade/GameObjects/Character/Character.hpp
        EternalFacade/Utils/AStar/AStar.cpp
        EternalFacade/Utils/AStar/AStar.hpp
        EternalFacade/Utils/AStar/Node/Node.cpp
        EternalFacade/Utils/AStar/Node/Node.hpp)
target_link_libraries(Eternal_Facade_SDL_V2 ${SDL2_LIBRARY})
target_link_libraries(Eternal_Facade_SDL_V2 ${SDL2_IMAGE_LIBRARY})
target_link_libraries(Eternal_Facade_SDL_V2 ${SDL2_TTF_LIBRARY})
target_link_libraries(Eternal_Facade_SDL_V2 ${CONFIG++_LIBRARY})

add_custom_command(TARGET Eternal_Facade_SDL_V2 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Resources $<TARGET_FILE_DIR:Eternal_Facade_SDL_V2>)