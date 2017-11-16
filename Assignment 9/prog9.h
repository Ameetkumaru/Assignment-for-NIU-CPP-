/*
*****************************************************************************************************************************************************************

CSCI 689
Assignment number 689 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 12 April,2016
Assignment Number : 9
Purpose : This c++ program implements the Simple Calculator .

*****************************************************************************************************************************************************************
*/

/* Declaring the libraries which will be used for Simple Calculator .
Using fstream and sstream library we are taking the date input.
Declaring string library to store the string value. 
*/

#include<iostream>
#include<stack> 
#include<cmath>
#include <iomanip>
#include<fstream>
#include<sstream>
using namespace std ;

// Below are the functions definition in header file.
void process_token(const string& token, stack < double >& S ) ;

bool unarySign ( const char& c, const string& token, const unsigned& i ) ;

bool floatPoint( const char& c, const string& token, const unsigned& i ) ;

double getNumber( const char& c,const string&token, unsigned& i, const bool& floatPointFlag) ;

double stringToDouble(string str) ;

bool isValidOperator(const char& c) ;

double operation(const char& c, const double& x, const double& y) ;

double popStack ( stack < double >& S ) ;

void printResult(const stack<double>& S) ;

void emptyStack(stack<double>& S) ;


