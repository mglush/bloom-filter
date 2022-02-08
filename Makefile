CXX = clang++

# CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

# Change to this before final submission:

# CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

all: tests PA01
	./PA01

PA01: main.o BloomFilter.o HashTable.o
	${CXX} $^ -o $@

tests: testBloomFilter testHashTable
	./testBloomFilter
	./testHashTable

testBloomFilter: testBloomFilter.o BloomFilter.o HashTable.o testFramework.o
	${CXX} ${CXXFLAGS} $^ -o $@

testHashTable: testHashTable.o HashTable.o testFramework.o
	${CXX} ${CXXFLAGS} $^ -o $@

clean:
	/bin/rm -f testBloomFilter testHashTable PA01 *.o
