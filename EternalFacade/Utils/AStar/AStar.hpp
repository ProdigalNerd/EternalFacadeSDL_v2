//
// Created by Tyler Wilson on 5/3/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_ASTAR_HPP
#define ETERNAL_FACADE_SDL_V2_ASTAR_HPP

#include <list>
#include <map>
#include <Maps/MapGenerator.hpp>

#include "../../GameObjects/DungeonObject/DungeonObject.hpp"
#include "Node/Node.hpp"

class AStar {
public:
    AStar(MapGenerator *mapGen);
    ~AStar();

    std::list<Node*> GetPathToTile(std::pair<int, int> startTile,
                                    std::pair<int, int> targetTile,
                                    bool ignoreWalls);

    std::list<Node*> BruteForcePath(std::pair<int, int> startTile,
                                    std::pair<int, int> targetTile);

    bool DoesPathExist(std::pair<int, int> startTile,
                       std::pair<int, int> targetTile);

private:
    MapGenerator* mapGenerator;

    std::list<Node> openTiles;
    std::list<Node> closedTiles;

    std::list<Node> OpenNeighbors(Node node);
    std::list<Node> GetNeighborWalls(Node node);
    std::list<Node> OpenAllNeighbors(Node node);
    int CalculateHValue(std::pair<int, int> pos, std::pair<int, int> targetTile);
    bool IsEdgeWall(std::pair<int, int> wallPos);
    bool IsOutOfBounds(std::pair<int, int> wallPos);
};


#endif //ETERNAL_FACADE_SDL_V2_ASTAR_HPP
