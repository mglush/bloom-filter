#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <string>
#include <sstream>
#include <vector>

class BloomFilter {
    public:
        // p := probability of a false positive.
        // m := expected number of strings to be inserted.
        // c := scale factor of the bloom filter size.
        // d := scale factor of number of hash functions.
        BloomFilter(double p, int m, float c, float d);

        // family of hash functions.
        // the index specifies which hash function should be used.
        // takes a string or an unsigned int as the element to hash.
        int hash(std::string element, int index) const;
        int hash(unsigned int element, int index) const;

        // insert a string into the BloomFilter.
        void insert(std::string element);

        // string to integer conversion.
        // necessary to run the hash functions on the element.
        unsigned int strToInt(std::string element) const;
        
        // delete a string from the BloomFilter.
        // the function uses HashTable removedElements.
        void remove(std::string element);

        // returns true if the element is in the BloomFilter.
        // returns false otherwise.
        bool find(std::string element) const;

        // calculates the size of the bloom filter,
        // based on the false positive probability and number of elements.
        // p := probability of a false positive.
        // m := expected number of strings to be inserted.
        // c := scale factor of the bloom filter size.
        int bloomFilterSize(double p, int m, float c) const;

        // computes the number of hash functions to use based on the
        // BloomFilter size, and the expected num of strings to be inserted.
        // n := bloom filter size (can find via bloomFilterSize(p, m, c))
        // m := expected number of strings to be inserted.
        // d := scale factor of number of hash functions.
        int numHashFunctions(int n, int m, float d) const;

        // used to test BloomFilter.
        void print();

    private:
        std::vector<bool> bitArray; // the actual bloom filter array (std::vector<bool> functions like std::bitset)
        std::vector<int> hashParameters; // contains n parameters for the n hash functions we need
};

#endif // BLOOM_FILTER_H