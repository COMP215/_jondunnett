#include "graph.h"
#include <string>

Node::Node(std::string name)
{
	name_ = name;
}

Node::Node()
{
	name_ = "0";
}

edge::edge()
{
	n1_ = 0;
	n2_ = 0;
}

edge::edge(Node* n1, Node* n2)
{
	n1_ = n1;
	n2_ = n2;
}

graph::graph()
{
	ep_ = new edge[10];
	np_ = new Node[10];
	hmrep_ = 0;
	hmrnp_ = 0;
}


bool graph::add_node(std::string name)
{
	Node new_node = Node(name);
	if (hmrnp_ > 10){
		np_[hmrnp_] = new_node;
		hmrnp_++;
	}
	else{
		Node* old_array = np_;
		np_ = new Node[hmrnp_ * 2];
		for (short i = 0; i < hmrnp_ ; i++)
		{
			np_[i] = old_array[i]; 
		}
		delete old_array;
		np_[hmrnp_] = new_node;
		hmrnp_++;
	}
	return true;
}

bool graph::add_edge(std::string n1_name, std::string n2_name)
{
	Node* n1;
	Node* n2;

	for (short i = 0; i < hmrnp_ ; i++)
	{
		if (n1_name == (hmrnp_[i].name_))
			n1 = &hmrnp_[i];
		if (n2_name == (hmrnp_[i].name_))
			n2 = &hmrnp_[i];
	}

	add_edge(n1,n2);
	return true;
}

bool graph::add_edge(Node* n1, Node* n2)
{
	edge A = edge(n1,n2);
	if (hmrep_ > 10){

		ep_[hmrep_] = A;
		hmrep_++;
	}
	else{
		edge* old_array = ep_;
		ep_ = new edge[hmrep_ * 2];
		for (short i = 0; i < hmrep_ ; i++)
		{
			ep_[i] = old_array[i]; 
		}
		delete old_array;
		ep_[hmrep_] = A;
		hmrnp_++;
	}
	return true;
}

