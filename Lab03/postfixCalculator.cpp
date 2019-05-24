// Selinie Wang (jw6qe@virginia.edu)
// September 15, 2018
// postfixCalculator.cpp

#include "postfixCalculator.h"
#include "stack.h"
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

#include <iostream>
#include <cstdlib> // used to terminate program

using namespace std;

postfixCalculator::postfixCalculator() {
	stack1 = new stack;
}

postfixCalculator::~postfixCalculator() {
	delete stack1;
}

// equals operator and copy constructor are not necessary

// addition method
void postfixCalculator::add() {
	if (stack1 -> empty()) {
		cout << "The stack is empty." << endl;
	} else {
		int num1 = stack1 -> top(); // can't do top() -> pop() because void and int arguments
		stack1 -> pop();
		int num2 = stack1 -> top();
		stack1 -> pop();
		stack1 -> push(num1 + num2);
	}
}

// subtraction method
void postfixCalculator::subtract() {
	if (stack1 -> empty()) {
		cout << "The stack is empty." << endl;
	} else {
		int num1 = stack1 -> top();
		stack1 -> pop();
		int num2 = stack1 -> top();
		stack1 -> pop();
		stack1 -> push(num2 - num1); // non-commutative operator
	}
}

// multiplication method
void postfixCalculator::multiply() {
	if (stack1 -> empty()) {
		cout << "The stack is empty." << endl;
	} else {
		int num1 = stack1 -> top();
		stack1 -> pop();
		int num2 = stack1 -> top();
		stack1 -> pop();
		stack1 -> push(num1 * num2);
	}
}

// division method
void postfixCalculator::divide() {
	if (stack1 -> empty()) {
		cout << "The stack is empty." << endl;
	} else {
		int num1 = stack1 -> top();
		stack1 -> pop();
		int num2 = stack1 -> top();
		stack1 -> pop();
		stack1 -> push(num2 / num1); // non-commutative operator
	}
}

// negation method
void postfixCalculator::negate() {
	if (stack1 -> empty()) {
		cout << "The stack is empty." << endl;
	} else {
		int num1 = stack1 -> top();
		stack1 -> pop();
		stack1 -> push(num1 * -1);
	}
}

void postfixCalculator::pushNum(int x) { // put numbers into calculator
	stack1 -> push(x);
}

int postfixCalculator::getTopValue() {
	return stack1 -> top();
}
