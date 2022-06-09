// HashTable.hpp

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>

// separate chaining hash table.
// used for deleted elements of BloomFilter.
class HashTable {
    public:
        // q := the size of the HashTable, a prime number.
        HashTable(int q);

        // calculates the hash of an element.
        // hash function used: x mod size of HashTable.
        // used by the insert() function.
        int hash(std::string element) const;

        // insert a string into the hash table.
        void insert(std::string element);

        // resizes the table to about double the size (whenever load factor >= 0.7).
        void resizeTable();
        
        // delete an element from the hash table.
        void remove(std::string element);

        // returns 1 if the element is in the hash table.
        // returns 0 otherwise.
        bool find(std::string element) const;

        // testing purposes (to test insert without using find())
        int getNumEntries() const { return numEntries; }

    private:
        // linked list implementation for separate hashing.
        struct Node {
            std::string element;
            Node* next;
        };
        int size; // size of HashTable, a prime number.
        int numEntries; // for testing purposes, and for calculating the load factor.
        Node** hashTable; // a separate chaining hash table.
};

#endif // HASH_TABLE_H