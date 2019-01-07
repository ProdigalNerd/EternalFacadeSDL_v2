//
// Created by Tyler Wilson on 3/13/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_EXITINGSTATE_HPP
#define ETERNAL_FACADE_SDL_V2_EXITINGSTATE_HPP

#include "../GameState.hpp"

class ExitingState : public GameState {
public:
    ExitingState();
    ~ExitingState();

    void OnEnter() override;

    void OnExit() override;

    void Update() override;

    void Draw(SDL_Renderer* renderer) override;
};


#endif //ETERNAL_FACADE_SDL_V2_EXITINGSTATE_HPP
