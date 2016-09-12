#include "lab1_maker.cpp"
#include "lab1_sorter.cpp"
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>




int main()
{
	std::ofstream fout2;
	char filenames[3][14];
	char file1[14] = "strings_0.txt";
	char file2[14] = "strings_1.txt";
	char file3[14] = "strings_2.txt";
	for (short i = 0; i < 15; i++)
	{
		filenames[0][i] = file1[i];
		filenames[1][i] = file2[i];
        filenames[2][i] = file3[i];

	}
	std::vector< std::vector< std::string > > A;
	A.resize(3);
	


	for (short i = 0; i < 3; i++)
	{
		ProgramOne(filenames[i]);
		A[i] = ProgramTwo(filenames[i]);
	}
    
	return 0;
}