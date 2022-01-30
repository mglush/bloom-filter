#include <cassert>
#include <string>
#include <sstream>

#include "math.h"
#include "BloomFilter.h"
#include "HashTable.h"

int main(int argc, char *argv[]) {
    // first, we process the inputs


    // create our BloomFilter and auxilary HashTable based on the inputs


    // print the values we are experimenting on


    // run 10 rounds of tests, each consisting of inserting 1000 elements


    // print the total statistics of our tests

    return 0;
}

// calculates the size of the bloom filter,
// based on the false positive probability and number of elements
int bloomFilterSize(double p, int m, float c) {

    return 0; // STUB
}

// computes the number of hash functions to use
// based on the BloomFilter size, and the expected num
// of strings to be inserted
int numHashFunctions() {
    return 0; // STUB
}

// family of hash functions
// the index specifies which hash function should be used
int hash(unsigned int element, int index) {
    return 0; // STUB
}