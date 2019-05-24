// Selinie Wang (jw6qe@virginia.edu)
// List.cpp
// September 9, 2018

#include <iostream>
#include <stdio.h>
#include "List.h"

using namespace std;

List::List() {
	head = new ListNode;
	tail = new ListNode;
	count = 0;
	head -> next = tail;
	tail -> previous = head;
}

List::List(const List& source) { // copy constructor method
	head = new ListNode;
    tail = new ListNode;
    head -> next = tail;
    tail -> previous = head;
    count = 0;
    ListItr iter(source.head -> next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
   }
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return * this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return * this;
}

List::~List() { // make list empty; reclaim memory allocated for head & tail
	makeEmpty();
	delete head;
	delete tail;
}

bool List::isEmpty() const { // returns true if list is empty
	return count == 0;
}

void List::makeEmpty() { // removes all items from list
	ListNode *node = head -> next;
	while (node == tail == false) {
		node = node -> next;
		delete node -> previous;
		node -> next = node -> next;
		node -> previous -> next = node -> next;
	}
	head -> next = tail;
	tail -> previous = head;
}

ListItr List::first() {
	ListItr *iterator = new ListItr(); // returns iterator
	*iterator = head -> next; // element after the head
	return *iterator;
}

ListItr List::last() { 
	ListItr *iterator2 = new ListItr(); // returns iterator
	*iterator2 = tail -> previous; // element before the tail
	return *iterator2;
}

void List::insertAfter(int x, ListItr position) {
	ListNode *newNode = new ListNode();
	newNode -> value = x; // set node into x value

	newNode -> previous = position.current;
	newNode -> next = position.current -> next;
	position.current -> next -> previous = newNode;
	position.current -> next = newNode;
	count++;
}

void List::insertBefore(int x, ListItr position) { // opposite of insertAfter
	ListNode *newNode = new ListNode();
	newNode -> value = x; // set node into x value

	newNode -> next = position.current;
	newNode -> previous = position.current -> previous;
	position.current -> previous -> next = newNode;
	position.current -> previous = newNode;
	count++;
}

void List::insertAtTail(int x) {
	ListNode *newNode = new ListNode();
	newNode -> value = x;
	ListNode *previousNode = tail -> previous;
	previousNode -> next = newNode;

	tail -> previous = newNode;
	newNode -> previous = previousNode;
	newNode -> next = tail;
	count++;
}

void List::remove(int x) { // removes first occurance of x
	ListItr *iterator3 = new ListItr;
	*iterator3 = find(x);
	iterator3 -> current -> previous -> next = iterator3 -> current -> next;
	iterator3 -> current -> next -> previous = iterator3 -> current -> previous;
	delete iterator3;
	count--;
}

ListItr List::find(int x) {
	ListItr *iterator4 = new ListItr(head);
	while (iterator4 -> isPastEnd() == false) {
		iterator4 -> current = iterator4 -> current -> next;
		if (iterator4 -> current -> value == x) {
			return *iterator4;
		} iterator4 -> moveForward();
	}
	return *iterator4;
}

int List::size() const { // returns number of elements in list
	return count;
}

void printList(List& source, bool direction) {
	ListItr firstitr = ListItr(source.first());
	ListItr lastitr = ListItr(source.last());
	if (direction == true) {
		while (firstitr.isPastEnd() == false) {
			cout << firstitr.retrieve() << " ";
			firstitr.moveForward();
		}
	} else {
		while (lastitr.isPastBeginning() == false) {
			cout << lastitr.retrieve() << " ";
			lastitr.moveBackward();
		} 
	}
}