// utilities.cpp
// implementation file of some utilitiy functions
// utilized by both the BloomFilter class and the
// HashTable class.

#include "utilities.h"
#include <string>
#include <cmath>

// returns the closest prime number to n such that
// n is less than this prime number.
int nextPrime(int n) {
    while (!isPrime(n)) { n++; }
    return n;
}

// helper function for generateHashParameter.
// returns true if n is prime.
// returns false otherwise.
bool isPrime(int n) {
    // base cases
    if (n <= 1) { return false; }
    if (n <= 3) { return true; }
    if (n % 2 == 0 || n % 3 == 0) { return false; }
   
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) { return false; }
   
    return true;
}

// string to integer conversion.
// necessary to run the hash functions on the element.
// we evenly distribute the strings by multiplying each
// ascii value by a power of a prime number.
// 31 was chosen because it's a prime number close to
// the number of letters in the alphabet.
unsigned int strToInt(std::string element) {
    unsigned int result = 0;
    for (unsigned int i = 0; i < element.length(); i++)
        result += element[i] * pow(31, i);
    return result;
}