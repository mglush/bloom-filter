// testBloomFilter1.cpp
// this test file tests the following BloomFilter functions:
// strToInt()
// bloomFilterSize()
// numHashFunctions()
// hash()

#include <cassert>
#include <string>
#include <sstream>

#include "testBloomFilter.h"
#include "testFramework.h"
#include "BloomFilter.h"
#include "HashTable.h"

int main() {
    std::cout << "Running testBloomFilter1 file!" << std::endl << std::endl;
    runAllTests();
    std::cout << "Finished running testBloomFilter1 file!" << std::endl << std::endl;
}

void runAllTests() {
    test_bloomFilterSize();
    test_numHashFunctions();
    test_generateHashParameter();
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

void test_generateHashParameter() {
    START_TEST("test_generateHashParameter");
    
    BloomFilter bloomFilter(0.05, 0, 1.0, 1.0);

    // testing size 0.
    assertEquals(2, bloomFilter.numHashFunctions(0, 0, 1.0), "testing bloom filter of size 0");
    
    // testing size 63.
    assertEquals(67, bloomFilter.numHashFunctions(63, 10, 1.0), "testing bloom filter of size 63");

    // testing size 62353.
    assertEquals(62383, bloomFilter.numHashFunctions(62353, 10000, 1.0), "testing bloom filter of size 62353");
    
    // testing size 96.
    assertEquals(97, bloomFilter.numHashFunctions(96, 10, 1.0), "testing bloom filter of size 96");

    // testing size 95851.
    assertEquals(95857, bloomFilter.numHashFunctions(95851, 10000, 1.0), "testing bloom filter of size 95851");

    END_TEST("test_generateHashParameter");
}