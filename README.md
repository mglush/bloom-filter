# Bloom Filter Implementation in C++.
#### By Michael Glushchenko for UCSB CS130a Winter 2022 (Data Structure Algorithms I)

## Table of Contents
* [How To Run](https://github.com/mglush/bloom-filter/blob/main/README.md#how-to-run)
* [Use BloomFilter in Your Project](https://github.com/mglush/bloom-filter/blob/main/README.md#use-bloom-filter-in-your-project)
* [Project Notes](https://github.com/mglush/bloom-filter/blob/main/README.md#project-notes)
* [Report](https://github.com/mglush/bloom-filter/blob/main/README.md#report)

## How to Run
To run the project as is:
~~~
git clone https://github.com/mglush/bloom-filter          # clone repository.
cd bloom-filter                                           # enter repository folder.
make clean && make                                        # create the bloom filter executable by the name of PA1.out
./PA1.out file_1 file_2 file_3 file_4 file_5              # run the exectuable
~~~
Meaning of the input files above:
  - 'file_1' contains, each on a separate line, p (desired probability of a false positive), m (expected number of strings to be inserted), c (scale factor of the bloom filter size), and d (scale factor of number of hash functions). Keeping c and d at 1 works just fine.
  - 'file_2' contains the list of words to be inserted into the bloom filter.
  - 'file_3' contains the list of words that are all supposed to be successful.
  - 'file_4' contains the list of words that are all supposed to be unsuccessful.
  - 'file_5' contains the list of words that will then be deleted from the bloom filter (i.e., inserted into the auxillary hash table).

## Use BloomFilter in Your Project
To use the bloom filter data structure, you will need to keep copy the following files to your project:
  - 'BloomFilter.hpp' and 'BloomFilter.cpp'
  - 'HashTable.hpp' and 'HashTable.cpp'
  - 'utilities.hpp' and 'utilities.cpp'

## Project Notes
This project implements a bloom filter with an auxillary hash table to create a probabilistic data structure that supports O(1) find() operations. The auxillary hash table is used to keep track of elements removed from the bloom filter, since the filter itself does not support the delete operation.

To do so, bloom filter uses an m-bit array, with k hash functions that map strings to numbers in the range 0 <= x < m. When a string is inserted into the bloom filter, it is first converted to a number, and then hashed using every single one of the k hash functions available. The results of these hashes is the set of indices that need to be set to 1 to insert the string into the bloom filter. The project report goes into greater details about the implementaiton.

## Report
Titled PA1_report.pdf, the paper explains somee aspects of the bloom filter implementation, as well as several design choices, including conversion of strings to numbers, generation of independent hash functions, estimating and adjusting the size of the auxillary hash table, as well as the actual data structure used to implement the bloom filter bit array.

The report then examines two relationships. First, it examines how to size of the bloom filter affects the false positive probability of a find() operation. Next, the same is done for the relationship between the number of hash functions used and the false positive probability of a find() operation.

Michael Glushchenko &copy; 2022
