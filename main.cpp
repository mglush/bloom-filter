#include <string>
#include <fstream>
#include <iostream>
#include <utility>
#include <cmath>

#include "math.h"
#include "BloomFilter.h"
#include "HashTable.h"
#include "utilities.h"
#include "createTestFileFramework.h"

int main(int argc, char *argv[]) {
    double p;
    int m, q, totalFalseNeg = 0, totalFalsePos = 0;
    float c, d;
    std::ifstream inFile1, inFile2, inFile3, inFile4, inFile5;
    std::vector<std::string> falsePosElements;

    // process the inputs from file 1.
    inFile1.open(argv[1]);
    inFile1 >> p;
    inFile1 >> m;
    inFile1 >> c;
    inFile1 >> d;
    inFile1.close();

    // create the BloomFilter and HashTable based on the inputs (so we can print test values).
    BloomFilter bloomFilter(p, m, c, d);
    q = nextPrime(std::ceil(std::sqrt(bloomFilter.getHashingPrimeNum()))); // find the auxilary hashTable size.
    HashTable hashTable(q);

    // print the values that are being experimented on.
    printTestValues(p, c, d, q);

    // open the other 4 input files.
    inFile2.open(argv[2]); // inputs into the bloom filter.
    inFile3.open(argv[3]); // successful searches list.
    inFile4.open(argv[4]); // failed searches list.
    inFile5.open(argv[5]); // deleteElements list.
    
    // run 10 rounds of tests, each consisting of inserting 1000 elements.
    for (int i = 0; i < 10; i++) {
        int falseNeg = 0, falsePos = 0;
        std::string curr;
        falsePosElements.clear();

        std::cout << "Phase " << std::to_string(i + 1) << ":" << std::endl;

        // read in, and insert, the next 1000 elements into the bloom filter.
        for (int j = 0; j < 1000; j++) {
            inFile2 >> curr;
            bloomFilter.insert(curr);
        }

        // read in, and look for, the next 100 elements in successfulSearches text file.
        for (int j = 0; j < 100; j++) {
            inFile3 >> curr;
            if (!bloomFilter.find(curr)) { falseNeg++; }
        }

        // read in, and look for, the next 100 elements in failedSearches text file.
        for (int j = 0; j < 100; j++) {
            inFile4 >> curr;
            // a false positive occurs iff we find the string in our bloom filter,
            // AND it does not exist in our auxilary hash table
            // (meaning we haven't removed it from bloom filter yet).
            if (bloomFilter.find(curr) && !hashTable.find(curr)) {
                falsePos++;
                falsePosElements.push_back(curr);
            }
        }

        // read in, and remove, the next 100 elements in removedElements text file.
        for (int j = 0; j < 100; j++) {
            inFile5 >> curr;
            // if element exists in the bloom filter, we remove it by adding it to hashTable.
            if (bloomFilter.find(curr)) { hashTable.insert(curr); }
        }

        // print results of this round.
        printRoundResults(falseNeg, falsePos, falsePosElements);

        // record the false negatives and false positives data.
        totalFalseNeg += falseNeg;
        totalFalsePos += falsePos;
    }
    // close the ifstreams.
    inFile2.close();
    inFile3.close();
    inFile4.close();
    inFile5.close();

    // print the total statistics of our tests.
    printFinalStatistics(totalFalseNeg, totalFalsePos);

    // finally, we create 10 test files for 10 different setups that we use.
    for (int i = 1; i < 14; i++) {
        std::string filename = "./setup_files/setup" + std::to_string(i) + ".txt";
        makeTestFile(filename);
    }
    return 0;
}