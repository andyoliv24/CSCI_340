/***********************************************************
CSCI 340 - Assignment 1 - Fall 2019

prog1.cc

Progammer: Andy Olivares
Z-ID: z1860934
Section: 2
TA: Rahul Rao Madarapu
Date Due: September 10, 2019

Purpose: This program gets random numbers and then they are stored
into a vector to later be displayed
************************************************************/

#include "prog1.h"
using namespace std;

int main() {

	//variable declaration
	vector<int> VEC_SIZE(200);

	//seeds rand
	srand(1);

	//calls genRnDNums function
	genRnDNums(VEC_SIZE);

	//sorts vector
	sort(VEC_SIZE.begin(), VEC_SIZE.end());

	//calls printVec function
	printVec(VEC_SIZE);

	return 0;
}


/***************************************************************
genRnDNums
Use: adds 200 random numbers into the vector
Parameters: 1. v: a vector with size 200
Returns: nothing
***************************************************************/
void genRnDNums(std::vector<int>& v) {
	const int HIGH = 10000;
	const int LOW = 1;
	int RandomNum = 0;

	//overrides a current value of the vector for a random number
	for (int i = 0; i <= 200; i++) {
		RandomNum = rand() % (HIGH - LOW + 1) + LOW;
		v[i] = RandomNum;
	}
}

/***************************************************************
printVec
Use: prints the content of the vector
Parameters: 1. v: a vector with 200 values
Returns: nothing
***************************************************************/
void printVec(const std::vector<int>& v) {
	const int NO_ITEMS = 12;
	const int ITEM_W = 5;
	int counter = 0;


	//loops thru the vector and prints out values
	for (auto i = v.begin(); i != v.end(); ++i) {
		cout << setw(ITEM_W) << *i;
		counter++;
		if (counter == NO_ITEMS) {
			cout << endl;
			counter = 0;
		}
	}
}
