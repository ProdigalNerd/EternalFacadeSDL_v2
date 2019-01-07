//
// Created by Tyler Wilson on 3/13/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_MAINMENUSTATE_HPP
#define ETERNAL_FACADE_SDL_V2_MAINMENUSTATE_HPP

#include <map>

#include "../GameState.hpp"
#include "../../UI/Button/Button.hpp"
#include "../ExitingState/ExitingState.hpp"
#include "../PlayingState/PlayingState.hpp"

class MainMenuState : public GameState {
public:
    MainMenuState(InputManager *manInput, StateManager *manState, TextureManager *manTexture);
    ~MainMenuState();

    void OnEnter() override;

    void OnExit() override;

    void Update() override;

    void Draw(SDL_Renderer* renderer) override;

private:
    std::map<std::string, Button*> menuButtons;
};


#endif //ETERNAL_FACADE_SDL_V2_MAINMENUSTATE_HPP
