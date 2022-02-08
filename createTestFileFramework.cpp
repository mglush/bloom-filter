#include "createTestFileFramework.h"
#include "BloomFilter.h"
#include "HashTable.h"
#include <fstream>
#include <string>

int makeTestFile(std::string filename) {
    double p;
    int m, q;
    int totalFalseNeg = 0, totalFalsePos = 0;
    float c, d;
    std::ifstream inFile1, inFile2, inFile3, inFile4, inFile5;
    std::vector<std::string> falsePosElements;

    // process the inputs from file 1.
    inFile1.open(filename);
    inFile1 >> p;
    inFile1 >> m;
    inFile1 >> c;
    inFile1 >> d;
    inFile1.close();

    // create the BloomFilter and HashTable based on the inputs (so we can print test values).
    BloomFilter bloomFilter(p, m, c, d);
    q = bloomFilter.getHashingPrimeNum(); // find the auxilary hashTable size
    HashTable hashTable(q);

    // print the values that are being experimented on
    printTestValues(p, c, d, q);

    // run 10 rounds of tests, each consisting of inserting 1000 elements
    inFile2.open("input.txt");
    inFile3.open("successfulSearch.txt");
    inFile4.open("failedSearch.txt");
    inFile5.open("remove.txt");
    for (int i = 0; i < 10; i++) {
        int falseNeg = 0;
        int falsePos = 0;
        falsePosElements.clear();

        std::cout << "Phase " << std::to_string(i + 1) << ":" << std::endl;

        // read in, and insert, the next 1000 elements into the bloom filter.
        for (int j = 0; j < 1000; j++) {
            std::string curr;
            inFile2 >> curr;
            bloomFilter.insert(curr);
        }

        // read in, and look for, the next 100 elements in successfulSearches text file.
        for (int j = 0; j < 100; j++) {
            std::string curr;
            inFile3 >> curr;
            if (!bloomFilter.find(curr)) { falseNeg++; }
        }

        // read in, and look for, the next 100 elements in failedSearches text file.
        for (int j = 0; j < 100; j++) {
            std::string curr;
            inFile4 >> curr;
            if (bloomFilter.find(curr) && !hashTable.find(curr)) {
                falsePos++;
                falsePosElements.push_back(curr);
            }
        }

        // read in, and remove, the next 100 elements in removedElements text file.
        for (int j = 0; j < 100; j++) {
            std::string curr;
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
    return 0;
}