//
// Created by Tyler Wilson on 3/13/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_GAMESTATE_HPP
#define ETERNAL_FACADE_SDL_V2_GAMESTATE_HPP

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <string>

#include "../Managers/InputManager/InputManager.hpp"
#include "../Managers/TextureManager/TextureManager.hpp"

class StateManager;

class GameState {
public:
    GameState(InputManager *manInput, StateManager *manState, TextureManager *manTexture);
    ~GameState();

    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual void Update() = 0;
    virtual void Draw(SDL_Renderer* renderer) = 0;

    std::string GetStateName();
protected:
    std::string stateName;
    InputManager* inputManager;
    StateManager* stateManager;
    TextureManager* textureManager;
};

#endif //ETERNAL_FACADE_SDL_V2_GAMESTATE_HPP
