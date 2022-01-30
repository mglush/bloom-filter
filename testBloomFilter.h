// testBloomFilter.h
// the file contains the declarations of all the tests that will be run on BloomFilter

#ifndef TEST_BLOOMFILTER_H
#define TEST_BLOOMFILTER_H

void runAllTests();
//------------------------------
void test_strToInt();
void test_bloomFilterSize();
void test_numHashFunctions();
void test_hashStrInput();
void test_hashNumInput();
//------------------------------
void test_insert();
void test_remove();
void test_find();
//------------------------------
void test_print();

#endif // TEST_BLOOMFILTER_H