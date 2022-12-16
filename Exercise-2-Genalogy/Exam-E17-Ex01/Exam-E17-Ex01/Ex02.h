#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_

#include <set>
#include <deque>
#include <string>

//******************************************************************

struct Node {
	std::string name;
	Node * left;
	Node * right;
};

//******************************************************************

using DQST = std::deque<std::string>;
using SETStr = std::set<std::string>;

void computeParentNodes(Node * n, SETStr & parents);
void computeMembersOfSubTree(Node * n, SETStr & members);

// Improved functions
void computeParentNodes(Node * n, DQST & parents);
void computeMembersOfSubTree(Node * n, DQST & members);

// Printing functions
void printSet(std::set<std::string> s);

template <typename T>
void printTree(T s) {
	if (s.size() == 0)
		std::cout << " No nodes\n";
	else {
		for (auto it = s.begin(); it != s.end(); ++it)
			std::cout << ' ' << *it << '\n';
	}
	std::cout << "\n";
}

#endif