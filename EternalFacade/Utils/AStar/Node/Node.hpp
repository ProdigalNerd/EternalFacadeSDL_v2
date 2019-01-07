//
// Created by Tyler Wilson on 5/3/18.
//

#ifndef ETERNAL_FACADE_SDL_V2_NODE_HPP
#define ETERNAL_FACADE_SDL_V2_NODE_HPP

#include <utility>

class Node {
public:
    Node();
    Node(Node* parent = nullptr, std::pair<int, int> location = {0,0});
    ~Node();

    int GetScore();

    Node* parentNode;
    int g; // cost from start to node
    int h; // cost from node to target
    std::pair<int, int> pos;

    bool operator == (const Node& n) const { return pos == n.pos; }
    bool operator != (const Node& n) const { return pos != n.pos; }
};


#endif //ETERNAL_FACADE_SDL_V2_NODE_HPP
