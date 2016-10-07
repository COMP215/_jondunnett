/* THIS IS LAB 5 */
#ifndef GRAPH_H
#define GRAPH_H

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
	edge(Node* n1, Node* n2);
	Node* n1_;
	Node* n2_;
};

class graph
{
public:
	graph();
	edge* ep_;
	int hmrep_;
	Node* np_;
	int hmrnp_;
	bool add_node(std::string);
	bool add_edge(Node* n1, Node* n2);
	bool add_edge(std::string, std::string);
	bool IsBipartite();
	void print_graph(std::ostream&);
	//friend std::ostream& operator<<(std::ostream&, graph);
	//friend std::istream& operator>>(std::istream&, graph&);

};

#endif