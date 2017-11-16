
/*
*****************************************************************************************************************************************************************

CSCI 689
Assignment number 689 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 2 May,2016
Assignment Number : 11
Purpose : N Queens Puzzle.

*****************************************************************************************************************************************************************/

#ifndef CONSTANT_VALUE
#define CONSTANT_VALUE
// Declaring the different libraries .
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std ;
extern const int SEED=int(time(0));
// Declaring the functions prototype .
void initBoard(vector<vector<bool> >& );
void solveNQueens(const unsigned& );
bool solveNqueensUtil(vector<vector<bool> >& , const unsigned& );
bool isSafe(const vector<vector<bool> >& , const int& , const int& );
void printBoard(const vector<vector<bool> >&);
// End of header file
#endif

