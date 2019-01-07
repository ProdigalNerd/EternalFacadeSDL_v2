//
//  EternalFacade.hpp
//  Eternal Facade SDL
//
//  Created by Tyler Wilson on 2/27/18.
//  Copyright © 2018 Tyler Wilson. All rights reserved.
//

#ifndef EternalFacade_hpp
#define EternalFacade_hpp

#include <stdio.h>
#include <iostream>

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <SDL2_ttf/SDL_ttf.h>
#include <libconfig.h++>

#include "DataModels/ScreenConfig.hpp"
#include "GameStates/GameStateIncludes.hpp"
#include "Managers/InputManager/InputManager.hpp"
#include "Managers/TextureManager/TextureManager.hpp"
#include "Utils/IGame/IGame.hpp"

class StateManager;

class EternalFacade : public IGame{
public:
    EternalFacade();
    ~EternalFacade();

    GameState* GetState();
    void SetState(GameState* state) override;
private:
    void LoadConfigVars();
    void InitializeWindow();
    void InitializeTextures();
    void RunEngine();
    bool IsRunning();
    void OnSDLEvent(SDL_Event& event);

    GameState* currentState;
    ScreenConfig cfg;
    SDL_Window* window;
    SDL_Renderer* renderer;


    InputManager* inputManager;
    StateManager* stateManager;
    TextureManager* textureManager;
};

#endif /* EternalFacade_hpp */