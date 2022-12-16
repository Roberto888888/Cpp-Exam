#include <iostream>
#include "Ex04.h"



// Do not modify
template <class T>
mydeque<T>::mydeque() {
	size  = 0;
	first = last = nullptr;
}


// Do not modify
template <class T>
int mydeque<T>::getSize() {
	return size;
}


// (There was an ERROR in this function: the conditional operation in the 'if'
// was != instead of ==)

// Do not modify
template <class T>
void mydeque<T>::print_front() {
	if (size == 0)
		std::cout << "The deque is empty." << std::endl;
	else
		std::cout <<    first->content     << std::endl;
}


// Do not modify
template <class T>
void mydeque<T>::print() {
	if (size == 0)
		std::cout << "The deque is empty." << std::endl;
	else {
		std::cout << "The deque has size " << size << " :" << std::endl;
		Node<T> * current = first;
		while (current != nullptr) {
			cout << " " << current->content << std::endl;
			current = current->next;
		}
	}
}


// Do not modify
template <class T>
void mydeque<T>::push_when_empty(T v) {
	Node<T> * node = new Node<T>;
	node->content  = v;
	node->next     = nullptr;
	first = last   = node;
	size  = 1;
}

/////////////////////////////////////////////////////////////////////////////

// Exercise 4 (a) Check and correct if necessary

/*template <class T>
mydeque<T>::~mydeque() {
	Node<T> * current = first;
	while (current != nullptr) {
		delete current;
		Node<T> * next = current->next;   // ERROR
		current = next;                   // ERROR
	}
	std::cout << "Destructor completed" << std::endl;
}*/

// ERROR:
// Node deallocated before the address to the next node is read.

// CORRECTED CODE:
// I preferred to use a service method to perform the deallocation
// recursively.

template <class T>
mydeque<T>::~mydeque() {
	if (first) {
		empty(first); 
		std::cout << "Destructor completed" << std::endl;
	}
	else
		std::cout << "Nothing to destroy" << std::endl;
}

template <class T>
void mydeque<T>::empty(Node<T> * n){
	if (n->next)
		empty(n->next);
	delete n;
}



// Exercise 4 (b) Implement this function

template<class T>
void mydeque<T>::push_back(T v) {
	Node<T> * node = new Node<T>;
	if (size == 0)
		push_when_empty(v);
	else {
		node->content = v;
		node->next = nullptr;
		last->next = node;
		last = node;
		size++;
	}
}


// Exercise 4 (c) Implement this function

template<class T>
void mydeque<T>::push_front(T v) {
	Node<T> * node = new Node<T>;
	if (size == 0)
		push_when_empty(v);
	else {
		node->content = v;
		node->next = first;
		first = node;
		size++;
	}
}



// Exercise 4 (d) Check and correct if necessary

/*template<class T>
void mydeque<T>::print_back() {
	if (size != 0) {                          // ERROR 1
		cout << "The deque is empty.\n";
	}
	else {
		cout << first->content << "\n";       // ERROR 2
	}
}*/

// 1. The check for empty deque is size == 0
// 2. The back of the deque is the last element, not the first.


template<class T>
void mydeque<T>::print_back() {
	if (size == 0)
		std::cout << "The deque is empty." << std::endl;
	else
		std::cout << last->content << std::endl;
}


















// Exercise 4 (e) Complete body of last else

// The old 2nd element becomes the 1st
// The old 1st element is deleted
// Be careful not to delete the 1st element after reassigning it

template<class T>
bool mydeque<T>::pop_front() {
	if (size == 0) {
		return false;
	}
	else if (size == 1) {
		delete first;
		first = nullptr;
		last  = nullptr;
		size  = 0;
		return true;
	}
	else {
		auto next = first->next;
		delete first;
		first = next;
		size--;
	}
} 


//Do not modify
template class mydeque<int>;