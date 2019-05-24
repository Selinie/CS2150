// Selinie Wang (jw6qe@virginia.edu)
// October 22, 2018
// hashTable.cpp

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
#include "hashTable.h"

using namespace std;

hashTable::hashTable(int size) {
	array = new vector<list<string> >; // space is required
	if (!(checkprime(size))) {
		sizeTable = getNextPrime(size) * 2;
	} else {
		sizeTable = getNextPrime(size);
	} array -> resize(sizeTable);
}

hashTable::~hashTable() {
	delete array;
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

bool hashTable::insert(const string& x) {
	int maxWords = 0;
	if (this -> contains(x) == false) {
		list<string>& list1 = array -> at(hashFunction(x));
		list1.push_back(x);
		if (x.length() > maxWords) {
			maxWords = x.length();
			return true;
		} return false;
	} return false;
}

bool hashTable::contains(const string& x) {
	list<string>& list = array -> at(hashFunction(x));
	return find(list.begin(), list.end(), x) != (list.end());
	// return find(begin(list), end(list), x) != (end(list));
}

unsigned int hashTable::hashFunction(const string& x) {
	int hash1 = 0;
	int temp = 1;
	for (int i = 0; i < x.length(); i++) {
		temp = (37 * x[i]) % (this -> sizeTable);
	} hash1 = temp % (this -> sizeTable);
	return hash1;
}



