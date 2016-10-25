

#include "graph2.h"
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>

using namespace std;



int main()
{
	srand(time(NULL));

	graph G;
	graph P;
	/*
	stringstream ss;
	int edges = 4000;
	int nodes = 300;
	string A[nodes];
	for (short i = 0; i < nodes; i++)
	{
		ss << i;
		A[i] = ss.str();
		ss.str("");
	}

	
	string s;
	string t;
	for (short i = 0; i < nodes; i++)
	{
		
		s = A[i];
		G.insert_node(s);
	}

	int upperbound = rand() % edges;
	
	for (short i = 0; i < upperbound; i++)
	{
		s = A[rand()%nodes];
		t = A[rand()%nodes];
		G.insert_edge(s,t, rand() % 25);
	}
	*/
	string A="A",B="B",C="C",D="D",E="E",F="F";

	G.insert_node(A);
	G.insert_node(B);
	G.insert_node(C);
	G.insert_node(D);
	G.insert_node(E);
	G.insert_node(F);

	G.insert_edge(D,F,2);
	G.insert_edge(C,D,3);
	G.insert_edge(D,E,3);
	G.insert_edge(B,E,5);
	G.insert_edge(D,B,6);
	G.insert_edge(F,E,7);
	G.insert_edge(C,A,7);
	G.insert_edge(A,B,9);


	G.ToGraphviz();
	P = G.KruskalMST();
	P.ToGraphviz();

	return 0;

}