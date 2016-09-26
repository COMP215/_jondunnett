#include "in_class_bst.h"
#include <string>
#include <iostream>

using namespace std;
/*
  TO DO:
    - search method for each (LL and BST) bool search(std::string)
    - delete method for each (LL and BST) bool delete(std::string)

    Repository structure:
      - Lab_01
      - Lab_02
      - Lab_03
      - Lab_04
        - main.cpp
        - binarytree.cpp
        - binarytree.hpp
        - two other things I can't read....
        - README.md
*/

Node::Node(string data)
// CTOR takes a string and initializes the Node
{
	data_  = data;
	left_  = NULL;
	right_ = NULL;
}

bst::bst()
// DEFAULT CTOR
{
	root_ = NULL;
}

Node* bst::search(string what_u_want)
// search method to find nodes 
// Precondition : valid string of the data thats being stored
// Postcondition: 
{
	if (root_ == NULL)
		return 0;
	else {
		Node* curr = root_;
		while (curr->data_ != what_u_want)
		{
			if (curr->data_ == what_u_want){
				return curr;
			}
			else if (curr->data_ > what_u_want){
				if (curr->left_ == NULL)
					return 0;
				curr = curr->left_;
			} else {
				if (curr->right_ == NULL)
					return 0;
				curr = curr->right_;
			}
		}
	}
}

bool bst::delete_node(string deletion_target)
{
	return false;
}

bool bst::Insert(string data)
{
	if (root_ == NULL) {
		root_ = new Node(data);
		return true;
	} else {
		Node* curr = root_;
		while(curr != NULL) {
			if (data == curr->data_){
				return false;
			} else if (data < curr->data_) {
				if (curr->left_ == NULL) {
					curr->left_ = new Node(data);
					return true;
				} else {
					curr = curr->left_;
				}
			} else {
				if (curr->right_ == NULL) {
					curr->right_ = new Node(data);
				} else {
					curr = curr->right_;
				}
			}
		}
		//if (data < curr->data_) {
		//	if(curr->left_ == NULL)
		//} 
	}
	return false; 
}

void bst::InOrder(){
if (root_ != NULL){
	InOrder(root_);
	}
}

void bst::InOrder(Node* node){
	if (node->left_ != NULL){
		InOrder(node->left_);
	}
	cout << node->data_ << endl;
	if (node->right_ != NULL){
		InOrder(node->right_);
	}
}