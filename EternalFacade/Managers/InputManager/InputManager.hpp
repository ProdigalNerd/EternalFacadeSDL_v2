//
// Created by Tyler Wilson on 3/13/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_INPUTMANAGER_HPP
#define ETERNAL_FACADE_SDL_V2_INPUTMANAGER_HPP

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <unordered_map>
#include <glm/glm.hpp>

class InputManager {
public:
    InputManager();
    ~InputManager();

    void Update();
    void KeyPress(SDL_Keycode keyID);
    void KeyRelease(SDL_Keycode keyID);
    bool isKeyDown(unsigned int keyID);
    bool isKeyPressed(unsigned int keyID);
    void SetMouseCoords(float x, float y);
    glm::vec2 GetMouseCoords() const { return mouseCoords; };
private:
    bool wasKeyDown(unsigned int keyID);
    std::unordered_map<unsigned int, bool> keyMap;
    std::unordered_map<unsigned int, bool> previousKeyMap;
    glm::vec2 mouseCoords;
};

#endif //ETERNAL_FACADE_SDL_V2_INPUTMANAGER_HPP
