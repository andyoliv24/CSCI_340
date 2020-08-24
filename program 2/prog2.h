/***********************************************************
CSCI 340 - Assignment 2 - Fall 2019

prog2.h

Progammer: Andy Olivares
Z-ID: z1860934
Section: 2
TA: Rahul Rao Madarapu
Date Due: September 19, 2019

Purpose: implement the prototypes of sub2.cc 
************************************************************/ 

#ifndef H_PROG2
#define H_PROG2 

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip> 
using namespace std;

//vector size
const int ARR_SIZE = 200;

//test array size
const int TEST_ARR_SIZE = 100;

//value for seed1
const int SEED1 =1;

//value for seed2
const int SEED2 =3;

//Vector Prototype
void Vectors (vector <int>& v1, vector <int>& v2, int s1, int s2);

//linearSearch Prototype
bool linearSearch (const vector <int>& v, int x);

//binarySearch Prototype
bool binarySearch (const vector <int>& v, int x);

//Search Prototype
int search (const vector <int>& v1, const vector <int>& v2, bool(*p) (const vector <int >&, int));

//sortVector Prototype
void sortVector (vector <int>& v);

//printVector Prototype
void printVector (const vector <int>& v);

//printStat Prototype
void printStat (int totalSucCnt, int vectorSz);

#endif
