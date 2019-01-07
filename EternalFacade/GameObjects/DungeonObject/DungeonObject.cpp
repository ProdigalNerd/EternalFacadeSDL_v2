//
// Created by Tyler Wilson on 3/29/18.
//

#include "DungeonObject.hpp"

DungeonObject::DungeonObject() {

}

DungeonObject::~DungeonObject() {

}

bool DungeonObject::IsInteractable() {
    return interactable;
}

TileType DungeonObject::GetTileType() {
    return type;
}

void DungeonObject::SetTileType(TileType nType) {
    type = nType;
}

std::list<SDL_Rect> DungeonObject::GetClipRects() {
    return textureClipRects;
}

void DungeonObject::ClearClipRects() {
    textureClipRects.clear();
}

void DungeonObject::AddClipRect(SDL_Rect rect) {
    textureClipRects.push_back(rect);
}
