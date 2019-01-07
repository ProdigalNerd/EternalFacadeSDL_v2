//
// Created by Tyler Wilson on 3/13/18.
//
#include <SDL2/SDL_keycode.h>
#include "InputManager.hpp"

InputManager::InputManager() : mouseCoords(0.0f) {

}

InputManager::~InputManager() {

}

void InputManager::Update() {
    if(!keyMap.empty()) {
        for (auto &iter : keyMap) {
            previousKeyMap[iter.first] = iter.second;
        }
    }
}

void InputManager::KeyPress(SDL_Keycode keyID) {
    keyMap[keyID] = true;
}

void InputManager::KeyRelease(SDL_Keycode keyID) {
    keyMap[keyID] = false;
}

bool InputManager::isKeyDown(unsigned int keyID) {
    if(!keyMap.empty()) {
        auto key = keyMap.find(keyID);
        if (key != keyMap.end()) {
            return key->second;   // Found the key
        }
    }
    return false;
}

bool InputManager::wasKeyDown(unsigned int keyID) {
    if(!previousKeyMap.empty()) {
        auto key = previousKeyMap.find(keyID);
        if (key != previousKeyMap.end()) {
            return key->second;
        }
    }
    return false;
}

bool InputManager::isKeyPressed(unsigned int keyID) {
    if(isKeyDown(keyID) && !wasKeyDown(keyID))
    {
        return true;
    }
    return false;
}

void InputManager::SetMouseCoords(float x, float y) {
    mouseCoords.x = x;
    mouseCoords.y = y;
}

