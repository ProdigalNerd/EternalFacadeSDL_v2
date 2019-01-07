//
// Created by Tyler Wilson on 3/14/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_IGAME_HPP
#define ETERNAL_FACADE_SDL_V2_IGAME_HPP

#include "../../GameStates/GameState.hpp"

class IGame {
public:
    IGame();
    virtual ~IGame();

    virtual void SetState(GameState* state) = 0;
};


#endif //ETERNAL_FACADE_SDL_V2_IGAME_HPP
