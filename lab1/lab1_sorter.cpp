#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


std::vector< std::string > ProgramTwo(char* filename);
//void place_word(std::string word, std::vector< std::string>& final_array);
//void shift_array(std::vector< std::string > A, short startpos);
short whichshorter(short x, short y);
void organize(std::vector< std::string >& A);


short whichshorter(short x, short y)
{
	if( x > y)
		return y;
	else if (y > x)
		return x;
	else 
		return x;
}

std::vector< std::string > ProgramTwo(char* infilename)
{
	std::ifstream fin;
	std::string line;
	std::vector< std::string > og_array;
	og_array.resize(1000);
	fin.open(infilename);
	short i = 0;
	while (fin) 
	{
		std::getline(fin,line);
		og_array[i] = line;
		i++;
	}
	og_array.resize(i);

	for (short i = 0; i < og_array.size(); i++)
		std::cout << og_array[i] << std::endl;
	organize(og_array);

	fin.close();
	return og_array;

}


void organize(std::vector< std::string >& A)
{
	bool notdone = true;
	bool swaps = true;
	short swapCount = 0;
	std::string temp = "";
	while(notdone)
	{
		if(swaps)
		{
			swaps = 0;
			for (short i = (A.size() - 1); i > 0; i-- )
			{
				if(A[i-1] < A[i -2])
				{
					swapCount++;
					std::cout << "Swapped: " << A[i-1] << " and " << A[i-2] << std::endl;
					temp = A[i-2];
					A[i-2] = A[i-1];
					A[i-1] = temp;
				}
			}
			if (swapCount == 0)
			{
				swaps = false;
			}
		}
		else
		{
			notdone = false;
		}
	}
	for (short i = 0; i < A.size(); i++)
		std::cout<< A[i] << std::endl;
}
/*

void place_word(std::string word, std::vector< std::string>& final_array)
{
	for (short i = 0; i < final_array.size(); i++)
	{
		if (final_array[i] == "[")
		{
			final_array[i] = word;
			break;
		}
		bool done = false;
		for (short j = 0; j < whichshorter(word.length(),final_array[i].length()); j++)
		{
			if (word[j] > final_array[i][j])
			{
				done = true;
				break;
			} 
			else if (word[j] < final_array[i][j])
			{

				final_array[i] = word;
				done = true;
				break;
			}
			else
			{
				std::cout << word[j] << " == " << final_array[i][j] << std::endl;
			}
		}
		break;
	} 
}
*/