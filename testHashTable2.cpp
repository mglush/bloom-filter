// testHashTable2.cpp
// this test file tests the following HashTable functions:
// insert()
// remove()
// find()

#include <cassert>
#include <string>
#include <sstream>

#include "testHashTable.h"
#include "testFramework.h"
#include "HashTable.h"

int main() {
    std::cout << "Running testHashTable2 file!" << std::endl << std::endl;
    runAllTests();
    std::cout << "Finished running testHashTable2 file!" << std::endl << std::endl;
}

void runAllTests() {
    test_insert();
    test_remove();
    test_find();
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
    myTable.insert("aabb");
    assertEquals(3, myTable.getNumEntries(), "inserted aabb");
    myTable.insert("bbaa");
    assertEquals(4, myTable.getNumEntries(), "inserted bbaa");

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
    // STUB
}