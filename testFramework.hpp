// testFramework.hpp
// the file contains a general framework for running test files in this project.

#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <string>
#include <iostream>

void START_TEST(std::string testname);
void END_TEST(std::string testname);
void assertEquals(std::string expected, std::string actual, std::string testDescription);
void assertEquals(int expected, int actual, std::string testDescription);

#endif // TEST_FRAMEWORK_H