// HashTable.cpp

#include "HashTable.h"
#include "utilities.h"
#include <string>
#include <iostream>
#include <cmath>

// q := the size of the HashTable, a prime number.
HashTable::HashTable(int q) {
    this->size = q;
    this->hashTable = new Node*[q];
    this->numEntries = 0;
    // set each element to point to null in the beginning
    for (int i = 0; i < q; i++) { hashTable[i] = NULL; }
}

// calculates the hash of an element.
// hash function used: x mod size of HashTable.
// used by the insert() function.
int HashTable::hash(std::string element) const {
    return strToInt(element) % this->size;
}

// insert a string into the hash table.
void HashTable::insert(std::string element) {
    if (element == "") { return; } // don't insert empty strings.
    int location = this->hash(element);
    // first, check whether the element is in the table or not.
    if (!hashTable[location]) {
        Node* newNode = new Node();
        newNode->element = element;
        newNode->next = NULL;
        hashTable[location] = newNode;
        this->numEntries++; // FOR TEST CASE PURPOSES.
    }
    // otherwise we just go to the end of the linked list and add a node.
    else {
        Node* temp = hashTable[location];
        if (temp->element == element) { return; } // duplicates don't get inserted.
        while (temp->next) { 
            if (temp->element == element) { return; } // duplicates don't get inserted.
            else { temp = temp->next; }
        }
        // create new node that will contain element.
        Node* newNode = new Node();
        newNode->element = element;
        newNode->next = NULL;
        temp->next = newNode; // attach the newNode to the existing linked list.
        this->numEntries++; // FOR TEST CASE PURPOSES.
    }

    // after we have inserted a new node, we need to check our load factor!
    // if the load factor is now greater than 0.7, we resize our table.
    if ((numEntries * 1.0 / size) >= 0.7) {
        resizeTable(); // involves clearing the old array, and creating a new one.
    }
}

// resizes the table to about double the size (whenever load factor >= 0.7).
void HashTable::resizeTable() {
    // double the size, and find the next closest prime to that number.
    int oldSize = this->size;
    this->size = nextPrime(this->size * 2);
    // make new array, fill it with null pointers.
    Node** newTable = new Node*[this->size];
    for (int i = 0; i < this->size; i++) { newTable[i] = NULL; }
    // rehash all elements with the new size of the table.
    for (int i = 0; i < oldSize; i++) {
        for (Node* iterator = this->hashTable[i]; iterator != NULL;) {
            Node* temp = new Node();
            temp->element = iterator->element;
            temp->next = NULL;
            int location = this->hash(temp->element);
            if (!newTable[location]) { newTable[location] = temp; }
            else {
                Node* last = newTable[location];
                while (last->next) { last = last->next; }
                last->next = temp;
            }
            // and then delete the element that was just rehashed.
            Node* wantToDel = iterator;
            iterator = iterator->next;
            delete wantToDel;
        }
    }
    // set the hashtable to point the newly create array
    this->hashTable = newTable;
}

// delete an element from the hash table.
void HashTable::remove(std::string element) {
    if (element == "") { return; } // empty strings are never in the table.
    int location = this->hash(element);
    if (!this->hashTable[location]) { return; } // element is not in the table.
    // otherwise, we find the element, and remove it.
    Node* temp = hashTable[location];
    // check if the first node at this location is the one we want to delete.
    if (temp->element == element) {
        hashTable[location] = temp->next;
        delete temp;
        this->numEntries--; // FOR TESTING PURPOSES ONLY.
        return; // don't continue doing work after we're done.
    }
    // if not, look for the element in this linked list.
    Node* temp1 = temp;
    while (temp->next) {
        temp1 = temp;
        temp = temp->next;
        if (temp->element == element) {
            // check if there's more elements after temp.
            if (temp->next) { temp1->next = temp->next; } 
            else { temp1->next = NULL; }
            delete temp;
            this->numEntries--; // FOR TESTING PURPOSES ONLY.
            return;
        }
    }
}

// returns 1 if the element is in the hash table.
// returns 0 otherwise.
bool HashTable::find(std::string element) const {
    if (element == "") { return 0; } // empty strings are never in the table.
    int location = this->hash(element);
    if (!this->hashTable[location]) { return 0; } // element is not in the table.
    // otherwise, we look for the element.
    Node* temp = hashTable[location];
    // check if the first node at this location is the one we want.
    if (temp->element == element) { return 1; }
    // if not, look for the element in this linked list.
    while (temp->next) {
        temp = temp->next;
        if (temp->element == element) {
            return 1;
        }
    }
    return 0; // couldn't find the element.
}