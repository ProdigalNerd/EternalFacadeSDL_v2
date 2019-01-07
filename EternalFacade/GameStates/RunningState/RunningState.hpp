//
// Created by Tyler Wilson on 3/13/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_RUNNINGSTATE_HPP
#define ETERNAL_FACADE_SDL_V2_RUNNINGSTATE_HPP

#include "../GameState.hpp"

class RunningState : public GameState {
public:
    RunningState();
    ~RunningState();

    void OnEnter() override;

    void OnExit() override;

    void Update() override;

    void Draw(SDL_Renderer* renderer) override;
};

#endif //ETERNAL_FACADE_SDL_V2_RUNNINGSTATE_HPP
