//
// Created by Tyler Wilson on 3/14/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_STATEMANAGER_HPP
#define ETERNAL_FACADE_SDL_V2_STATEMANAGER_HPP

#include <list>

class IGame;
class GameState;

class StateManager {
public:
    explicit StateManager(IGame* game);
    ~StateManager();

    void GoToState(GameState* state);
    void GoToPreviousState();
private:
    std::list<GameState*> stateStack;
    IGame* game_ref;
};


#endif //ETERNAL_FACADE_SDL_V2_STATEMANAGER_HPP
