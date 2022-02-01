// HashTable.cpp

#include "HashTable.h"
#include <string>
#include <iostream>

// q := the size of the HashTable, a prime number.
HashTable::HashTable(int q) {
    this->size = q;
    this->hashTable = new Node*[q];
    this->numEntries = 0;
    // set each element to point to null in the beginning
    for (int i = 0; i < q; i++) {
        hashTable[i] = NULL;
    }
}

// calculates the hash of an element.
// hash function used: x mod size of HashTable.
// used by the insert() function.
int HashTable::hash(std::string element) {
    return strToInt(element) % this->size;
}

// insert a string into the hash table.
void HashTable::insert(std::string element) {
    int location = this->hash(element);
    if (element == "") { return; } // don't insert empty strings
    // first, check whether the element is in the table or not
    if (!hashTable[location]) {
        Node* newNode = new Node();
        newNode->element = element;
        newNode->next = NULL;
        hashTable[location] = newNode;
        this->numEntries++; // FOR TEST CASE PURPOSES
    }
    // otherwise we just go to the end of the linked list and add a node
    else {
        Node* temp = hashTable[location];
        if (temp->element == element) { return; } // duplicates don't get inserted
        while (temp->next) { 
            if (temp->element == element) { return; } // duplicates don't get inserted
            else { temp = temp->next; }
        }
        // create new node that will contain element
        Node* newNode = new Node();
        newNode->element = element;
        newNode->next = NULL;
        temp->next = newNode; // attach the newNode to the existing linked list
        this->numEntries++; // FOR TEST CASE PURPOSES
    }
}

// string to integer conversion.
// necessary to run the hash functions on the element.
// we evenly distribute the strings by multiplying each
// ascii value by a power of a prime number.
// 31 was chosen because it's a prime number close to
// the number of letters in the alphabet.
unsigned int HashTable::strToInt(std::string element) {
    unsigned int result = 0;
    for (unsigned int i = 0; i < element.length(); i++)
        result += element[i] * pow(31, i);
    return result;
}

// delete an element from the hash table.
void HashTable::remove(std::string element) {
    // STUB
}

// returns 1 if the element is in the hash table.
// returns 0 otherwise.
bool HashTable::find(std::string element) const {
    return false; // STUB
}