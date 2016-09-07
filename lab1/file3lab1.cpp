#include "file2lab1.cpp"
#include "file1lab1.cpp"
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>




int main()
{
	std::ofstream fout2;
	char FileNames[3][14];
	char file1[14] = "strings_0.txt";
	char file2[14] = "strings_1.txt";
	char file3[14] = "strings_2.txt";
	for (short i = 0; i < 15; i++)
	{
		FileNames[0][i] = file1[i];
		FileNames[1][i] = file2[i];
		FileNames[2][i] = file3[i];

	}
	std::vector< std::vector< std::string > > A;
	A.resize(3);
	


	for (short i = 0; i < 3; i++)
	{
		Pone(FileNames[i]);
		A[i] = Ptwo(FileNames[i]);
	}
/*
	fout2.open("lab1outputsorted.txt");
	for (short i = 0; i < A.size(); i++)
	{
		for (short j = 0; i < A[i].size(); j++)
		{
			fout2 << A[i][j] << "p" << "\n";
		}
	}
*/


	return 0;
}