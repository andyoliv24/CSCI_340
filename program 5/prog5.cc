/***********************************************************
CSCI 340 - Assignment 5 - Fall 2019

prog5.cc

Progammer: Andy Olivares
Z-ID: z1860934
Section: 2
TA: Rahul Rao Madarapu
Date Due: October 21, 2019
************************************************************/ 

#include "/home/cs340/progs/19f/p5/prog5.h"

int main() {

	//j will be the index for list
	int j=0;
	int counter=0;

	//initializes new args struct
	args in;
	
	//new list
	list<string> people;
	
	//input
	cin >> in.N;
	cin >> in.M;
	cin >> in.K;
	
	
	cout << "Number of people? " << in.N << endl;
	cout << "Index for elimination? " << in.M << endl;
	cout << "Index for printing? " << in.K << endl;
	
	cout << endl;
	cout << endl;


	cout << "Initial group of people" << endl;
	cout << "------------------------" << endl;
	//initializes values
	init_vals(people, in);
	//prints list of people
	print_list(people, 0);
	cout << endl;
	
	//creates new iterator that points to the begining
	std::list<string>::iterator it = people.begin();
	
	while (people.size() > 1) {
		//gets the mth person in the list
		j = (j + (in.M - 1)) % people.size();
		//converts index to iterator
		advance(it, j);
		//erases person in the list
		people.erase(it);

		//sets iterator the new begin
		it = people.begin();
		
		counter++;
		if(counter % in.K ==0 ){	
			print_list( people , counter );
		}
		//checks for last person
		if(people.size() == 1){
			print_list(people, counter);
		}
	}

}
 


/***************************************************************
Function: init_vals
Use: gets words from input file
Parameters: 1. L: an empty list to be filled with people
* 			2. in: a struck to get data for people 
Returns: nothing
***************************************************************/
void init_vals(list < string >& L, args& in) {
	
	//resizes the list
	L.resize(in.N);
	
	//generates people into the list
	generate(L.begin(), L.end(), SEQ(in.N));
}

/***************************************************************
Function: print_list 
Use: gets words from input file
Parameters: 1. L: an empty list to be filled with people
* 			2. in: a struck to get data for people 
Returns: nothing
***************************************************************/
void print_list(const list < string >& L, const unsigned& cnt) {
	int count = 0;//
	
	//checks how many people got deleted so far
	if ( cnt != 0 ){
		if( cnt == 7 ){
			cout << "After eliminating " << cnt << "th person" << endl;
			cout << "----------------------------" << endl;
		}
		else{
			cout << "After eliminating " << cnt << "th person" << endl;
			cout << "-----------------------------" << endl;
		}
	}
	
	//prints people
	for ( auto it = L.begin() ; it != L.end() ; ++it ){	
		cout << *it << " ";
		count++;
		//checks for 12 items
		if( count == NO_ITEMS ){
			cout << endl;
			count = 0;
		}
	}
	//double spacing
	cout << endl;
	cout << endl;
}
