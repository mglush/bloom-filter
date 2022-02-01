// testHashTable.cpp
// this test file tests the following HashTable functions:
// strToInt()
// hash()
// insert()
// remove()
// find()

#include <cassert>
#include <string>
#include <iostream>

#include "testHashTable.h"
#include "testFramework.h"
#include "HashTable.h"

int main() {
    std::cout << "Running testHashTable file!" << std::endl << std::endl;
    runAllTests();
    std::cout << "Finished running testHashTable file!" << std::endl << std::endl;
}

void runAllTests() {
    test_strToInt();
    test_hash();
    //---------------
    test_insert();
    test_remove();
    test_find();
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
    START_TEST("test_hash");

    HashTable myTable(13);
    assertEquals(0 % 13, myTable.hash(""), "hashing an empty string");
    assertEquals(3135 % 13, myTable.hash("ab"), "hashing 'ab'");
    assertEquals(3105 % 13, myTable.hash("ba"), "hashing 'ba'");
    assertEquals(3016800 % 13, myTable.hash("aabb"), "hashing 'aabb'");
    assertEquals(2986080 % 13, myTable.hash("bbaa"), "hashing 'bbaa'");

    END_TEST("test_hash");
}

void test_insert() {
    START_TEST("test_insert");

    HashTable myTable(13);
    
    myTable.insert("");
    assertEquals(0, myTable.getNumEntries(), "inserted an empty string");
    
    myTable.insert("ab");
    assertEquals(1, myTable.getNumEntries(), "inserted ab");
    
    myTable.insert("ba");
    assertEquals(2, myTable.getNumEntries(), "inserted ba");
    
    myTable.insert("ab");
    assertEquals(2, myTable.getNumEntries(), "inserted ab (DUPLICATE)");
    
    myTable.insert("ba");
    assertEquals(2, myTable.getNumEntries(), "inserted ba (DUPLICATE)");

    END_TEST("test_insert");
}

void test_remove() {
    START_TEST("test_remove");

    HashTable myTable(13);
    myTable.insert("aabb");
    myTable.insert("bbaa");
    assertEquals(2, myTable.getNumEntries(), "inserted 2 elements to begin");
    
    myTable.remove("");
    assertEquals(2, myTable.getNumEntries(), "deleted an empty string");
    
    myTable.remove("aabb");
    assertEquals(1, myTable.getNumEntries(), "deleted aabb (valid string)");
    
    myTable.remove("aabb");
    assertEquals(1, myTable.getNumEntries(), "deleted aabb (invalid string)");
    
    myTable.remove("bbaa");
    assertEquals(0, myTable.getNumEntries(), "deleted bbaa (valid string)");
    
    myTable.remove("bbaa");
    assertEquals(0, myTable.getNumEntries(), "deleted bbaa from empty table");

    END_TEST("test_remove");
}

void test_find() {
    START_TEST("test_find");

    HashTable myTable(13);
    myTable.insert("aabb");
    myTable.insert("bbaa");

    assertEquals(0, myTable.find(""), "looking for an empty string");
    
    assertEquals(1, myTable.find("aabb"), "looking for aabb when aabb is in the list");
    
    myTable.remove("aabb");
    assertEquals(0, myTable.find("aabb"), "looking for aabb when aabb is not in the list");
    
    assertEquals(1, myTable.find("bbaa"), "looking for bbaa when bbaa is in the list");
    
    myTable.remove("bbaa");
    assertEquals(0, myTable.find("bbaa"), "looking for bbaa when bbaa is not in the list");

    END_TEST("test_find");
}