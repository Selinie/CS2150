// Selinie Wang (jw6qe@virginia.edu)
// September 15, 2018
// testPostfixCalc.cpp

#include "postfixCalculator.h"
#include "stack.h"
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int main() {

    postfixCalculator p;

    cout << "Input integers and operators separated by a space." << endl;
    cout << "Press ENTER to end line & CTRL + D to execute." << endl; // hit enter, then control D

    string s;
    const char *cstr = (char*)s.c_str();

    while (cin >> s) {

        if (s == "") { // account for when input is empty
        	break;
        }

        // c_str() gets c string equivalent
    	// isdigit() checks if character is decimal digit
    	// atoi() converts string to integer
    	
    	if (isdigit(cstr[0]) == true) { // if first digit is a decimal
    		int num1 = atoi(cstr);
    		p.pushNum(num1);
    	} else {
    		if (s.length() >= 2) { // length should be greater/equal to 2 b/c "-x"
    			if (s[0] == '-') { // includes - to signify negative
    				// '' instead of "" because char* not int
    				int num2 = atoi(cstr);
    				p.pushNum(num2);
    			}
    		}
    	}

    	if (s == "+") {
    		p.add();
    	} if (s == "-") {
    		p.subtract();
    	} if (s == "*") {
    		p.multiply();
    	} if (s == "/") {
    		p.divide();
    	} else if (s == "~") {
    		p.negate();
    	}

    }

    cout << "Expected output: " << p.getTopValue() << endl;
    /*
    
    // testing addition method
    p.pushNum(1);
    p.pushNum(2);
    p.pushNum(3);
    p.pushNum(4);
    p.pushNum(5);
    p.add();
    p.add();
    p.add();
    p.add();
    cout << "Sum: " << p.getTopValue() << endl; // expected output: 15

    // testing subtraction method
    p.pushNum(2);
    p.pushNum(4);
    p.subtract();
    cout << "Difference: " << p.getTopValue() << endl; // expected output: -2

    // testing multiplication method
    p.pushNum(3);
    p.pushNum(4);
    p.multiply();
    cout << "Product: " << p.getTopValue() << endl; // expected output: 12

    // testing division method
    p.pushNum(4);
    p.pushNum(2);
    p.divide();
    cout << "Quotient: " << p.getTopValue() << endl; // expected output: 2

    // testing negation method
    p.pushNum(-2);
    p.negate();
    cout << "Negate: " << p.getTopValue() << endl; // expected output: 2

    // testing empty statement
    postfixCalculator calc;
    calc.add(); // stack should be empty
    */
    
    return 0;
}