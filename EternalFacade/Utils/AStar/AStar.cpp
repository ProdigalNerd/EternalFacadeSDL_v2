//
// Created by Tyler Wilson on 5/3/18.
//

#include "AStar.hpp"

#include <algorithm>
#include <memory>

using namespace std;

AStar::AStar(MapGenerator* mapGen) {
    mapGenerator = mapGen;
}

AStar::~AStar() {
    openTiles.clear();
    closedTiles.clear();
}

std::list<Node*> AStar::GetPathToTile(std::pair<int, int> startTile,
                                      std::pair<int, int> targetTile,
                                      bool ignoreWalls) {
    openTiles.clear();
    closedTiles.clear();

    Node startNode(NULL, startTile);
    startNode.g = 0;

    openTiles.push_back(startNode);

    Node* curNode = &startNode;
    curNode->g = 0;
    curNode->h = CalculateHValue(curNode->pos, targetTile);
    Node* lowFNode = curNode;

    while(!openTiles.empty() && curNode->pos != targetTile) {
        openTiles.remove(*curNode);
        closedTiles.push_back(*curNode);

        std::list<Node> neighbors;

        if(ignoreWalls) {
            neighbors = OpenAllNeighbors(*curNode);
        }
        else {
            neighbors = OpenNeighbors(*curNode);
        }

        std::list<Node>::iterator nIt;
        for(nIt = neighbors.begin(); nIt != neighbors.end(); ++nIt) {
            if(!(std::find(closedTiles.begin(), closedTiles.end(), (*nIt)) != closedTiles.end())) {
                // if not in open tiles calculate values and add to open list
                if(!(std::find(openTiles.begin(), openTiles.end(), (*nIt)) != openTiles.end())) {
                    nIt->g = curNode->g + 10;
                    nIt->h = CalculateHValue(nIt->pos, targetTile);
                    nIt->parentNode = curNode;
                    openTiles.emplace_back(*nIt);
                }
                else {
                    if(nIt->g > (curNode->g + 10)) {
                        nIt->parentNode = curNode;
                        nIt->g = curNode->g + 10;
                        nIt->h = CalculateHValue(nIt->pos, targetTile);
                    }
                }
            }
        }

        lowFNode = &openTiles.front();

        for(nIt = openTiles.begin(); nIt != openTiles.end(); ++nIt) {
            if(nIt->GetScore() < lowFNode->GetScore()){
                lowFNode = &(*nIt);
            }
        }

        curNode = lowFNode;

        neighbors.clear();
    }

    std::list<Node*> pathList;

    if(curNode->pos == targetTile) {
        while(curNode->parentNode != nullptr) {
            pathList.push_front(curNode);
            curNode = curNode->parentNode;
        }
    }

    return pathList;
}

std::list<Node *> AStar::BruteForcePath(std::pair<int, int> startTile, std::pair<int, int> targetTile) {
    Node* lowFNode = &closedTiles.front();

    std::list<Node>::iterator nIt;
    for(nIt = closedTiles.begin(); nIt != closedTiles.end(); ++nIt) {
        if(nIt->GetScore() < lowFNode->GetScore()) {
            lowFNode = &(*nIt);
        }
    }

    std::list<Node *> tilesToChange;

    return GetPathToTile(lowFNode->pos, targetTile, true);
}

bool AStar::DoesPathExist(std::pair<int, int> startTile, std::pair<int, int> targetTile) {
    return !GetPathToTile(startTile, targetTile, false).empty();
}

std::list<Node> AStar::OpenNeighbors(Node node) {
    std::map<std::pair<int, int>, DungeonObject*> map_ref = mapGenerator->GetDungeonMap();

    std::pair<int, int> north = std::make_pair(node.pos.first - 1, node.pos.second);
    std::pair<int, int> south = std::make_pair(node.pos.first + 1, node.pos.second);
    std::pair<int, int> west = std::make_pair(node.pos.first, node.pos.second - 1);
    std::pair<int, int> east = std::make_pair(node.pos.first, node.pos.second + 1);

    std::list<Node> neighbors;

    if(map_ref[north]->GetTileType() == TileType::Floor) {
        neighbors.emplace_back(Node(nullptr, north));
    }

    if(map_ref[south]->GetTileType() == TileType::Floor) {
        neighbors.emplace_back(Node(nullptr, south));
    }

    if(map_ref[west]->GetTileType() == TileType::Floor) {
        neighbors.emplace_back(Node(nullptr, west));
    }

    if(map_ref[east]->GetTileType() == TileType::Floor) {
        neighbors.emplace_back(Node(nullptr, east));
    }

    return neighbors;
}

std::list<Node> AStar::GetNeighborWalls(Node node) {
    std::list<Node> neighbors;

    if(node.pos.first > 0 && node.pos.second > 0) {
        std::map<std::pair<int, int>, DungeonObject *> map_ref = mapGenerator->GetDungeonMap();

        std::pair<int, int> north = std::make_pair(node.pos.first - 1, node.pos.second);
        std::pair<int, int> south = std::make_pair(node.pos.first + 1, node.pos.second);
        std::pair<int, int> west = std::make_pair(node.pos.first, node.pos.second - 1);
        std::pair<int, int> east = std::make_pair(node.pos.first, node.pos.second + 1);

        if (map_ref[north]->GetTileType() == TileType::Wall && !IsEdgeWall(north)) {
            neighbors.emplace_back(Node(nullptr, north));
        }

        if (map_ref[south]->GetTileType() == TileType::Wall && !IsEdgeWall(south)) {
            neighbors.emplace_back(Node(nullptr, south));
        }

        if (map_ref[west]->GetTileType() == TileType::Wall && !IsEdgeWall(west)) {
            neighbors.emplace_back(Node(nullptr, west));
        }

        if (map_ref[east]->GetTileType() == TileType::Wall && !IsEdgeWall(east)) {
            neighbors.emplace_back(Node(nullptr, east));
        }
    }

    return neighbors;
}

std::list<Node> AStar::OpenAllNeighbors(Node node) {
    std::map<std::pair<int, int>, DungeonObject*> map_ref = mapGenerator->GetDungeonMap();

    std::pair<int, int> north = std::make_pair(node.pos.first - 1, node.pos.second);
    std::pair<int, int> south = std::make_pair(node.pos.first + 1, node.pos.second);
    std::pair<int, int> west = std::make_pair(node.pos.first, node.pos.second - 1);
    std::pair<int, int> east = std::make_pair(node.pos.first, node.pos.second + 1);

    std::list<Node> neighbors;

    if(!IsOutOfBounds(north)) {
        neighbors.emplace_back(Node(nullptr, north));
    }
    if(!IsOutOfBounds(south)) {
        neighbors.emplace_back(Node(nullptr, south));
    }
    if(!IsOutOfBounds(west)) {
        neighbors.emplace_back(Node(nullptr, west));
    }
    if(!IsOutOfBounds(east)) {
        neighbors.emplace_back(Node(nullptr, east));
    }

    return neighbors;
}

int AStar::CalculateHValue(std::pair<int, int> pos, std::pair<int, int> targetTile) {
    int hx = abs(targetTile.first - pos.first) * 10;
    int hy = abs(targetTile.second -pos.second) * 10;
    return hx + hy;
}

bool AStar::IsEdgeWall(std::pair<int, int> wallPos) {
    if(wallPos.first == 0
       || wallPos.second == 0
       || wallPos.first == mapGenerator->GetMaxTilesX() - 1
       || wallPos.second == mapGenerator->GetMaxTilesY() - 1) {

        return true;
    }

    return false;
}

bool AStar::IsOutOfBounds(std::pair<int, int> wallPos) {
    if(wallPos.first < 0
            || wallPos.second < 0
            || wallPos.first > mapGenerator->GetMaxTilesX() -1
            || wallPos.second > mapGenerator->GetMaxTilesY() - 1) {
        return true;
    }
    return false;
}
