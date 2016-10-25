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
	start_len = 100;
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
	cout << hmrEA << endl;
	if (n1 && n2)
	{
		edge A = edge(n1,n2);
		EA_[hmrEA] = A;
		hmrEA++;
		return true;
	}
	return false;
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
		return true;
	}
	return false;
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

graph graph::KruskalMST()
{
	graph G;
	edge* unsorted = &EA_[0];
	//edge* sorted = new edge[this->hmrEA];
	int   hmrSorted = 0;
	int   indexes_done[hmrEA];
	int   hmr_done = 0;
	bool  done = false;
	int   least = 1000;

	/* Load the nodes into the new graph 
	for (short i=0; i < hmrNA; i++)
		G.insert_node(this->NA_[i].name_);

	/* Sort the edges by wieght */

	qsort(unsorted, sizeof(unsorted)/sizeof(*unsorted), sizeof(*unsorted), comp);


	string left;
	string right;
	for (short i = 0; i < hmrEA;i++)
	{
		left = (unsorted[i].left_)->name_;
		right = (unsorted[i].rite_)->name_;
		if (!(G.find_node(left)) && !(G.find_node(right)))
		{
			G.insert_node(left);
			G.insert_node(right);
			G.insert_edge(left, right, unsorted[i].weight);
		}
		else if (!(G.find_node(left)) && G.find_node(right))
		{
			G.insert_node(left);
			G.insert_edge(left,right, unsorted[i].weight);
		}
		else if (G.find_node(left) && !(G.find_node(right)))
		{
			G.insert_node(right);
			G.insert_edge(left, right, unsorted[i].weight);
		}

	}



	return G;
}

graph graph::PrimMST()
{
	graph G;


	return G;
} 

bool graph::hasCycle()
{
	bool backAti = false;
	string cur;
	string check;
	for(short i=0; i < hmrNA; i++)
	{
		check = NA_[i].name_;
		while(!backAti)
		{
			if (cur == check)
			{
				backAti = true;
			}
		}
	}
}


int graph::comp (const edge elm1, const edge elm2)
{
	if (elm1.weight > elm2.weight)
	{return  1;}
	if (elm2.weight > elm1.weight)
	{return -1;}
	return 0;
}

/*
new algorithm: ( dij_stra's algorithm ) 

- assign total path cost of infinity to each vertex
- update start vertex cost to 0
- while open is not empty:
	- Find vertex with smallest total path cost in open
	- Look at all edges incident on smallest vertex
	- move smallest vertex we found from open to closed

*/