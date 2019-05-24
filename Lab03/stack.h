// Selinie Wang (jw6qe@virginia.edu)
// September 18, 2018
// stack.h

#ifndef STACK_H
#define STACK_H

#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class stack {

public:
	stack();
	~stack();

	void push(int e);
	int top();
	void pop();
	bool empty();

private:
	List *stack1;
};

#endif