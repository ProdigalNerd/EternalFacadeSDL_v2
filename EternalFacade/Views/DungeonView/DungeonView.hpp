//
// Created by Tyler Wilson on 3/15/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_DUNGEONVIEW_HPP
#define ETERNAL_FACADE_SDL_V2_DUNGEONVIEW_HPP

#include "../../Utils/IView/IView.hpp"

#include <list>
#include <map>
#include "../../Utils/ITexture/ITexture.hpp"
#include "../../Managers/TextureManager/TextureManager.hpp"
#include "../../Maps/Environment.hpp"
#include "../../GameObjects/DungeonObject/DungeonObject.hpp"
#include "../../GameObjects/Character/Player/Player.hpp"

class DungeonView : public IView {
public:
    DungeonView(TextureManager *manTexture, Player *playerObj);
    ~DungeonView();

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    void Draw(SDL_Renderer* renderer) override;
private:
    ITexture* mainTexture;
    Environment* env;
    Player* player;

    int viewTilesX;
    int viewTilesY;
};


#endif //ETERNAL_FACADE_SDL_V2_DUNGEONVIEW_HPP
