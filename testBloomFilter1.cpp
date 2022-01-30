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
    runAllTests();
}

void runAllTests() {
    test_strToInt();
    test_bloomFilterSize();
    test_numHashFunctions();
    test_hashStrInput();
    test_hashNumInput();
}

void test_strToInt() {
    // STUB
}

void test_bloomFilterSize() {
    // STUB
}

void test_numHashFunctions() {
    // STUB
}

void test_hashStrInput() {
    // STUB
}

void test_hashNumInput() {
    // STUB
}