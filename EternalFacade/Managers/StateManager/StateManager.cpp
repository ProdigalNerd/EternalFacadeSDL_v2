
//
// Created by Tyler Wilson on 3/14/18.
//

#include "StateManager.hpp"

#include "../../Utils/IGame/IGame.hpp"


StateManager::StateManager(IGame *game) {
    game_ref = game;
}

StateManager::~StateManager() {
    delete game_ref;
}

void StateManager::GoToState(GameState *state) {
    stateStack.push_front(state);
    game_ref->SetState(state);
}

void StateManager::GoToPreviousState() {
    if (!stateStack.empty()) {
        game_ref->SetState(stateStack.front());

        stateStack.pop_front();
    }
}
