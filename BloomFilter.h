#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <string>
#include <sstream>

class BloomFilter {
    public:
        // p := probability of a false positive.
        // m := expected number of strings to be inserted.
        // c := scale factor of the bloom filter size.
        // d := scale factor of number of hash functions.
        BloomFilter(double p, int m, float c, float d);

        // insert a string into the BloomFilter.
        void insert(std::string element);
        
        // delete a string from the BloomFilter.
        // the function uses HashTable removedElements.
        void remove(std::string element);

        // returns true if the element is in the BloomFilter.
        // returns false otherwise.
        bool find(std::string element) const;

        // used to test BloomFilter.
        void print();

    private:
        HashTable removedElements; // keeps track of removed elements.

    
}

#endif // BLOOM_FILTER_H