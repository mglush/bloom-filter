#include "HashTable.h"
#include <string>
#include <iostream>

// q := the size of the HashTable, a prime number.
HashTable::HashTable(int q) {
    this->size = q;
    this->hashTable = new Node*[q];
    // set each element to point to null in the beginning
    for (int i = 0; i < q; i++) {
        hashTable[i] = NULL;
    }
}

// calculates the hash of an element.
// hash function used: x mod size of HashTable.
// used by the insert() function.
int HashTable::hash(std::string element) {
    return 0; // STUB
}

// insert a string into the hash table.
void HashTable::insert(std::string element) {
    // STUB
}

// string to integer conversion.
// necessary to run the hash functions on the element.
unsigned int HashTable::strToInt(std::string element) {
    return 0; // STUB
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