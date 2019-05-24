// Selinie Wang (jw6qe@virginia.edu)
// ListItr.cpp
// September 9, 2018

#include <iostream>
#include <stdio.h>
#include "ListItr.h"
#include "ListNode.h"

using namespace std;

ListItr::ListItr() { // Constructor for ListItr(); set variable to null
	current = NULL;
}

ListItr::ListItr(ListNode* theNode) { // one parameter constructor
	current = theNode;
}

bool ListItr::isPastEnd() const { // returns true if past end position in list
	return (current -> next == NULL);
}

bool ListItr::isPastBeginning() const { // returns true if past first position in list
	return (current -> previous == NULL);
}

void ListItr::moveForward() { // advances pointer to the next position
	if (isPastEnd() == false) {
		current = current -> next;
	}
}

void ListItr::moveBackward() { // move pointer back to the previous position
	if (isPastBeginning() == false) {
		current = current -> previous;
	}
}

int ListItr::retrieve() const { // returns value of item in current position of list
	return current -> value;
}