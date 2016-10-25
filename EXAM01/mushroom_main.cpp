#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "mushroom_analyzer.h"
#include <math.h>

using namespace std;

float BAG_CAPACITY = 12.5;

void bubble_sort(mushroom [], int);


int main()
{

	ifstream fin;
	fin.open("mushrooms_1.csv");

	bag nice_satchel(BAG_CAPACITY);
	mushroom mushrooms_available[10];
	int hmrMA = 0;
	mushroom one_you_see;

	string line;
	string header;
	int next_pos = 0;
	int last_pos = 0;

	getline(fin,header);
	stringstream convert;


	while (1)
	{

		getline(fin, line);
		if (fin.bad() || line == "")
		{break;}
		cout << line << endl;

		next_pos = line.find(',', last_pos);

		one_you_see.common_name = line.substr(last_pos,next_pos);
		cout << one_you_see.common_name << " read into common_name" << "(" << last_pos << "," << next_pos << ")" << line.length() <<  endl;

		last_pos = next_pos + 1;
		next_pos = line.find(", ", last_pos);

		one_you_see.scientific_name = line.substr(last_pos,next_pos - last_pos);
		cout << one_you_see.scientific_name << " read into scientific_name" << "(" << last_pos << "," << next_pos << ")" << line.length() <<  endl;

		last_pos = next_pos + 1;
		next_pos = line.find(", ",last_pos);

		convert.str(line.substr(last_pos,next_pos - last_pos));
		convert >> one_you_see.ounces_available;
		cout << one_you_see.ounces_available << " read into ounces_available" << "(" << last_pos << "," << next_pos << ")" << line.length() <<  endl;

		last_pos = next_pos + 1;
		next_pos = line.find(", ",last_pos);

		convert.str(line.substr(last_pos,next_pos - last_pos));
		convert >> one_you_see.total_value_available;
		cout << one_you_see.total_value_available << " read into total_value_available" << "(" << last_pos << "," << next_pos << ")" << line.length() <<  endl;

		last_pos = 0;
		next_pos = 0;

		convert.str(string());
		cout << endl;

		one_you_see.price_per_ounce = one_you_see.total_value_available / one_you_see.ounces_available;

		mushrooms_available[hmrMA] = one_you_see;
		hmrMA++;
	}

	bubble_sort(mushrooms_available,hmrMA);
	int count = 0;
	while (nice_satchel.add_mushroom(mushrooms_available[count]) && count < hmrMA)
	{count++;}

	nice_satchel.calculate_total_value();
	nice_satchel.print(cout);

	cout << endl;

	return 0;
}