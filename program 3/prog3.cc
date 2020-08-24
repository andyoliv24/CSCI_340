/***********************************************************
CSCI 340 - Assignment 3 - Fall 2019

prog3.cc

Progammer: Andy Olivares
Z-ID: z1860934
Section: 2
TA: Rahul Rao Madarapu
Date Due: September 30, 2019

Purpose: fill a set with only prime numbers then display them.
************************************************************/ 

#include "prog3.h"
using namespace std;

int main(){
//empty set
set <int> primeNums;
//numbers
int numbers=0;
//gets user input
cin >> numbers;


cout << "upper limit for the set of primes: 1000" << endl;
//calls sieve
sieve(primeNums,numbers);
//calls print_primes
print_primes(primeNums);

return 0;
}





/***************************************************************
sieve
Use: erases non prime numbers
Parameters: 1. s: A set type int
*           2. n: An int
Returns: nothing
***************************************************************/
void sieve(set <int> &s, int n ){
	
	//fills set with data
	for(int i=2; i<=n; i++){
		s.insert(i);
	}
	
	//first loop gets the first number
	for (auto it = s.begin(); it != s.end(); ++it){
		//second loop test current number with all number in the set
		for (auto it2 = it; it2!= s.end(); ++it2){
			//checks whether is prime or not
			if((*it2%*it==0) && (*it2 != *it)){
				//set pointer to value that was erased, otherwise we
				//get segmentation fault
				it2 = s.erase(it2);
			}
		}
	}
}



/***************************************************************
print_primes
Use: prints prime numbers from a set 
Parameters: 1. s: A set type int
Returns: nothing
***************************************************************/
void print_primes (const set <int> &s ){
	const int NO_ITEMS = 16;
	const int ITEM_W = 4;
	int counter = 0;
	
	//loops thru the set
	for(auto it=s.begin(); it!=s.end(); ++it){
		//sets width
		cout << setw(ITEM_W) << *it;
		counter++;
			//checks if row has 16 primes
			if(counter == NO_ITEMS){
				cout << endl;
				counter =0;
			}
	}
	cout << endl;
}

