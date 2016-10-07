

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
	G.export_graph();




}