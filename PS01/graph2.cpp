#include "graph2.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>

using namespace std;

Node::Node()
{
	name_ = '\0';
}

Node::Node(string x)
{
	name_ = x;
}

edge::edge()
{
	left_ = 0;
	rite_ = 0;
	weight = 1;
}

edge::edge(Node* x, Node* y)
{
	left_ = x;
	rite_ = y;
	weight = 1;
}

edge::edge(Node* x, Node* y, int w)
{
	left_ = x;
	rite_ = y;
	weight = w;
}


graph::graph()
{
	start_len = 100000;
	NA_ = new Node[start_len];
	hmrNA = 0;
	EA_ = new edge[start_len];
	hmrEA = 0;
}

bool graph::insert_node(string name)
{
	Node A = Node(name);
	NA_[hmrNA] = A;
	hmrNA++;
	return true;
}

bool graph::insert_edge(string name1, string name2)
{
	Node* n1 = find_node(name1);
	Node* n2 = find_node(name2);
	if (n1 && n2)
	{
		edge A = edge(n1,n2);
		EA_[hmrEA] = A;
		hmrEA++;
	}
}

bool graph::insert_edge(string name1, string name2, int w)
{
	Node* n1 = find_node(name1);
	Node* n2 = find_node(name2);
	if (n1 && n2)
	{
		edge A = edge(n1,n2,w);
		EA_[hmrEA] = A;
		hmrEA++;
	}
}


Node* graph::find_node(string name)
{
	Node* return_pointer = 0;
	for (short i = 0; i < hmrNA ; i++)
	{
		if (name == NA_[i].name_)
		{
			return_pointer = &NA_[i];
			break;
		}
	}

	return return_pointer;
}

void graph::ToGraphviz()
{
	ofstream fout;
	fout.open("helloworld.dot");

	Node* out1;
	Node* out2;
	int weight__;

	fout << "graph g {" << endl;
	for (short i = 0; i < hmrEA ; i++)
	{
		out1 = EA_[i].left_;
		out2 = EA_[i].rite_;
		weight__ = EA_[i].weight;
		fout << out1->name_ << "--" << out2->name_ << "[label=" << weight__ << "]" << endl;
	}

	fout << "}" << endl;

}

Graph KruskalMST()
{
	graph G;
	edge* unsorted = this->EA_;
	edge* sorted = new edge[this->hmrEA];
	int   hmrSorted = 0;
	int   indexes_done[hmrEA];
	int   hmr_done = 0;
	bool  done = false;
	int   least = 1000;

	for (short i = 0; i < hmrEA; i++)
	{
		for (short j=0; j < hmrEA; j++)
		{
			if (i == indexes_done[j])
			{
				done = true;
			}
		}

		if (!done)
		{
			if(least > (unsorted[i]->weight_))
			{
				least = (unsorted[i]->weight_);
				indexes_done[hmr_done] = i;
				hmr_done++;
			}
		}

		done = false;
	}

	for (short i=0; i < hmrEA; i++)
	{
		sorted[i] = unsorted[indexes_done[i]];
	}
	

	int nodes_in_G[this->hmrNA];

	for (short i = 0; i < hmrEA;i++)
	{
		
	}







	return G;
}

Graph PrimMST()
{
	Graph G;


	return G;
} 
