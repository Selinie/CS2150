// Selinie Wang (jw6qe@virginia.edu)
// September 23, 2018
// prelab4.cpp

#include <iostream>

using namespace std;

void sizeOfTest() {
	int x = 0;
	unsigned int unsignedx = 1; // no negs
	float f = 0;
	double d = 0.0;
	char c = '0';
	bool b = true;

	int * intpointer;
	char * charpointer;
	bool * boolpointer;

	// print out types and respective sizes
	cout << "Int size: " << sizeof(x) << endl;
	cout << "Unsigned Int size: " << sizeof(unsignedx) << endl;
	cout << "Float size: " << sizeof(f) << endl;
	cout << "Double size: " << sizeof(d) << endl;
	cout << "Char size: " << sizeof(c) << endl;
	cout << "Bool size: " << sizeof(b) << endl;

	cout << "Int Pointer size: " << sizeof(intpointer) << endl;
	cout << "Char Pointer size: " << sizeof(charpointer) << endl;
	cout << "Bool Pointer size: " << sizeof(boolpointer) << endl;
}

void outputBinary(unsigned int unsignedx) {
	string output;
	// 32-bit binary representation
	if (unsignedx == 0) {
			cout << "0000 0000 0000 0000 0000 0000 0000 0000" << endl;
		}

	for (int i = 31; i >= 0; i--) {
		if ((i + 1) % 4 == 0) {
			output = output + " ";
		}
		// left shift operator & binary and operator
		if ((1 << i) & unsignedx) {
			output = output + "1";
		} else {
			output = output + "0";
		}
	}
	cout << "Output:" << output << endl;

}

void overflow() {
	// add 1 to unsigned variable int containing max
	unsigned int unsignedx = 4294967295;
	int x = unsignedx + 1;
	if (x) {
		cout << "Overflow at " << x << endl;
		cout << "Max of an unsigned integer is 32 1's. If you add one, the bits are flipped in a carry over method and it results in overflow." << endl;
	}
}

int main() {
	// ask for single-digit integer input x
	cout << "Enter an integer: " << endl;
	int x;
	cin >> x;

	sizeOfTest();
	outputBinary(x);
	overflow();
}

