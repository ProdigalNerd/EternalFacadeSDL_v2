//
// Created by Tyler Wilson on 4/11/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_PLAYER_HPP
#define ETERNAL_FACADE_SDL_V2_PLAYER_HPP

#include <cstdio>
#include <utility>
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <libconfig.h++>
#include <Managers/InputManager/InputManager.hpp>

#include "GameObjects/Character/Character.hpp"
#include "Maps/Environment.hpp"

class Player : public Character {
public:
    Player(InputManager *manInput);
    ~Player();

    void Update() override;
    void InitializePosition(int x, int y);
    void SetEnvironment(Environment* environment);
    std::pair<int, int> GetWorldCoordinates();
    SDL_Rect* GetClipRect();

private:
    // TODO make dynamic in future via character creation screen
    void InitializeConfig();
    void InitializeClipRect();

    InputManager* inputManager;
    Environment* env;

    std::pair<int, int> worldCoords;
    int imgX;
    int imgY;
    SDL_Rect clipRect;
};


#endif //ETERNAL_FACADE_SDL_V2_PLAYER_HPP
