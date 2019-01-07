//
// Created by Tyler Wilson on 4/11/18.
//

#include "Player.hpp"

#include <iostream>

Player::Player(InputManager *manInput) {
    inputManager = manInput;
    InitializeConfig();
    InitializeClipRect();
}

Player::~Player() {

}

void Player::Update() {
    std::pair<int, int> movementVector;
    if(inputManager->isKeyPressed(SDLK_UP) || inputManager->isKeyPressed(SDLK_w)) {
        movementVector = std::make_pair(0, -1);
    }
    else if(inputManager->isKeyPressed(SDLK_DOWN) || inputManager->isKeyPressed(SDLK_s)) {
        movementVector = std::make_pair(0, 1);
    }
    else if(inputManager->isKeyPressed(SDLK_LEFT) || inputManager->isKeyPressed(SDLK_a)) {
        movementVector = std::make_pair(-1, 0);
    }
    else if(inputManager->isKeyPressed(SDLK_RIGHT) || inputManager->isKeyPressed(SDLK_d)) {
        movementVector = std::make_pair(1, 0);
    }

    if(env->CanMoveToTile(worldCoords.first + movementVector.first, worldCoords.second + movementVector.second)){
        worldCoords.first = worldCoords.first + movementVector.first;
        worldCoords.second = worldCoords.second + movementVector.second;
    }
}

void Player::InitializePosition(int x, int y) {
    worldCoords = std::make_pair(x, y);
}

std::pair<int, int> Player::GetWorldCoordinates() {
    return worldCoords;
}

void Player::InitializeConfig() {
    libconfig::Config _screenCfg;
    // Load the config file to define screen properties
    try {
        _screenCfg.setIncludeDir("Configs");
        std::string base_path = SDL_GetBasePath();
        const char* filename = base_path.append("Configs/characters/race.cfg").c_str();
        _screenCfg.readFile(filename);

        const libconfig::Setting& root = _screenCfg.getRoot();

        // TODO make more dynamic

        imgX = root["male"][4]["x"];
        imgY = root["male"][4]["y"];
    }
    catch(const libconfig::FileIOException& fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
    }
    catch(const libconfig::ParseException &pex)
    {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
    }
}

void Player::InitializeClipRect() {
    clipRect.x = imgX;
    clipRect.y = imgY;
    clipRect.w = 32;
    clipRect.h = 32;
}

SDL_Rect* Player::GetClipRect() {
    return &clipRect;
}

void Player::SetEnvironment(Environment *environment) {
    env = environment;
}
