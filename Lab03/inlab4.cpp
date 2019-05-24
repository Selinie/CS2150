// Selinie Wang (jw6qe@virginia.edu)
// September 24, 2018
// inlab4.cpp

#include <iostream>
#include <limits>
#include <climits>

using namespace std;

int main() {

	// REPRESENTATION IN MEMORY
	bool boolean = true;
	char character = '0';
	int integer = 0;
	double dvalue = 0.0;
	int * intpointer2 = NULL;
	cout << "Bool: " << boolean << endl;
	cout << "Char: " << character << endl;
	cout << "Int: " << integer << endl;
	cout << "Double: " << dvalue << endl;
	cout << "Int*: " << intpointer2 << endl;

	// PRIMITIVE ARRAYS IN C++

	// int IntArray[10]; // one dimensional array of ints
	int IntArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// char CharArray[10]; // one dimensional array of chars
	char CharArray[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

	int IntArray2D[6][5]; // two dimensional array of ints
	IntArray2D[0][0] = 01;
	IntArray2D[0][1] = 02;
	IntArray2D[0][2] = 03;
	IntArray2D[0][3] = 04;
	IntArray2D[0][4] = 05;
	IntArray2D[1][0] = 06;
	IntArray2D[1][1] = 07;
	IntArray2D[1][2] = 31; // 08 is octal constant
	IntArray2D[1][3] = 32; // 09 is octal constant
	IntArray2D[1][4] = 10;
	IntArray2D[2][0] = 11;
	IntArray2D[2][1] = 12;
	IntArray2D[2][2] = 13;
	IntArray2D[2][3] = 14;
	IntArray2D[2][4] = 15;
	IntArray2D[3][0] = 16;
	IntArray2D[3][1] = 17;
	IntArray2D[3][2] = 18;
	IntArray2D[3][3] = 19;
	IntArray2D[3][4] = 20;
	IntArray2D[4][0] = 21;
	IntArray2D[4][1] = 22;
	IntArray2D[4][2] = 23;
	IntArray2D[4][3] = 24;
	IntArray2D[4][4] = 25;
	IntArray2D[5][0] = 26;
	IntArray2D[5][1] = 27;
	IntArray2D[5][2] = 28;
	IntArray2D[5][3] = 29;
	IntArray2D[5][4] = 30;

	char CharArray2D[6][5]; // two dimensional array of chars
	IntArray2D[0][0] = 'a';
	IntArray2D[0][1] = 'b';
	IntArray2D[0][2] = 'c';
	IntArray2D[0][3] = 'd';
	IntArray2D[0][4] = 'e';
	IntArray2D[1][0] = 'f';
	IntArray2D[1][1] = 'g';
	IntArray2D[1][2] = 'h';
	IntArray2D[1][3] = 'i';
	IntArray2D[1][4] = 'j';
	IntArray2D[2][0] = 'k';
	IntArray2D[2][1] = 'l';
	IntArray2D[2][2] = 'm';
	IntArray2D[2][3] = 'n';
	IntArray2D[2][4] = 'o';
	IntArray2D[3][0] = 'p';
	IntArray2D[3][1] = 'q';
	IntArray2D[3][2] = 'r';
	IntArray2D[3][3] = 's';
	IntArray2D[3][4] = 't';
	IntArray2D[4][0] = 'u';
	IntArray2D[4][1] = 'v';
	IntArray2D[4][2] = 'w';
	IntArray2D[4][3] = 'x';
	IntArray2D[4][4] = 'y';
	IntArray2D[5][0] = 'z';
	IntArray2D[5][1] = '1';
	IntArray2D[5][2] = '2';
	IntArray2D[5][3] = '3';
	IntArray2D[5][4] = '4';

	return 0;
}
