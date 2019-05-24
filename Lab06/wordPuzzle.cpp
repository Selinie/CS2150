// Selinie Wang (jw6qe@virginia.edu)
// October 25, 2018
// wordPuzzle.cpp
// O(n^4) for quad nested forward loops
// for the 4x7 grid, running time is 0.003368 seconds
// for the 250x250 grid, running time is 109.966 seconds

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>

#include "hashTable.h"
#include "timer.h"

using namespace std;

// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
#define MAXROWS 500
#define MAXCOLS 500

char grid[MAXROWS][MAXCOLS];
timer t;

// Forward declarations
bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);



/** The main() function shows how to call both the readInGrid()
 * function as well as the getWordInGrid() function.
 */
int main(int argc, char* argv[]) { // command line parameters
    // to hold the number of rows and cols in the input file
    int rows, cols;
    int wordsFound = 0;
    int count = 0;
    timer t;

    // if less than three arguments
	if (argc < 3) {
		cout << "Less than three arguments." << endl;
	}

	// FIRST PASS THRU DICT FILE

	string dictFile = argv[1]; // dictionary filename
	string line;
	ifstream dictionary(dictFile.c_str()); // ifstream is c-style string

	// READING FROM A DICTIONARY & COUNT NUM OF ELEMENTS
	if (!dictionary.is_open()) {
		cout << "Dictionary failed to open." << endl;
	} else {
		while(getline(dictionary, line)) {
			// cout << line << '\n';
			count++;
		} 
	} dictionary.close();

	// CREATE APPROPRIATE SIZED HASH TABLE
	hashTable* table = new hashTable(count);
	dictionary.open(dictFile.c_str());
	string line2;
    // cout << "Error" << endl;
	while (dictionary.good()) {
		getline(dictionary, line2);
		if (line2.length() >= 3) {
			table -> insert(line2);
		}
	} // cout << "Error 2" << endl;

	// SECOND PASS THRU DICT FILE

	string gridFile = argv[2]; // grid filename
    dictionary.close();
	string direction;
	dictionary.open(gridFile.c_str());

	if (!readInGrid(gridFile.c_str(), rows, cols)) {
        cout << "Cannot read file." << endl;
    } else {
        readInGrid(gridFile.c_str(), rows, cols);
    }
    vector<string> table2;
    stringstream table3;
    t.start(); // start the timer

	// QUADRATIC TIME (FOUR NESTED LOOPS)
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			for (int dir = 0; dir <= 7; dir++) {
				for (int len = 3; len <= 22; len++) {
					string currentWord(getWordInGrid(row, col, dir, len, rows, cols));
					if (currentWord.length() < len) {
						break;
					} if (table -> contains(currentWord)) {
						wordsFound++;
						switch(dir) { // get word in grid direction
							case 0:
								direction = "N";
								break; // north
							case 1:
								direction = "NE";
								break; // north-east
							case 2:
								direction = "E";
								break; // east
							case 3:
								direction = "SE";
								break; // south-east
							case 4:
								direction = "S";
								break; // south
				            case 5:
				                direction = "SW";
				                break; // south-west
				            case 6:
				                direction = "W";
				                break; // west
				            case 7:
				                direction = "NW";
				                break; // north-west
						} //cout << direction << "(" << row << "," << col << "):" 
							//<< currentWord << endl;
                        table3 << direction << "(" << row << "," << col << "): "
                            << currentWord << endl;
                        string table4 = table3.str();
                        table2.push_back(table4);
                        table3.str("");
					}
				}
			}
		}
	}
    // print out list
    for (int i = 0; i < table2.size(); i++) {
        // cout << table2[i] << endl;
        cout << table2[i];
    }
	t.stop();
	cout << wordsFound << " words found" << endl;
	cout << "Found all words in " << t.getTime() << " seconds" << endl;
    cout << (t.getTime() * 1000) << " milliseconds" << endl;

    return 0;
}

    /*
    // attempt to read in the file
    bool result = readInGrid ("5x8.grid.txt", rows, cols);
    // if there is an error, report it
    if ( !result ) {
        cout << "Error reading in file!" << endl;
        exit(1); // requires the <stdlib.h> #include header!
    }
    // Get a word (of length 10), starting at position (2,2) in the
    // array, in each of the 8 directions
    cout << endl;
    for ( int i = 0; i < 8; i++ )
        cout << i << ": " << getWordInGrid(2,2,i,10,rows,cols) << endl;
    // All done!
    */




/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columnss as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    // cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    // cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            // cout << grid[r][c];
        }
        // cout << endl;
    }
    // return success!
    return true;
}



/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static char[][] variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A char* containing the letters in the provided direction
 *         (NOTE: it is returned in a static char array).
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}
