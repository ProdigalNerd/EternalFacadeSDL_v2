//
// Created by Tyler Wilson on 3/13/18.
//

#include "MainMenuState.hpp"
#include "../../Managers/StateManager/StateManager.hpp"

MainMenuState::MainMenuState(InputManager *manInput, StateManager *manState, TextureManager *manTexture)
        : GameState(manInput, manState, manTexture) {
    OnEnter();
}

MainMenuState::~MainMenuState() {
    OnExit();
}

void MainMenuState::OnEnter() {
    stateName = "MainMenu";


    SDL_Color fontColor;
    fontColor.r = 255;
    fontColor.g = 255;
    fontColor.b = 255;
    fontColor.a = 255;

    SDL_Color bgColor;
    bgColor.r = 0;
    bgColor.g = 0;
    bgColor.b = 255;
    bgColor.a = 255;

    menuButtons["new_game"] = new Button("NotoMono-Regular",
                                         "New Game",
                                         fontColor,
                                         bgColor,
                                         0, 0,
                                         1024, 150
    );

    menuButtons["exit_game"] = new Button("NotoMono-Regular",
                                          "Exit Game",
                                          fontColor,
                                          bgColor,
                                          0, 250,
                                          1024, 150);
}

void MainMenuState::OnExit() {

}

void MainMenuState::Update() {
    bool clickOccurred = inputManager->isKeyPressed(SDL_BUTTON_LEFT);

    if (clickOccurred) {
        std::map<std::string, Button*>::iterator it;
        for(it = menuButtons.begin(); it != menuButtons.end(); ++it) {
            if(it->second->CheckForClick(inputManager->GetMouseCoords())) {
                if(it->first == "new_game") {
                    stateManager->GoToState(new PlayingState(inputManager, stateManager, textureManager));
                    break;
                }
                else if(it->first == "exit_game") {
                    stateManager->GoToState(new ExitingState());
                    break;
                }
            }
        }
    }
}

void MainMenuState::Draw(SDL_Renderer* renderer) {
    std::map<std::string, Button*>::iterator it;
    for (it = menuButtons.begin(); it != menuButtons.end(); ++it) {
        it->second->Render(renderer);
    }
}
