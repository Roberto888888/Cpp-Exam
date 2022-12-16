#include <iostream>
#include "Ex04.h"



int main() {
	mydeque<int> deque;

	std::cout << "Start: " << deque.getSize() << std::endl;
	deque.print_front();

	deque.push_when_empty(32);
	deque.push_front(2);
	deque.push_front(1);
	deque.push_back(3);
	deque.push_back(4);
	deque.push_back(7);
	deque.push_front(9);

	deque.print();

	std::cout << std::endl;

	std::cout << "The first element is: ";
	deque.print_front();

	std::cout << "The last element is: ";
	deque.print_back();

	do {
		std::cout << std::endl;
		std::cout << "pop_front(): ";
		std::cout << deque.pop_front() << std::endl;
		deque.print();
	} while (deque.getSize() > 0);

	std::cout << std::endl;

	std::cout << "pop_front(): ";
	std::cout << deque.pop_front() << std::endl;

	std::cout << std::endl;

	deque.push_when_empty(32);
	deque.push_front(2);
	deque.push_front(1);
	deque.push_back(3);

	return 0;
}