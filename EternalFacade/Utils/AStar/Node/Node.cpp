//
// Created by Tyler Wilson on 5/3/18.
//

#include "Node.hpp"

Node::Node() {

}

Node::Node(Node* parent, std::pair<int, int> location) {
    parentNode = parent;
    pos = location;
}

Node::~Node() {
}

int Node::GetScore() {
    return g + h;
}
