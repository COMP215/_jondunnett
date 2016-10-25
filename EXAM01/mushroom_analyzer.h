#ifndef MUSHROOM_ANALYZER
#define MUSHROOM_ANALYZER
#include <string>
#include <iostream>

class mushroom
{
public:
	float ounces_available;
	float total_value_available;
	float price_per_ounce;
	float amount_taken;
	std::string common_name;
	std::string scientific_name;
};

class bag
{
	float capacity_;
	float current_load_;
	float capacity_left_;
	float total_value_;
	int hmrMushrooms;
	mushroom in_bag[10];
public:
	bag(float capacity);
	bool add_mushroom(mushroom);
	void calculate_total_value();
	void print(std::ostream&);


};

#endif