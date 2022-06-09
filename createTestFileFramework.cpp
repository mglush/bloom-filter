// createTestFileFramework.cpp

#include "createTestFileFramework.hpp"
#include "utilities.hpp"
#include <cmath>

void printTestValues(double p, float c, float d, int q) {
    std::cout << "Experiment for values of:" << std::endl;
    std::cout << "p = " << std::to_string(p) << std::endl;
    std::cout << "c = " << std::to_string(c) << std::endl;
    std::cout << "d = " << std::to_string(d) << std::endl;
    std::cout << "q = " << std::to_string(q) << std::endl;
}

void printRoundResults(int falseNeg, int falsePos, std::vector<std::string> falsePosElements) {
    std::cout << "Number of false negatives:" << std::endl;
    std::cout << std::to_string(falseNeg) << std::endl;
    std::cout << "Number of false positives:" << std::endl;
    std::cout << std::to_string(falsePos) << std::endl;
    std::cout << "Probability of false positives:" << std::endl;
    std::cout << std::to_string(falsePos / 100.0) << std::endl;
    std::cout << "False Positive Elements:" << std::endl;
    for (unsigned int i = 0; i < falsePosElements.size(); i++)
        std::cout << falsePosElements[i] << std::endl;
}

void printFinalStatistics(int falseNeg, int falsePos) {
    std::cout << "Number of false negatives:" << std::endl;
    std::cout << std::to_string(falseNeg) << std::endl;
    std::cout << "Number of false positives:" << std::endl;
    std::cout << std::to_string(falsePos) << std::endl;
    std::cout << "Probability of false positives:" << std::endl;
    std::cout << std::to_string(falsePos / 1000.0) << std::endl;
}

void makeTestFile(std::string setup) {
    double p;
    int m;
    float c, d;
    
    std::string curr;
    std::ifstream inFile1, inFile2, inFile3, inFile4, inFile5;
    
    std::string outputFileName = "./output_files/output" + setup.substr(19);
    std::ofstream outFile;
    
    int totalFalseNeg = 0, totalFalsePos = 0;

    // process the inputs from file 1.
    inFile1.open(setup);
    inFile1 >> p;
    inFile1 >> m;
    inFile1 >> c;
    inFile1 >> d;
    inFile1.close();

    // create the BloomFilter and HashTable based on the inputs (so we can print test values).
    BloomFilter bloomFilter(p, m, c, d);
    HashTable hashTable(nextPrime(std::ceil(std::sqrt(bloomFilter.getHashingPrimeNum()))));

    // run 10 rounds of tests, each consisting of inserting 1000 elements.
    // this time, we only record the final statistics about false positives/negatives.
    // instead of printing the statistics, the statistics will be saved in output<test#>.txt file.
    inFile2.open("input.txt");
    inFile3.open("successfulSearch.txt");
    inFile4.open("failedSearch.txt");
    inFile5.open("remove.txt");
    for (int i = 0; i < 10; i++) {
        // read in, and insert, the next 1000 elements into the bloom filter.
        for (int j = 0; j < 1000; j++) {
            inFile2 >> curr;
            bloomFilter.insert(curr);
        }

        // read in, and look for, the next 100 elements in successfulSearches text file.
        for (int j = 0; j < 100; j++) {
            inFile3 >> curr;
            if (!bloomFilter.find(curr)) { totalFalseNeg++; }
        }

        // read in, and look for, the next 100 elements in failedSearches text file.
        for (int j = 0; j < 100; j++) {
            inFile4 >> curr;
            if (bloomFilter.find(curr) && !hashTable.find(curr)) { totalFalsePos++; }
        }

        // read in, and remove, the next 100 elements in removedElements text file.
        for (int j = 0; j < 100; j++) {
            inFile5 >> curr;
            // if element exists in the bloom filter, we remove it by adding it to hashTable.
            if (bloomFilter.find(curr)) { hashTable.insert(curr); }
        }
    }
    // close the ifstreams.
    inFile2.close();
    inFile3.close();
    inFile4.close();
    inFile5.close();

    // record the total statistics in the output<test#>.txt file.
    outFile.open(outputFileName);
    outFile << "Testing values:\nc = " << std::to_string(c) << "\nd = " << std::to_string(d) << "\n";
    outFile << "Probability of false positive:\n" << std::to_string(totalFalsePos / 1000.0);
    outFile.close();
}