
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>


void Pone(char* outfilename);
std::string makeString();


std::string makeString(){
	std::string word;             // returned word
	short wordlen = (rand() % 15) + 1;  // random word length  
	char x;                       // placeholder character
	for(short i = 0; i < wordlen; i++){
		x = (97 + (rand() % 26)); // 97 is where ascii characters for the english alphabet start
		word += x;
	}
	return word;
}

void Pone(char* outfilename){

	/* PYTHON 

	upperbound = int(input("enter an upper bound for file lines: "));
	file_length = random.randrange(upperbound);

	outputfile = open("lab1output" + str(timesRun) + ".txt","w");

	for i in range(file_length):
		wordlen = random.randrange(10) +1;
		word = '';
		for i in range(wordlen):
			word = word + abcs[random.randrange(26)];
		print(word,file = outputfile);
	*/ // END PYTHON
	/* BEGIN C++ */
	int upperbound =  10; // upperbound on # of lines in file
	std::ofstream fout;
	fout.open(outfilename);

	for (short i = 0; i < upperbound; i++)
	{
		std::string addToFile = makeString();
		fout << addToFile << "\n";
	}
	fout.close();

}