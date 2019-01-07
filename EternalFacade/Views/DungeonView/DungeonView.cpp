//
// Created by Tyler Wilson on 3/15/18.
//

#include "DungeonView.hpp"

DungeonView::DungeonView(TextureManager *manTexture, Player *playerObj) {
    mainTexture = manTexture->GetTextureByKey("main");
    env = new Environment();
    player = playerObj;
    player->SetEnvironment(env);
    OnEnter();
}

DungeonView::~DungeonView() {
    OnExit();
}

void DungeonView::OnEnter() {
    viewConfigName = "dungeon_view";

    LoadViewConfig();

    std::pair<int, int> startCoords = env->GetRandomFloorCoords();

    // number of tiles wide/high in the view
    viewTilesX = viewRect.w / env->GetTileSize();
    viewTilesY = viewRect.h / env->GetTileSize();

    player->InitializePosition(startCoords.first, startCoords.second);
}

void DungeonView::OnExit() {

}

// UPDATE ALL OBJECTS IN THE SCENE
void DungeonView::Update() {
    env->Update();
    player->Update();
}

void DungeonView::Draw(SDL_Renderer *renderer) {
    std::pair<int, int> playerPos = player->GetWorldCoordinates();

    if(mainTexture != nullptr) {
        int startX = playerPos.first - (viewTilesX / 2);
        int startY = playerPos.second - (viewTilesY / 2);

        env->Draw(renderer, mainTexture, startX, startY, viewTilesX, viewTilesY);

        // draw player to the screen
        mainTexture->render((viewTilesX / 2) * env->GetTileSize(), (viewTilesY / 2) * env->GetTileSize(), player->GetClipRect(), renderer);
    }
}
