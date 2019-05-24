// Selinie Wang (jw6qe@virginia.edu)
// September 18, 2018
// stack.cpp

#include "stack.h"
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

stack::stack() {
	stack1 = new List();
}

stack::~stack() {
	delete stack1;
}

// adds the passed element to top of stack
void stack::push(int e) {
	ListItr iterator1 = stack1 -> first();
	stack1 -> insertBefore(e, iterator1);
}

// returns element on the top of stack
// does not remove the element on top
int stack::top() {
	ListItr iterator2 = stack1 -> first();
	if (stack1 -> size() != 0) {
		return iterator2.retrieve();
	} else {
		cout << "Stack is empty." << endl;
		exit(-1);
	}
}

// removes element on the top of stack
void stack::pop() {
	ListItr iterator3 = stack1 -> first();
	if (stack1 -> size() != 0) {
		stack1 -> remove(iterator3.retrieve());
	} else {
		cout << "Stack is empty." << endl;
	}
}

// tells whether any elements left in stack
bool stack::empty() {
	if (stack1 -> size() == 0) {
		return true;
	} else {
		return false;
	}
}