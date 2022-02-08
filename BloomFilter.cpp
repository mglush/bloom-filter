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
int BloomFilter::hash(std::string element, int index) const {
    return 0; // STUB
}

// insert a string into the BloomFilter.
void BloomFilter::insert(std::string element) {
    // STUB
}

// string to integer conversion.
// necessary to run the hash functions on the element.
// the function is idential to HashTable::strToInt()
unsigned int BloomFilter::strToInt(std::string element) const {
    unsigned int result = 0;
    for (unsigned int i = 0; i < element.length(); i++)
        result += element[i] * pow(31, i);
    return result;
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
int BloomFilter::bloomFilterSize(double p, int m, float c) const {
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

// generates a prime number, that will act as a parameter for one of the
// bloomFilter hash functions that will be used.
// acts as a helper function for numHashFunctions; together, the two functions
// initialize the hashParameters vector, and make the bloom filter ready for use.
// n := bloom filter size (can find via bloomFilterSize(p, m, c))
// m := expected number of strings to be inserted.
// x := number of hash functions to be used.
int BloomFilter::generateHashParameter(int n, int m, int x) {
    return 0; // STUB
}

// helper function for generateHashParameter.
// returns true if n is prime.
// returns false otherwise.
bool BloomFilter::isPrime(int n) const {
    return false; // STUB
}

// used to test BloomFilter.
void BloomFilter::print() {
    // STUB
}