#include <iostream>
#include <set>
#include <string>
#include "Ex02.h"


// ERROR in given code:
// namespace not specified
// Either use 'using' or std:: all over the code when needed.

void printSet(std::set<std::string> s) {
	if (s.size() == 0) {
		std::cout << " No nodes\n";
	}
	else {
		// UNNECESSARY: this iterator can be declared as
		// 'auto' inside the for loop
		std::set<std::string>::iterator it;     
		for (it = s.begin() ; it != s.end() ; ++it)
			//cout << ’ ’ << *it << "\n";              // Two ERRORS
			std::cout << ' ' << *it << '\n';           // CORRECTED
	}
	std::cout << "\n";
}


////////////////////////////////////////////////////////////////////////////
// Exercise 2 (a) Check and correct if necessary
////////////////////////////////////////////////////////////////////////////

// PROBLEMS:
// - std:: is missing in various points (minor problem).
// - It calls itself even when it knows there are no children so there will
//   be at least 2 calls to the function with nullptr where the function
//   will try to call the left and right nodes of nullptr.

// GIVEN CODE:
// void computeParentNodes(Node* n, set<string> & parents) {
//	 if (n->left != nullptr || n->right != nullptr)
//		 parents.insert(n->name);
//	 computeParentNodes(n->left, parents);
//	 computeParentNodes(n->right, parents);
// }

// IMPROVED CODE:

using SETStr = std::set<std::string>;

void computeParentNodes(Node * n, SETStr & parents) {
	if (n->left != nullptr) {
		parents.insert(n->name);
		computeParentNodes(n->left, parents);
	}
	if (n->right != nullptr) {
		parents.insert(n->name);
		computeParentNodes(n->right, parents);
	}
}

////////////////////////////////////////////////////////////////////////////
// Exercise 2 (b) Implement this function
////////////////////////////////////////////////////////////////////////////

// Create a set with all of the names in a subtree given a starting node 'n'

// It's the same as the first exercise but now the nodes with no children
// are included too. It's actually simpler than the previous case.

// There's no point considering a specific order when reading the tree
// because std::set has its own internal ordering.

using SETStr = std::set<std::string>;

void computeMembersOfSubTree(Node * n, SETStr & members) {
	members.insert(n->name);
	if (n->left)
		computeMembersOfSubTree(n->left, members);
	if (n->right)
		computeMembersOfSubTree(n->right, members);
}


/////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////// 

// OBSERVATIONS:

// std::Set automatically avoids writing the same name multiple times,
// resulting in simple and clean code where attempts to insert the same node
// name have no effect.
// At the same time, this creates a problem though:
// if there are people in the family tree with the same name, that name will
// be saved only once, with loss of information.
// Switching to std::multiset solves the second problem but code must be more 
// complex in the computation of a subtree as the code relies on the fact that
// repeated values (when passing through the same node while moving up and down
// the tree) are ignored.

// Another problem with sets and multisets is that these structures internally
// sort elements so when printing out, names will be presented in alphabetical 
// order regardless of how data has been acquired.

// std::unordered_multiset doesn't follow an alphabetical order so it makes a
// bit more sense, but it groups together repeated values when printing out so
// results are a bit unpredictable.

// The best alternative is std:deque. It is a FIFO structure that makes possible
// to print out the tree in a way that is significant (although functions have 
// to be more complex to acquire data correctly) and allows access to elements
// without having to pop them out (unlike simple std::queue).

// The function 'printSet' is exactly the same regardless the data container used
// (set, unordered_set, deque) so it can be templated.