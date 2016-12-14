#include <iostream>
#include <math.h>
#include <stdio.h>
/*
A program to find carmichael numbers.

A carmichael number is an composite number such that
it has no witness for its compositeness. A common test
for primes are to raise all numbers x < p, st x is 
relatively prime to p, to p-1 and mod the answer, if x^(p-1) % p == 1 
then it is not a witness to p's compositeness. If 
there are no witnesses then p is considered prime but 
carmichael numbers are composite numbers with no witnesses
so they are often mistaken as prime. 

These numbers are very important in cryptography and 
I'm taking cryptography this semester so I figured I'd try
to find them.

More info: http://oeis.org/A002997

*/
bool inhere(int x, int* Y, int size){
	for(short i=0;i<size;i++){
		if (x == Y[i]){
			return true;
		}
	}
	return false;
}

int powermod(int i, int j, int mod){
	int k = 1;
	for (short p=0; p<j;p++){
		k = (k * i) % mod;
	}
	return k;
}

/* I got this online */ 
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int carmichael(int test){
	int powerres=0,count = 0;
	for(short i=2;i<test;i++){
		powerres = powermod(i,test-1,test); 
		if(powerres != 1){
			if (gcd(i,test) == 1){
				count++;
			}
		}
	}
	if (count < 2){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	
	int Primes[10000];
	int hmrp = 1;
	int p;
	Primes[0] = 2;
	bool yesprime, yesmerg;

	/* manually finding primes the hard way */
	for(short i=3;i < 1000; i=i+2){
		yesprime = true;
		for(short j=0;j<hmrp;j++){
			if(i % Primes[j] == 0){
				yesprime = false;
			}
		}
		if (yesprime){
			Primes[hmrp] = i;
			hmrp++;
		}
	}

	std::cout<<"Done finding primes..." << std::endl;

	/* Finding the carmichael numbers */ 
	bool YAY;
	for (short i=3;i<562;i=i+2){
		YAY = false;
		std::cout<< "Testing: " << i;
		for (short j=2; j<i;j++){
			if ((!inhere(i,Primes,hmrp)) && (carmichael(i))){
				YAY = true;
			}
		}
		if (YAY){
			std::cout << "<- carmichael";
		}
		std::cout << std::endl;
	}
	
	return 0;
}