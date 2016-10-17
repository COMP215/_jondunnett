#ifndef GRAPH_2_H
#define GRAPH_2_H

#include <string>
#include <iostream>

class Node
{
public:
	Node();
	Node(std::string);
	std::string name_;
};

class edge
{
public:
	edge();
	edge(Node*,Node*);
	edge(Node*,Node*,int);
	Node* left_;
	Node* rite_;
	int weight;
};


class graph
{
public:
	int start_len;
	Node* NA_;
	int hmrNA;
	edge* EA_;
	int hmrEA;
	graph();
	bool insert_node(std::string);
	Node* find_node(std::string);
	bool insert_edge(std::string,std::string);
	bool insert_edge(std::string,std::string, int);
	void ToGraphviz();
	Graph KruskalMST();
	Graph PrimMST(); 
};

#endif