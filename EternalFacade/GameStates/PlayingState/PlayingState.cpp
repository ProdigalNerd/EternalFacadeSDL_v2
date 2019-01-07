//
// Created by Tyler Wilson on 3/15/18.
//

#include "PlayingState.hpp"

PlayingState::PlayingState(InputManager *manInput, StateManager *manState, TextureManager *manTexture)
        : GameState(manInput, manState, manTexture) {
    OnEnter();
}

PlayingState::~PlayingState() {
    OnExit();
}

void PlayingState::OnEnter() {
    stateName = "Playing";
    CreatePlayerObject();
    InitializeViews();
}

void PlayingState::OnExit() {

}

void PlayingState::Update() {
    std::list<IView*>::iterator it;
    for(it = views.begin(); it != views.end(); ++it) {
        (*it)->Update();
    }
}

void PlayingState::Draw(SDL_Renderer *renderer) {
    std::list<IView*>::iterator it;
    for(it = views.begin(); it != views.end(); ++it) {
        (*it)->Draw(renderer);
    }
}

void PlayingState::InitializeViews() {
    views.push_back(new DungeonView(textureManager, player));
}

void PlayingState::CreatePlayerObject() {
    player = new Player(inputManager);
}
