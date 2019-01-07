//
// Created by Tyler Wilson on 3/29/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_DUNGEONTILE_HPP
#define ETERNAL_FACADE_SDL_V2_DUNGEONTILE_HPP

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <list>

#include "../GameObject.hpp"
#include "../../DataModels/Enums/TileType.hpp"

class DungeonObject : public GameObject {
public:
    DungeonObject();
    ~DungeonObject();

    bool IsInteractable();

    virtual TileType GetTileType();
    virtual void SetTileType(TileType nType);

    virtual std::list<SDL_Rect> GetClipRects();
    virtual void ClearClipRects();
    virtual void AddClipRect(SDL_Rect rect);
private:
    bool interactable;
protected:
    TileType type;

    // rect used to clip from sprite sheet
    // this way once generated, it will always show the same image
    std::list<SDL_Rect> textureClipRects;
};


#endif //ETERNAL_FACADE_SDL_V2_DUNGEONTILE_HPP
