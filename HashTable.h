#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>

// separate chaining hash table.
// used for deleted elements of BloomFilter.
class HashTable {
    public:
        // q := the size of the HashTable, a prime number.
        HashTable(int q);

        // insert a string into the hash table.
        void insert(std::string element);
        
        // delete an element from the hash table.
        void remove(std::string element);

        // returns 1 if the element is in the hash table.
        // returns 0 otherwise.
        bool find(std::string element) const;

    private:
        
    
}

#endif // HASH_TABLE_H