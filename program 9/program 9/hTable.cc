/***********************************************************
CSCI 340 - Assignment 9 - Fall 2019

hTable.cc

Progammer: Andy Olivares
Z-ID: z1860934
Section: 2
TA: Rahul Rao Madarapu
Date Due: December 2, 2019
Purpose: build a hash table
************************************************************/  
 
 #include "/home/cs340/progs/19f/p9/hTable.h"



/***************************************************************
ptr_sort 
Use: sorts pTable
Parameters: 1. vector<Entry*>: vector to be sorted
Returns: nothing
***************************************************************/
 void ptr_sort(vector <Entry*>); 
    bool cmp(Entry*, Entry*);


/***************************************************************
HT::HT
Use: hash table constructor
Parameters: 1. const unsigned& hs: size of hash table
Returns: nothing
***************************************************************/
HT::HT(const unsigned& hs){
    //hsize is now hs value
    hsize = hs;
    //resizes hTable to hs
    hTable.resize(hs);
}


/***************************************************************
HT::~HT
Use: calls destructor
Returns: nothing
***************************************************************/
HT::~HT(){
        //calls clear on both hTable and pTable
		hTable.clear();
		pTable.clear();	
}


/***************************************************************
insert function
Use: inserts an item
Parameters: 1.  const Entry& e: value key to be inserted
Returns: nothing
***************************************************************/

    void HT::insert (const Entry& e){
        //hashes key entry
        int index = hash(e.key);
        //creates a new list
        list<Entry>&l = hTable[index];

        //use of find_if algorithm to find if a value is already in the hash table
	    auto item =std::find_if(l.cbegin(), l.cend(), [e](const Entry& val){return e.key == val.key;});
        //checks if item is equal to cend
    	if(item!=l.cend()){
            cout << "not inserted - duplicate key!!!"<<endl;
		}else{
            cout << " entry = " << index << endl;
            //pushes into the list the element provided
            l.push_front(e);
            //pushes address to thte front of the list
            pTable.push_back(&l.front());

	    }
	
    }
     
/***************************************************************
search function
Use: searches for an item
Parameters: 1. const string& key: key to be searched
Returns: nothing
***************************************************************/
    void HT::search (const string& key){
        //hashes key entry
        int index = hash(key);
        //creates a new list
        list<Entry> l = hTable[index];
        //use of find_if algorithm to find if a value is already in the hash table
	    auto searchItem = std::find_if(l.cbegin(), l.cend(), [key](Entry val){return key == val.key;});
        //compares if searchItem is equal to l.cend()
        if(searchItem != l.cend()){
            cout << " ==> number: " << setw(4) << (*searchItem).num << " - item: " << (*searchItem).desc;
        }else{
            cout << " not in table!!";
        }
        cout << endl;
    }
     
/***************************************************************
hTable_print function
Use: prints item key, description and number
Returns: nothing
***************************************************************/   
    void HT::hTable_print(){
     
        bool flag = false;
        for(unsigned i =0; i<hTable.size(); i++){
            
            for(auto item : hTable[i]){
                if(flag){
                    cout << endl;
                } 
                    cout << setw(4) << i << ": " <<item.key << " - " << setw(5) <<item.num << " - " << item.desc << endl;
                    flag = false;
            }
            flag = true;
        }
        cout << endl;
    }
     
     
/***************************************************************
pTable_print
Use: reads text file and stores the data into an array
Parameters: 1. vector<T>&v: vector for data storage
* 			2. const char* path: a path to a text file
Returns: nothing
***************************************************************/  
    void HT::pTable_print(){
     
        sort(pTable.begin(), pTable.end(), cmp);
        for(unsigned i =0; i<pTable.size(); i++){
            cout << "  " << pTable[i]->key << " - " << right << setw(4) << pTable[i]->num << " - " << left  << pTable[i]->desc << endl;
        }
        cout << endl;
    }


     
     
/***************************************************************
prt_sort
Use: sorts the pTable
Parameters: 1. vector<Entry*>: vector to be sorted
Returns: nothing
***************************************************************/
    void ptr_sort(vector <Entry*> pTable){
        //sorts elements in pTable
         sort(pTable.begin(), pTable.end(), cmp);
    }
    


/***************************************************************
cmp function
Use: compares keys
Parameters: 1. Entry* p: key to be compared
* 			2. Entry* q: key to be compared
Returns: true or false
***************************************************************/ 
    bool cmp (Entry* p, Entry* q){
        //compares which one is bigger
        return (p->key < q->key);
    }