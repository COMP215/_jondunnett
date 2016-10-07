#include "graph.h"
#include <string>
#include <iostream>

Node::Node(std::string name)
{
	name_ = name;
}

Node::Node()
{
	name_ = "\0";
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
		if (n1_name == (np_[i]).name_)
			n1 = &np_[i];
		if (n2_name == (np_[i]).name_)
			n2 = &np_[i];
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

bool graph::IsBipartite()
{
	bool in_array(Node* Na, Node& N);
	Node* v1;
	Node* v2;
	int hmrv1;
	int hmrv2;

	v1 = new Node[hmrnp_];
	v2 = new Node[hmrnp_];

	bool inv1;
	bool inv2;
	for (short i = 0; i < hmrep_ ; i++)
	{
		if (in_array(v1,ep_[i]->n1_))
		{
			if (in_array(v1,ep_[i]->n2_))
			{
				return false;
			}
			if (!in_array(v2,ep_[i]->n2))
			{
				v2[hmrv2] = ep_[i]->n2;

			}
		}
		if (in_array(v2,ep_[i]->n1_))
		{
			if (in_array(v2,ep_[i]->n2_))
			{
				return false;
			}
			if (!in_array(v1,ep_[i]->n1))
			{
				v1[hmrv1] = ep_[i]->
			}

		}
	}

	return true;
}

bool in_array(Node* Na, Node& N)
{
	return true;
}

/*
std::ostream& operator<<(std::ostream& out, graph A)
{

	if (A.ep_ != 0)
	{
		out << "graph G {\n";
		for (short i = 0; i < A.hmrep_ ; i++)
		{
			if ((A.ep_[i].n1_ != 0) && (A.ep_[i].n2_ != 0))
			{
				out << (A.ep_[i].n1_)->name_ << " -- " << (A.ep_[i].n2_)->name_ << "\n";
			}	
		}
		out << "}";
	}
	else
		out << "No valid graph...";

	return out;
}
*/



