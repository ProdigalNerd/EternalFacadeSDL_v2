//
// Created by Tyler Wilson on 5/2/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_CHARACTER_HPP
#define ETERNAL_FACADE_SDL_V2_CHARACTER_HPP

#include "../GameObject.hpp"

class Character : GameObject {
public:
    Character();
    ~Character();

    virtual void Update() override;
};


#endif //ETERNAL_FACADE_SDL_V2_CHARACTER_HPP
