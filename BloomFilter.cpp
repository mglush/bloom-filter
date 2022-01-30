#include "BloomFilter.h"
#include <string>


// p := probability of a false positive.
// m := expected number of strings to be inserted.
// c := scale factor of the bloom filter size.
// d := scale factor of number of hash functions.
BloomFilter::BloomFilter(double p, int m, float c, float d) {
    // STUB
}

// family of hash functions.
// the index specifies which hash function should be used.
// takes a string as the element to hash.
int BloomFilter::hash(std::string element, int index) {
    return 0; // STUB
}

// family of hash functions.
// the index specifies which hash function should be used.
// takes an unsigned int as the parameter to hash.
int BloomFilter::hash(unsigned int element, int index) {
    return 0; // STUB
}

// insert a string into the BloomFilter.
void BloomFilter::insert(std::string element) {
    // STUB
}

// string to integer conversion.
// necessary to run the hash functions on the element.
unsigned int BloomFilter::strToInt(std::string element) {
    return 0; // STUB
}

// delete a string from the BloomFilter.
// the function uses HashTable removedElements.
void BloomFilter::remove(std::string element) {
    // STUB
}

// returns true if the element is in the BloomFilter.
// returns false otherwise.
bool BloomFilter::find(std::string element) const {
    return false; // STUB
}

// calculates the size of the bloom filter,
// based on the false positive probability and number of elements
// p := probability of a false positive.
// m := expected number of strings to be inserted.
// c := scale factor of the bloom filter size.
int BloomFilter::bloomFilterSize(double p, int m, float c) {
    return 0; // STUB
}

// computes the number of hash functions to use
// based on the BloomFilter size, and the expected num
// of strings to be inserted
// n := bloom filter size (can find via bloomFilterSize(p, m, c))
// m := expected number of strings to be inserted.
// d := scale factor of number of hash functions.
int BloomFilter::numHashFunctions(int n, int m, float d) {
    return 0; // STUB
}

// used to test BloomFilter.
void BloomFilter::print() {
    // STUB
}