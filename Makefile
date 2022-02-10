CXX = g++

CXXFLAGS = -std=c++17 -Wall

all: tests PA1.out

PA1.out: main.o createTestFileFramework.o BloomFilter.o HashTable.o utilities.o
	${CXX} $^ -o $@

tests: testBloomFilter testHashTable
#	./testBloomFilter		# COMMENT THIS LINE OUT BEFORE SUBMISSION
#	./testHashTable			# COMMENT THIS LINE OUT BEFORE SUBMISSION

testBloomFilter: testBloomFilter.o BloomFilter.o HashTable.o testFramework.o utilities.o
	${CXX} ${CXXFLAGS} $^ -o $@

testHashTable: testHashTable.o HashTable.o testFramework.o utilities.o
	${CXX} ${CXXFLAGS} $^ -o $@

cleanOutputs:
	/bin/rm -f ./output_files/*

cleanObjectFiles:
	/bin/rm -f *.o

clean:
	/bin/rm -f testBloomFilter testHashTable PA1.out *.o