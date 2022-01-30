CXX = clang++

# CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

# Change to this before final submission:

# CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

BLOOMBINARIES = testBloomFilter1 testBloomFilter2 testBloomFilter3
HASHBINARIES = testHashTable1 testHashTable2

all: tests PA01
	./PA01

PA01: main.o BloomFilter.o HashTable.o
	${CXX} $^ -o $@

tests: ${BLOOMBINARIES} ${HASHBINARIES}
	./testBloomFilter1
	./testBloomFilter2
	./testBloomFilter3
	./testHashTable1
	./testHashTable2

testBloomFilter1: testBloomFilter1.o BloomFilter.o HashTable.o testFramework.o
	${CXX} ${CXXFLAGS} $^ -o $@

testBloomFilter2: testBloomFilter2.o BloomFilter.o HashTable.o testFramework.o
	${CXX} ${CXXFLAGS} $^ -o $@

testBloomFilter3: testBloomFilter3.o BloomFilter.o HashTable.o testFramework.o
	${CXX} ${CXXFLAGS} $^ -o $@

testHashTable1: testHashTable1.o HashTable.o testFramework.o
	${CXX} ${CXXFLAGS} $^ -o $@

testHashTable2: testHashTable2.o HashTable.o testFramework.o
	${CXX} ${CXXFLAGS} $^ -o $@

clean:
	/bin/rm -f ${BLOOMBINARIES} ${HASHBINARIES} PA01 *.o
