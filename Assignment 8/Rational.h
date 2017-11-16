/*
*****************************************************************************************************************************************************************

CSCI 689
Assignment number 689 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 1 April,2016
Assignment Number : 8
Purpose : This c++ program implements the Rational class where we are using various operator overloading .

*****************************************************************************************************************************************************************
*/

/* Declaring the libraries which will be used for Class program .
Using fstream and sstream library we are taking the date input.
Declaring string library to store the string value. 
*/
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;

// Defining the class prototype .
class Rational
{
	// All fnctions and variable mentioned below in Private access specifier will belong to private access . 
private:
   // Declaring the variable which are having private access .
	int num;
	int den ;
	// Defining the prototype of function having private access .
    int gcd(int x,int y);
		
	// All function prototype defined below in Public access specifier will belong to public access .
public :
	/* Defining the constructor of Rational class
	   The constructor is mixed constructor of default and parameterized . i.e. it has 2 input parameter which are initialized to default value .
	   If no input is provided while calling the constructor, then it will take the default value else , it will take the value which is being passed .
	*/
    Rational(const int& n=0,const int&d=1):num(n),den(d)
	{
		
	    num=n ;
        den=d;
        
		//Checking if the rational number has denominator as 0. If yes, then it will print the error function .
		if(den==0)
            cout <<"Error : division by zero"<<endl ;
        else
        {
            int g =0 ;
            g=gcd(num,den) ;
            num=num/g ;
            den=den/g ;
        }
	};
		
	// Declaring the prototype of few Date function
	
	Rational(const Rational& r) ;				// copy constructor
		
	Rational& operator=(const Rational& r) ;	// Operator overloading for '='
	
	Rational& operator+=(const Rational& r) ;	// Operator overloading for '+='
		
	Rational& operator-=(const Rational& r) ;	// Operator overloading for '-='
		
	Rational& operator*=(const Rational& r) ;	// Operator overloading for '*='
		
	Rational& operator/=(const Rational& r) ;	// Operator overloading for '/='
	
	Rational& operator++() ;					// Operator overloading for '++' Preincrement 
		
	Rational& operator--() ;					// Operator overloading for '--' Preincrement
		
	Rational& operator++(int unused) ;			// Operator overloading for '++' Post increment
		
	Rational& operator--(int unused) ;			// Operator overloading for '--' Post increment
	
	// Defining the friend function prototype to overload the various operator like '+','-','*','/','<','>' .
		
	friend Rational operator+(const Rational& r1,const Rational& r2) ;		
		
	friend Rational operator-(const Rational& r1,const Rational& r2) ;

	friend Rational operator*(const Rational& r1,const Rational& r2) ;

	friend Rational operator/(const Rational& r1,const Rational& r2) ;

	friend bool operator==(const Rational& r1,const Rational& r2) ;

	friend bool operator!=(const Rational& r1,const Rational& r2);

	friend bool operator<(const Rational& r1,const Rational& r2) ;

	friend bool operator<=(const Rational& r1,const Rational& r2) ;

	friend bool operator>(const Rational& r1,const Rational& r2) ;
		
	friend bool operator>=(const Rational& r1,const Rational& r2) ;

	// Defining the friend function prototype to overload the operator '>>' ,'<<' .
	friend ostream& operator<<(ostream& os,const Rational& r) ;

	friend istream& operator>>(istream& is, Rational& r) ;	
};

