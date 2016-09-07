#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

std::vector< std::string > Ptwo(char* filename);
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

std::vector< std::string > Ptwo(char* infilename)
{
	std::ifstream fin;
	std::string line;
	std::vector< std::string > OG_array; 
	OG_array.resize(1000);
	fin.open(infilename);
	short i = 0;
	while (fin) 
	{
		std::getline(fin,line);
		OG_array[i] = line;
		i++;
	}
	OG_array.resize(i);

	for (short i = 0; i < OG_array.size(); i++)
		std::cout << OG_array[i] << std::endl;
	organize(OG_array);

	fin.close();
	return OG_array;

}


void organize(std::vector< std::string >& A)
{
	bool notDone = true;
	bool swaps = true;
	short swapCount = 0;
	std::string temp = "";
	while(notDone)
	{
		if(swaps)
		{
			swaps = 0;
			for (short i = (A.size() - 1); i > 0; i-- )
			{
				if(A[i] < A[i -1])
				{
					swapCount++;
					std::cout << "Swapped: " << A[i] << " and " << A[i-1] << std::endl;
					temp = A[i-1];
					A[i-1] = A[i];
					A[i] = temp;
				}
			}
			if (swapCount == 0)
			{
				swaps = false;
			}
		}
		else
		{
			notDone = false;
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