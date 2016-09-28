#include "in_class_bst.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	bst* people_names = new bst();
	/*
	people_names->insert("gousie");
	people_names->insert("bloch");
	people_names->insert("armstrong");
	people_names->insert("decoste");
	*/


	ifstream infile;
	infile.open("foowords.txt");
	string line;
	while (infile)
	{
		getline(infile,line);
		people_names->Insert(line);
	}
	infile.close();

	infile.open("words.txt");



	people_names->InOrder();


	cout << "Done." << endl;

	return 0;
}
