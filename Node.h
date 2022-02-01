#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
    std::string element;
    Node* next;
};

#endif // NODE_H