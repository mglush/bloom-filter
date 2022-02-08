CXX = g++

CXXFLAGS = -std=c++17 -Wall

all: tests PA1.out

PA1.out: main.o BloomFilter.o HashTable.o
	${CXX} $^ -o $@

tests: testBloomFilter testHashTable
	./testBloomFilter
	./testHashTable

testBloomFilter: testBloomFilter.o BloomFilter.o HashTable.o testFramework.o
	${CXX} ${CXXFLAGS} $^ -o $@

testHashTable: testHashTable.o HashTable.o testFramework.o
	${CXX} ${CXXFLAGS} $^ -o $@

clean:
	/bin/rm -f testBloomFilter testHashTable PA1.out *.o
