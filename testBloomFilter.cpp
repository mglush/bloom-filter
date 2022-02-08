// testBloomFilter.cpp
// this test file tests the following BloomFilter functions:
// bloomFilterSize()
// numHashFunctions()
// test_generateHashParameter()
// test_insert_and_find() // tested together because it's difficult
// (or impossible) to test insert without find, or find without insert.


#include <cassert>
#include <string>
#include <sstream>

#include "testBloomFilter.h"
#include "testFramework.h"
#include "BloomFilter.h"
#include "HashTable.h"

int main() {
    std::cout << "Running testBloomFilter file!" << std::endl << std::endl;
    runAllTests();
    std::cout << "Finished running testBloomFilter file!" << std::endl << std::endl;
}

void runAllTests() {
    test_bloomFilterSize();
    test_numHashFunctions();
    test_nextPrime();
    test_isPrime();
    test_insert_and_find();
}

void test_bloomFilterSize() {
    START_TEST("test_bloomFilterSize");

    BloomFilter bloomFilter(0.05, 0, 1.0, 1.0);

    // testing 5% false positive probability, with 0 expected inserts.
    // scale factors are both 1.
    assertEquals(0, bloomFilter.bloomFilterSize(0.05, 0, 1.0), "testing 0 elements");
    
    // testing 5% false positive probability, with 10 expected inserts.
    // scale factors are both 1.
    assertEquals(63, bloomFilter.bloomFilterSize(0.05, 10, 1.0), "testing 10 elements");

    // testing 5% false positive probability, with 10000 expected inserts.
    // scale factors are both 1.
    assertEquals(62353, bloomFilter.bloomFilterSize(0.05, 10000, 1.0), "testing 10000 elements");

    END_TEST("test_bloomFilterSize");
}

void test_numHashFunctions() {
    START_TEST("test_numHashFunctions");

    BloomFilter bloomFilter(0.05, 0, 1.0, 1.0);

    // testing 5% false positive probability, with 0 expected inserts.
    // scale factors are both 1.
    assertEquals(0, bloomFilter.numHashFunctions(0, 0, 1.0), "testing 0 elements");
    
    // testing 5% false positive probability, with 10 expected inserts.
    // scale factors are both 1.
    assertEquals(5, bloomFilter.numHashFunctions(63, 10, 1.0), "testing 10 elements at 5% probability");

    // testing 5% false positive probability, with 10000 expected inserts.
    // scale factors are both 1.
    assertEquals(5, bloomFilter.numHashFunctions(62353, 10000, 1.0), "testing 10000 elements at 5% probability");
    
    // testing 1% false positive probability, with 10 expected inserts.
    // scale factors are both 1.
    assertEquals(7, bloomFilter.numHashFunctions(96, 10, 1.0), "testing 10 elements at 1% probability");

    // testing 1% false positive probability, with 10000 expected inserts.
    // scale factors are both 1.
    assertEquals(7, bloomFilter.numHashFunctions(95851, 10000, 1.0), "testing 10000 elements at 1% probability");

    END_TEST("test_numHashFunctions");
}

void test_nextPrime() {
    START_TEST("test_nextPrime");
    
    BloomFilter bloomFilter(0.05, 0, 1.0, 1.0);

    assertEquals(2, bloomFilter.nextPrime(0), "testing bloom filter of size 0");
    assertEquals(67, bloomFilter.nextPrime(63), "testing bloom filter of size 63");
    assertEquals(62383, bloomFilter.nextPrime(62353), "testing bloom filter of size 62353");
    assertEquals(97, bloomFilter.nextPrime(96), "testing bloom filter of size 96");
    assertEquals(95857, bloomFilter.nextPrime(95851), "testing bloom filter of size 95851");

    END_TEST("test_nextPrime");
}

void test_isPrime() {
    START_TEST("test_isPrime");
    
    BloomFilter bloomFilter(0.05, 0, 1.0, 1.0);

    assertEquals(true, bloomFilter.isPrime(67), "testing 67");
    assertEquals(true, bloomFilter.isPrime(62383), "testing 62383");
    assertEquals(false, bloomFilter.isPrime(62353), "testing 62353");
    assertEquals(false, bloomFilter.isPrime(96), "testing 96");
    assertEquals(true, bloomFilter.isPrime(95857), "testing 95857");

    END_TEST("test_isPrime");
}

void test_insert_and_find() {
    START_TEST("test_insert_and_find");

    BloomFilter bloomFilter(0.05, 10, 1.0, 1.0);

    assertEquals(false, bloomFilter.find("baa"), "looking for invalid string baa in an empty bloom filter");
    assertEquals(false, bloomFilter.find("aba"), "looking for invalid string aba in an empty bloom filter");
    
    bloomFilter.insert(""); // inserting empty string (should not be inserted)
    bloomFilter.insert("ab"); // inserting ab
    assertEquals(true, bloomFilter.find("ab"), "looking for (valid) ab");
    bloomFilter.insert("ba"); // inserting ba
    assertEquals(true, bloomFilter.find("ba"), "looking for (valid) ba");

    assertEquals(false, bloomFilter.find("baa"), "looking for invalid string baa in a filled bloom filter");
    assertEquals(false, bloomFilter.find("aba"), "looking for invalid string aba in a filled bloom filter");

    END_TEST("test_insert_and_find");
}