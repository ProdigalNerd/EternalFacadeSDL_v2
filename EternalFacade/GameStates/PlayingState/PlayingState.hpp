//
// Created by Tyler Wilson on 3/15/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_PLAYINGSTATE_HPP
#define ETERNAL_FACADE_SDL_V2_PLAYINGSTATE_HPP

#include <list>

#include "../GameState.hpp"
#include "../../Views/ViewIncludes.hpp"
#include "../../GameObjects/Character/Player/Player.hpp"

class PlayingState : public GameState {
public:
    PlayingState(InputManager *manInput, StateManager *manState, TextureManager *manTexture);
    ~PlayingState();

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    void Draw(SDL_Renderer* renderer) override;
private:
    // Initialize Player
    // TODO make dynamic with new character screen
    void CreatePlayerObject();
    void InitializeViews();

    std::list<IView*> views;
    Player* player;
};


#endif //ETERNAL_FACADE_SDL_V2_PLAYINGSTATE_HPP
