// testHashTable1.cpp
// this test file tests the following HashTable functions:
// strToInt()
// hash()

#include <cassert>
#include <string>
#include <sstream>
#include <iostream>

#include "testHashTable.h"
#include "testFramework.h"
#include "HashTable.h"

int main() {
    runAllTests();
}

void runAllTests() {
    test_strToInt();
    test_hash();
}

void test_strToInt() {
    START_TEST("test_strToInt");

    HashTable myTable(13);
    assertEquals(0, myTable.strToInt(""), "testing empty string");
    assertEquals(3135, myTable.strToInt("ab"), "testing ab");
    assertEquals(3105, myTable.strToInt("ba"), "testing ba");
    assertEquals(3016800, myTable.strToInt("aabb"), "testing aabb");
    assertEquals(2986080, myTable.strToInt("bbaa"), "testing bbaa");

    END_TEST("test_strToInt");
}

void test_hash() {
    // STUB
}