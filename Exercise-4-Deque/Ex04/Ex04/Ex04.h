#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_


template <class T>
struct Node {
	T content;
	Node<T> * next;
};

/////////////////////////////////

template <class T>
class mydeque {

private:
	Node<T> * first;
	Node<T> * last;
	int  size;
	void empty(Node<T> *);

public:
	mydeque();
	~mydeque();
	int  getSize();
	void push_when_empty(T);
	void print_front();
	void print_back();
	void print();
	void push_back(T);
	void push_front(T);
	bool pop_front();
};

#endif