#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include "Node.h"

// separate chaining hash table.
// used for deleted elements of BloomFilter.
class HashTable {
    public:
        // q := the size of the HashTable, a prime number.
        HashTable(int q);

        // calculates the hash of an element.
        // hash function used: x mod size of HashTable.
        // used by the insert() function.
        int hash(std::string element);

        // insert a string into the hash table.
        void insert(std::string element);

        // string to integer conversion.
        // necessary to run the hash functions on the element.
        unsigned int strToInt(std::string element);
        
        // delete an element from the hash table.
        void remove(std::string element);

        // returns 1 if the element is in the hash table.
        // returns 0 otherwise.
        bool find(std::string element) const;

    private:
        // linked list implementation for separate hashing.
        int size; // size of HashTable, a prime number.
        Node** hashTable; // a separate chaining hash table.
};

#endif // HASH_TABLE_H