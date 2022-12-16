#include <iostream>
#include <deque>
#include <string>
#include "Ex02.h"



////////////////////////////////////////////////////////////
// Caller functions:
////////////////////////////////////////////////////////////

void experimentParentNodes(Node * n) {
	//std::set<std::string> parents;
	std::deque<std::string> parents;
	computeParentNodes(n , parents);
	std::cout << "The nodes with children starting from "
		      << n->name << " are:\n";
	//printSet(parents);
	printTree(parents);
}


void experimentSubtree(Node * n) {
	//std::set<std::string> members;
	std::deque<std::string> members;
	computeMembersOfSubTree(n , members);
	std::cout << "The sub-tree with root in " << n->name
		      << " contains:\n";
	//printSet(members);
	printTree(members);
}


/////////////////////////////////////////////////////////////


int main() {
	/* Bob’s family tree from text */
	Node * Alice  = new Node;
	Alice->name   = "Alice";

	Node * Bob    = new Node;
	Bob->name     = "Bob";

	Node * Carl   = new Node;
	Carl->name    = "Carl";

	Node * Daisy  = new Node;
	Daisy->name   = "Daisy";

	Node * Emma   = new Node;
	Emma->name    = "Emma";

	Node * Bob1   = new Node;
	Bob1->name    = "Bob";

	Node * Joe    = new Node;
	Joe->name     = "Joe";

	Alice->left   = Bob;
	Alice->right  = Carl;

	Bob->left     = Daisy;
	Bob->right    = nullptr;

	Carl->right   = Emma;
	Carl->left    = Bob1;

	Bob1->left    = Joe;
	Bob1->right   = nullptr;

	Joe->left     = nullptr;
	Joe->right    = nullptr;

	Daisy->left   = nullptr;
	Daisy->right  = nullptr;

	Emma->left    = nullptr;
	Emma->right   = nullptr;

	std::cout << "Experiments about parent nodes\n";
	experimentParentNodes(Alice);
	experimentParentNodes(Bob);
	experimentParentNodes(Carl);
	experimentParentNodes(Bob1);
	experimentParentNodes(Joe);
	experimentParentNodes(Daisy);
	experimentParentNodes(Emma);
	
	std::cout << "Experiment about sub-tree\n";
	experimentSubtree(Alice);
	experimentSubtree(Bob);
	experimentSubtree(Carl);
	experimentSubtree(Bob1);
	experimentSubtree(Joe);
	experimentSubtree(Daisy);
	experimentSubtree(Emma);

	return 0;
}