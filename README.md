# Bloom Filter Implementation in C++.
#### By Michael Glushchenko for UCSB CS130a Winter 2022 (Data Structure Algorithms I)

This project implements a bloom filter with an auxillary hash table to create a probabilistic data structure that supports O(1) find() operations. The auxillary hash table is used to keep track of elements removed from the bloom filter, as it does not support the remove operation on its own.
