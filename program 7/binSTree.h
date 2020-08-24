/***********************************************************
CSCI 340 - Assignment 7 - Fall 2019

binSTree.h

Progammer: Andy Olivares
Z-ID: z1860934
Section: 2
TA: Rahul Rao Madarapu
Date Due: November 8, 2019

Purpose: implement the prototypes and classes of binSTree.h
************************************************************/
#include "binTree.h"
using namespace std;
#ifndef H_BINSTREE
#define H_BINSTREE

template <class T>
class binSTree;

template < class T >
class binSTree : public binTree < T > {
public:
	void insert(const T& x); // inserts node with value x
	bool search(const T& x) const; // searches leaf with value x
	bool remove(const T& x); // removes leaf with value x
private:
	void insert(Node < T >*&, const T&); // private version of insert
	bool search(Node < T >*, const T&) const; // private version of search
	void remove(Node < T >*&, const T&); // private version of remove
	bool leaf(Node < T >* node) const; // checks if node is leaf
};


/***************************************************************
Function: public insert
Use: calls private insert
Parameters: 1. const T& x: value to be inserted
Returns: nothing
***************************************************************/
template <class T>
void binSTree<T>::insert(const T& x) {
	//calls private insert
	insert(this->root, x);
}

/***************************************************************
Function: public search
Use: calls private search
Parameters: 1. const T& x: value to be searched
Returns: boolean
***************************************************************/
template <class T>
bool binSTree<T>::search(const T& x) const {
	//calls private search
	return search(this->root, x);
}


/***************************************************************
Function: public remove
Use: calls private remove
Parameters: 1. const T& x: a leaf value to be deleted
Returns: boolean
***************************************************************/
template<class T>
bool binSTree<T>::remove(const T& x) {
	//while search returns true
	while(search(x) == true){
		remove(this->root, x);
			return true;
			break;
	}
	return false;
}


/***************************************************************
Function: private insert
Use: inserts a value into the BST
Parameters: 1. Node<T>*& node: a node to be created
			2. const T& x: value to be inserted
Returns: nothing
***************************************************************/
template<class T>
void binSTree<T>::insert(Node<T>*& node, const T& x) {
	//checks if node is null
	if (node == NULL){
		node = new Node<T>(x);
	}
	//checks if value is less than node value
	else if (x < node->data){
		insert(node->left, x);
	}
	//checks if value is greather than node value
	else if (x > node->data){
		insert(node->right, x);
	}
}

/***************************************************************
Function: private search
Use: searches in the BST for a specific value
Parameters: 1. Node<T>*& node: a node to compare
			2. const T& x: value to be searched
Returns: boolean
***************************************************************/
template<class T>
bool binSTree<T>::search(Node<T>* node, const T& x) const {
	//checks if node is null
	if(node == NULL){
		return false;
	}
    else{
        if( x == node->data ){
			//checks if it is a leaf
			if(leaf(node )){
				return true;
			}
				return false;
		}
        else if( x < node->data ){
			//calls private search
			return search( node->left, x );
		}
		//calls private search
		return search( node->right, x );
	}
}


/***************************************************************
Function: private remove
Use: removes a value in the BST
Parameters: 1. Node<T>*& node: a node for comparison purposes
			2. const T& x: value to be deleted
Returns: boolean
***************************************************************/
template<class T>
void binSTree<T>::remove(Node<T> * &node, const T& x){	
	
	//creates a tempNode
	Node<T>* tempNode;
	//creates a "root" node
    Node<T>* root;
    //assigns node to tempNode for comparison purposes
    tempNode = node;
    
    //executes while tempnode is not null
    while( tempNode != NULL )
    {	//checks if tempnode is equal to value
		if( tempNode->data == x ){
			break;
		}
		else{
			root = tempNode;
			if( x > tempNode->data ){
				tempNode = tempNode->right;
			}
			else{
				tempNode= tempNode->left;
			}
         }
    }
	//checks if tempnode is not equal to null
	if(tempNode!= NULL){
		if( root->right == tempNode){
			root->right = NULL;
		}
		else{
			//sets left to null
			root->left = NULL;
		}
		//deletes node
		delete tempNode;
		tempNode= NULL;
	}
}


/***************************************************************
Function: leaf
Use: finds if a specific node is a leaf
Parameters: 1. Node<T>*& node: used to compare if it is a leaf
Returns: boolean
***************************************************************/
template <class T>
bool binSTree<T>::leaf(Node <T>* node) const{
	// checks if node is null
	if(node == NULL){
		return false;
	}
	//checks if both right and left children have no children
	else if(node->left == NULL && node->right == NULL){
		return true;
	}
	else{
		return false;	
	}
}

#endif
