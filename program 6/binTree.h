/***********************************************************
CSCI 340 - Assignment 6 - Fall 2019

binTree.h

Progammer: Andy Olivares
Z-ID: z1860934
Section: 2
TA: Rahul Rao Madarapu
Date Due: October 31, 2019

Purpose: implement the prototypes and classes of binTree.h
************************************************************/ 

#ifndef H_BINTREE
#define H_BINTREE

#include "/home/cs340/progs/19f/p6/Node.h"
#include <cstddef>
#include <stdlib.h>

template <class T>
class binTree;

template <class T> 
class binTree {
	public:
	binTree(); // default constructor
	unsigned height () const; // returns height of tree
	virtual void insert ( const T& ); // inserts node in tree
	void inorder ( void ( * ) ( const T& ) ); // inorder traversal of tree

	protected:
	Node < T >* root; // root of tree
	private:
	unsigned height(Node<T>*) const; // private version of height ( )
	void insert (Node<T>*&, const T&); // private version of insert ( )
	void inorder(Node<T>*, void(*)(const T&)); // private version of inorder ( )
};


//this is used to select a random side either left or right to insert
//a node
	typedef enum { left_side, right_side } SIDE;
	SIDE rnd (){ 
	return rand ( ) % 2 ? right_side : left_side; 
}



/***************************************************************
Function: constructor for binary tree
Use: sets root to 0
Parameters: none
Returns: nothing
***************************************************************/
template <class T>
binTree<T>::binTree(){
	//set root to NULL
	root = NULL;
}


/***************************************************************
Function: public Height
Use: calls height()
Parameters: none
Returns: height
***************************************************************/
template <class T>
unsigned binTree<T>::height() const{
	
	return height(root);
}


/***************************************************************
Function: public inorder
Use: calls inorder()
Parameters: 1. const T&: root 
* 			2. *print: print function
Returns: nothing
***************************************************************/
template <class T>
void binTree<T>::inorder(void (*print)(const T&)){
	inorder(root, print);
}


/***************************************************************
Function: public insert()
Use: calls insert()
Parameters: 1. const T& node:  a node to be inserted
Returns: nothing
***************************************************************/
template <class T>
void binTree<T>::insert(const T& node){
	insert(root, node);
}





/***************************************************************
Function: private height
Use: gets the height  of the binary tree
Parameters: 1. node <T>* node: a node
Returns: height of binary tree (unsigned)
***************************************************************/
template <class T>
unsigned binTree<T>::height(Node <T>* node) const{
	if(!node){
		return 0;
	}
	return 1 + max(height(node->left), height(node->right));
}


/***************************************************************
Function: private insert 
Use: inserts randomly a node
Parameters: 1. Node <T>*& node: a node to be searched
* 			2. const T& value: a value to be inserted
Returns: nothing
***************************************************************/
template <class T>
void binTree<T>::insert(Node <T>*& node, const T& value){

	if(node == NULL){
		node = new Node<T>();
        node->right = NULL;
        node->left = NULL;
        node->data = value;
	}else if(rnd() == left_side){
		insert(node->left, value);	
	}else
		insert(node->right, value);
}


/***************************************************************
Function: private inorder
Use: prints in inorder the binary tree
Parameters: 1. Node<T>* node: a root to start searching and printing
* 			2. *print:  a print function to print the nodes
Returns: nothing
***************************************************************/
template <class T>
void binTree<T>::inorder( Node<T>* node, void (*print) (const T& ) ) {
    if(node != NULL) {
		inorder(node->left, print);
		print( node->data );
        inorder(node->right, print);
	}
}

#endif
