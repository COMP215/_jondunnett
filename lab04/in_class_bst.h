#ifndef binarysearchtree_h
#define binarysearchtree_h
#include <stdio.h>
#include <string>

class Node;

class bst
{
public:
	Node* root_;               // tree root pointer 
	bst();                     // default (and only) CTOR
	bool Insert(std::string);   // insert something into tree(don't worry where I gotchu)
	void InOrder();            // in order tree traversal
	void InOrder(Node*);     // I'm not really sure on this one
	Node* search(std::string); // search method
	bool delete_node(std::string);  // delete method 
};

class Node
{
public:
	std::string data_;         // names/words that we are storing
	Node* left_;               // left child of the node
	Node* right_;              // right chile of the node
	Node(std::string);         // node CTOR (only one) takes a string
};

#endif // binarysearchtree_h