/***********************************************************
CSCI 340 - Assignment 8 - Fall 2019

prog8.cc

Progammer: Andy Olivares
Z-ID: z1860934
Section: 2
TA: Rahul Rao Madarapu
Date Due: November 18, 2019
Purpose: to build several heaps.
************************************************************/ 

#include "/home/cs340/progs/19f/p8/prog8.h"

/***************************************************************
get_list
Use: reads text file and stores the data into an array
Parameters: 1. vector<T>&v: vector for data storage
* 			2. const char* path: a path to a text file
Returns: nothing
***************************************************************/
template <typename T> 
void get_list(vector<T>& v, const char* path){
	//template variable
	T data;
	//stream variable
	ifstream textFile;
    
    //tries to open file
	textFile.open(path);
	if(!textFile) {
		cout << "Unable to open file";
		exit(1);
	}
    
    //clears vector
    v.clear();
    
    //inserts data into vector while there is data
    while (textFile>>data){
        v.push_back(data);
        //checks for duplicates
    }
    
	//closes file
	textFile.close();
}

/***************************************************************
construct_heap
Use: creates a heap and sorts it
Parameters: 1. vector<T>&v: vector to retrieve data from
* 			2. P pred: a predicate for sorting the heap
Returns: nothing
***************************************************************/
template <typename T, typename P> 
void construct_heap(vector<T>& v, P pred){
	//makes heap
	make_heap(v.begin(), v.end()-1);
	//sorts based on predicate
	sort(v.begin(), v.end(), pred);
}


/***************************************************************
print_list constructor
Use: initializes sz, wid, len and cnt
Parameters: 1. const unsigned& s: size of the heap
* 			2. const unsigned& w: width
* 			3. const unsigned& l: length
* 			4. const unsigned& c: counter
Returns: nothing
***************************************************************/
template<typename T>
print_list<T>::print_list( const unsigned& s, const unsigned& w, const unsigned& l, const unsigned& c ){
	//sets sz to s
	sz = s;
	//sets wid to w
	wid = w;
	//sets len to l
	len = l;
	//sets cnt to c
	cnt = c;
}

/***************************************************************
print_list overloaded
Use: prints out the heap
Parameters: 1. const T& x: a value to be printed
Returns: nothing
***************************************************************/
template < typename T>
void print_list<T>::operator()(const T& x){
	//static variable to keep track of endLineCounter
	static unsigned endLineCounter=0;
	
	//formatting output
	cout.width(wid); cout.precision(2);
	cout << fixed << showpoint;
	
	//checks if length is equal to count
	if(len==cnt){
		cout << endl;
		cnt = 0;
	}
	
	//prints data
	cout << x << " ";
	
	//increments counters
	cnt++;
	endLineCounter++;
	
	//checks if endLineCounter is equal to the vector size
	if(endLineCounter == sz){
		cout << endl;
		cout << endl;
		endLineCounter = 0;
	}
}



int main ( )
{
    vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings

    // print header message
    cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";

    // first heap

    cout << "first heap - ascending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int > print1 ( v1.size ( ), INT_SZ, INT_LN );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    cout << "first heap - descending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    // second heap

    cout << "second heap - ascending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float > print2 ( v2.size ( ), FLT_SZ, FLT_LN );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    cout << "second heap - descending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    // third heap

    cout << "third heap - ascending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string > print3 ( v3.size ( ), STR_SZ, STR_LN );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    cout << "third heap - descending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";
    return 0;
}
