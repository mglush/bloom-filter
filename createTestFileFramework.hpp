// createTestFileFramework.hpp

#ifndef CREATE_TESTFILE_FRAMEWORK_H
#define CREATE_TESTFILE_FRAMEWORK_H

#include <string>
#include <fstream>
#include <iostream>
#include <utility>

#include "math.h"
#include "BloomFilter.hpp"
#include "HashTable.hpp"

void makeTestFile(std::string fileName);
void printTestValues(double p, float c, float d, int q);
void printRoundResults(int falseNeg, int falsePos, std::vector<std::string> falsePosElements);
void printFinalStatistics(int falseNeg, int falsePos);

#endif // CREATE_TESTFILE_FRAMEWORK_H