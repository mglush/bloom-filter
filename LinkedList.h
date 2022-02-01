#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

class LinkedList {
    public:
        LinkedList(); // constructor
        ~LiknedList(); // destructor
    private:
        Node* head; // head of the linked list, initially null
};

#endif // LINKED_LIST_H