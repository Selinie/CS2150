// Selinie Wang (jw6qe@virginia.edu)
// September 15, 2018
// postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include "stack.h"
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

#include <iostream>
#include <cstdlib>

using namespace std;

class postfixCalculator {

public:
	postfixCalculator(); // constructor
	~postfixCalculator(); // destructor

	/*
	void push(int e);
	void pop();
	bool empty();
	*/

	void add();
	void subtract();
	void multiply();
	void divide();
	void negate();

	void pushNum(int x); // put numbers in calculator
	int getTopValue(); // returns value at top of stack

private:
	stack *stack1;
};

#endif