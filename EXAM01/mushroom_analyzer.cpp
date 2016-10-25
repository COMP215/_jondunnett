#include "mushroom_analyzer.h"
#include <stdio.h>
#include <iostream>
#include <math.h>


bag::bag(float capacity)
{
	capacity_ = capacity;
	capacity_left_ = capacity;
	current_load_ = 0;
	total_value_ = 0;
	hmrMushrooms = 0;
}

bool bag::add_mushroom(mushroom y)
{
	if (!fabs(capacity_left_ - 0) < 0.001)
	{
		mushroom taken;
		if (y.ounces_available  > capacity_left_)
		{
			y.amount_taken = capacity_left_;
			capacity_left_ = 0;
			in_bag[hmrMushrooms] = y;
			hmrMushrooms++;
			return true;
		}
		else
		{
			y.amount_taken = y.ounces_available;
			capacity_left_ = capacity_left_ - y.ounces_available;
			in_bag[hmrMushrooms] = y;
			hmrMushrooms++;
			return true;
		}
	}
	else
	{
		return false;
	}
}

void bag::calculate_total_value()
{
	float sum;
	for (short i=0; i<hmrMushrooms; i++)
	{
		sum = sum + in_bag[i].amount_taken * in_bag[i].price_per_ounce;
	}
	total_value_ = sum;
}

void bag::print(std::ostream& out)
{
	mushroom cur;
	for (short i=0; i < hmrMushrooms; i++)
	{
		cur = in_bag[i];
		out << cur.amount_taken << " ounces of" << cur.common_name << "(" << cur.scientific_name << ") " << "mushrooms" << std::endl;
	} 

	out << "--------------------------------" << std::endl;
	printf("Total value $%5.2f", total_value_);
}

void bubble_sort(mushroom list[], int size)
{
    float temp;
    for(int i=0; i<size; i++)
    {
        for(int j=size-1; j>i; j--)
        {
            if(list[j].price_per_ounce < list[j-1].price_per_ounce)
            {
                temp=list[j-1].price_per_ounce;
                list[j-1].price_per_ounce=list[j].price_per_ounce;
                list[j].price_per_ounce=temp;
            }
        }
    }
}