// utilities.h
// the file contains functions used by both
// the BloomFilter class and the HashTable class.

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

// returns the closest prime number to n such that
// n is less than this prime number.
int nextPrime(int n);

// helper function for generateHashParameter.
// returns true if n is prime.
// returns false otherwise.
bool isPrime(int n);

// string to integer conversion.
// necessary to run the hash functions on the element.
unsigned int strToInt(std::string element);

#endif // UTILITIES_H