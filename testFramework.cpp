// testframework.cpp
// the file contains a helpful general framework for running test files in the BloomFilter project.

#include <sstream>
#include "testFramework.h"

void START_TEST(std::string testname){
    std::cout << "Start " << testname << std::endl;
}

void END_TEST(std::string testname) {
    std::cout << "End " << testname << std::endl << std::endl;
}

void assertEquals(std::string expected, std::string actual, std::string testDescription){
    if (expected == actual) {
        std::cout << "PASSED " << std::endl;
    } else {
        std::cout << "   FAILED: " << testDescription << std::endl;
        std::cout << "   Expected: " << expected << " Actual: " << actual << std::endl;
    }
}

void assertEquals(int expected, int actual, std::string testDescription){
    if (expected == actual) {
        std::cout << "PASSED " << std::endl;
    } else {
        std::cout << "   FAILED: " << testDescription << std::endl;
        std::cout << "   Expected: " << std::to_string(expected) << " Actual: " << std::to_string(actual) << std::endl;
    }
}