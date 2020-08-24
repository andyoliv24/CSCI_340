/***********************************************************
CSCI 340 - Assignment 2 - Fall 2019

sub2.cc

Progammer: Andy Olivares
Z-ID: z1860934
Section: 2
TA: Rahul Rao Madarapu
Date Due: September 19, 2019

Purpose: sort vectors, print out the percent of successful comparisons
* between two vectors
************************************************************/ 

#include "prog2.h"
using namespace std; 



/***************************************************************
Vectors
Use: initializes 2 Vectors with random numbers 
Parameters: 1. v1: A Vector type int
*           2. v2: A vector type int
*           3. s1: an int with a number to be the size of the vector
*           4. s2: an int with a number to be the size of the vector
Returns: nothing
***************************************************************/ 
void Vectors (vector <int>& v1, vector <int>& v2, int s1, int s2){

	const int HIGH = 1000;
	const int LOW = 1;
	int RandomNum = 0; 
	
	srand(s1);
	
	//overrides a current value of the vector for a random number
	for(auto it =v1.begin(); it!=v1.end(); ++it){
		RandomNum = rand ( ) % ( HIGH - LOW + 1 ) + LOW;
		*it = RandomNum;
	}
	
	srand(s2);
	RandomNum = 0;
	
	//overrides a current value of the vector for a random number
	for(auto it =v2.begin(); it!=v2.end(); ++it){
		RandomNum = rand ( ) % ( HIGH - LOW + 1 ) + LOW;
		*it = RandomNum;
	}
	
}



/***************************************************************
linearSearch
Use: search for a value, if found the algorithm stops
Parameters: 1. v: a vector with random numbers
*           2. x: the value to be searched
Returns: false or true
***************************************************************/ 
bool linearSearch (const vector <int>& v, int x){
	auto it = find (v.begin(), v.end(), x);
	
	 if (it != v.end())
		return true;
	return false;
}


/***************************************************************
binarySearch
Use: search for a value, if found the algorithm returns true if not
* returns false
Parameters: 1. v: a vector with random numbers
*           2. x: the value to be searched
Returns: false or true
***************************************************************/ 
bool binarySearch (const vector <int>& v, int x){
	return (binary_search(v.begin(), v.end(), x));
}


/***************************************************************
search
Use: compares v2 contents with v1 contents and then accumulates number
* of successful comparisons
Parameters: 1. v: a vector with size 200
Returns: number of successful comparisons
***************************************************************/ 
int search (const vector <int>& v1, const vector <int>& v2, bool(*p) (const vector <int >&, int)){
	int count =0;
	
	for(auto i=v2.begin(); i!=v2.end(); ++i){
		if(p(v1,*i)){
			count ++;
		}
	}
	
	return count;
}


/***************************************************************
sortVector
Use: sorts the vector in anscending order
Parameters: 1. v: a vector to be sorted
Returns: nothing
***************************************************************/ 
void sortVector (vector <int>& v){
	sort(v.begin(), v.end()); 
}



/***************************************************************
printVector
Use: prints the content of a vector
Parameters: 1. v: a vector with random values
Returns: nothing
***************************************************************/ 
void printVector (const vector <int>& v){
	const int NO_ITEMS = 16;
	const int ITEM_W = 4;
	int counter=0; 
	
	
	//loops thru the vector and prints out values
	for(auto i=v.begin(); i!=v.end(); ++i){
		cout << setw(ITEM_W) << *i;
		counter++;
		if(counter == NO_ITEMS){
			cout << endl;
			counter =0;
		}
	}
}


/***************************************************************
printStat
Use: prints the percent of successful searches
Parameters: 1. totalSucCnt: total number of successful comparisons
*           2. vectorSz: size of the test vector
Returns: nothing
***************************************************************/ 
void printStat (int totalSucCnt, int vectorSz){
	cout << setw(41)
	<< "Percent of Successful Searches = " 
	<< fixed << setprecision(2) 
	<< ((float) totalSucCnt/ (float)vectorSz)*100 << '%' << endl;
}

