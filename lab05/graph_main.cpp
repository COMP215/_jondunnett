#include "graph.h"
#include <string>
#include <iostream>
int main()
{
	graph A = graph();
	std::string node1 = "22";
	std::string node2 = "43";
	std::string node3 = "99";
	A.add_node(node1);
	A.add_node(node2);
	A.add_node(node3);
	A.add_edge(node1,node2);
	A.add_edge(node2,node3);
	A.add_edge(node1,node3);


	//std::cout << A;





	return 0;
}