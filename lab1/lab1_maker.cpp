
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>


void ProgramOne(char* outfilename);
std::string makestring();


std::string makestring(){
	std::string word;             // returned word
	short wordlen = (rand() % 15) + 1;  // random word length  
	char x;                       // placeholder character
	for(short i = 0; i < wordlen; i++){
		x = (97 + (rand() % 26)); // 97 is where ascii characters for the english alphabet start
		word += x;
	}
	return word;
}

void ProgramOne(char* outfilename){

	int upperbound =  10; // upperbound on # of lines in file
	std::ofstream fout;
	fout.open(outfilename);

	for (short i = 0; i < upperbound; i++)
	{
		std::string addToFile = makestring();
		fout << addToFile << "\n";
	}
	fout.close();

}