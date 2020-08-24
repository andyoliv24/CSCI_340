/***********************************************************
CSCI 340 - Assignment 1 - Fall 2019

prog1.h

Progammer: Andy Olivares
Z-ID: z1860934
Section: 2
TA: Rahul Rao Madarapu
Date Due: September 10, 2019

Purpose: This program gets random numbers and then they are stored
into a vector to later be displayed
************************************************************/

#ifndef H_PROG1
#define H_PROG1 
#include <vector> 
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>

void genRnDNums(std::vector<int>& v);         //prototype for the genRnDNums
void printVec(const std::vector<int>& v);     //prototype for the printVec

#endif

