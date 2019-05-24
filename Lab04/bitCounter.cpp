// Selinie Wang (jw6qe@virginia.edu)
// September 25, 2018
// bitCounter.cpp

#include <iostream>
#include <math.h> // used for floor function

using namespace std;

int bitCounter(int bitCount) {

	if (bitCount == 0) { // base case for 0
		return 0;
	} else if (bitCount == 1) { // base case for 1
		return 1;
	} else if (bitCount % 2 == 0) { // base case for even numbers
		return bitCounter(bitCount / 2);
	} else { // base case for odd numbers
		// return bitCounter(floor(bitCount / 2) + 1); // floor is to round down
		return 1 + bitCounter((bitCount - 1) / 2);
	}
}

int main (int argc, char **argv) {
	
	if (argc == 1) { // number of parameters + 1
		cout << "No command line parameters found." << endl;
	} else {
		cout << "Number of parameters + 1: " << argc << endl;
		int x = atoi(argv[1]); // atoi parses str to int
		int result = bitCounter(x);
		cout << "Number of 1s: " << result << endl;
	}
}