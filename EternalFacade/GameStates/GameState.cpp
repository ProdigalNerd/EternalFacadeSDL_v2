//
// Created by Tyler Wilson on 3/13/18.
//

#include <Managers/TextureManager/TextureManager.hpp>
#include "../Managers/InputManager/InputManager.hpp"
#include "../Managers/StateManager/StateManager.hpp"
#include "GameState.hpp"

GameState::GameState(InputManager *manInput, StateManager *manState, TextureManager *manTexture) {
    inputManager = manInput;
    stateManager = manState;
    textureManager = manTexture;
}

GameState::~GameState() {
    if(inputManager != nullptr) {
        delete inputManager;
    }
    if(stateManager != nullptr) {
        delete stateManager;
    }
    if(textureManager != nullptr) {
        delete textureManager;
    }
}

std::string GameState::GetStateName() {
    return stateName;
}
