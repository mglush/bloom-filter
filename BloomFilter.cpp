#include "BloomFilter.h"
#include <string>
#include <cmath>

// p := probability of a false positive.
// m := expected number of strings to be inserted.
// c := scale factor of the bloom filter size.
// d := scale factor of number of hash functions.
BloomFilter::BloomFilter(double p, int m, float c, float d) {
    // find the correct size for out bloomFilter.
    this->size = bloomFilterSize(p, m, c);
    // find the prime number closest to the bloomFilter size, set the private var.
    this->hashingPrimeNum = nextPrime(this->size);
    // initialize our bitArray with the correct size.
    for (int i = 0; i < this->size; i++)
        bitArray.push_back(0);
    // initialize the vector holding the parameters/seeds of the
    // necessary amount of hash functions.
    for (int i = 0; i < numHashFunctions(this->size, m, d); i++)
        hashParameters.push_back(generateHashParameter(this->size));
}

// calculates the size of the bloom filter,
// based on the false positive probability and number of elements
// p := probability of a false positive.
// m := expected number of strings to be inserted.
// c := scale factor of the bloom filter size.
int BloomFilter::bloomFilterSize(double p, int m, float c) const {
    if (m == 0) { return 0; }
    return std::ceil((-1.0 * (m * std::log(p)) / (std::pow(std::log(2.0), 2.0))) / c);
}

// computes the number of hash functions to use
// based on the BloomFilter size, and the expected num
// of strings to be inserted
// n := bloom filter size (can find via bloomFilterSize(p, m, c))
// m := expected number of strings to be inserted.
// d := scale factor of number of hash functions.
int BloomFilter::numHashFunctions(int n, int m, float d) {
    if (n == 0) { return 0; }
    return std::ceil((n / m) * std::log(2.0) / d);
}

// returns the closest prime number to n such that
// n is less than this prime number.
int BloomFilter::nextPrime(int n) const {
    while (!isPrime(n)) { n++; }
    return n;
}


// generates a random seed number, that will act as a parameter
// for one of the bloomFilter hash functions that will be used.
// n := bloom filter size (can find via bloomFilterSize(p, m, c)).
// m := expected number of strings to be inserted.
int BloomFilter::generateHashParameter(int n) const {
    return std::rand() % n;
}

// helper function for generateHashParameter.
// returns true if n is prime.
// returns false otherwise.
bool BloomFilter::isPrime(int n) const {
    // base cases
    if (n <= 1) { return false; }
    if (n <= 3) { return true; }
    if (n % 2 == 0 || n % 3 == 0) { return false; }
   
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) { return false; }
   
    return true;
}

// family of hash functions.
// the index specifies which hash function should be used.
// takes a string as the element to hash.
// return a valid index for bitArray.
int BloomFilter::hash(std::string element, int index) const {
    unsigned int elementRep = strToInt(element);
    return ((elementRep ^ hashParameters[index]) % this->hashingPrimeNum) % this->size;
}

// insert a string into the BloomFilter.
void BloomFilter::insert(std::string element) {
    for (int i = 0; i < hashParameters.size(); i++)
        bitArray[hash(element, i)] = 1;
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
    for (int i = 0; i < hashParameters.size(); i++)
        if (bitArray[hash(element, i)] == 0) { return false; }
    return true; // all hashes show a '1' bit for this element
}

// used to test BloomFilter.
// this prints out the statistics about the bloomFilter.
void BloomFilter::print() {
    // STUB
}