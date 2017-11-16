/*
*****************************************************************************************************************************************************************

CSCI 689
Assignment number 689 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 24 March,2016
Assignment Number : 7 
Purpose : This c++ program implements the Date class which will validate whether the date entered is valid or not .

*****************************************************************************************************************************************************************
*/

/* Declaring the libraries which will be used for Class program .
Using fstream and sstream library we are taking the date input.
Declaring string library to store the string value. 
*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;
// Initializing vector variable which will store the 12 month .This variable will be used to check the validMonth function .
const vector<string> months {"January","February","March","April","May","June","July","August","September","October","November","December"} ;
// Defining the intToString function prototype.
string intToString(int& a);


// Defining the class prototype .
class Date
{
  // All fnctions and variable mentioned below in Private access specifier will belong to private access . 
   private: 
	// Declaring the variable which are having private access .

	string month ;
	int day ;
    int year ;		
   	// Defining the prototype of function having private access .
	bool isValidMonth() const;

        bool isLeapYear() const ;

        int daysInMonth(const string& m) const ;
		
		int monthIndex() ;
   
  // All function prototype defined below in Public access specifier will belong to public access .
  public : 
	/* Defining the constructor of Date class
	   The constructor is mixed constructor of default and parameterized . i.e. it has 3 input parameter which are initialized to default value .
	   If no input is provided while calling the constructor, then it will take the default value else , it will take the value which is being passed .
	*/
	Date(const string& m="January",const int& d=1, const int& y=2000)
	{
		month=m ;
		day=d ;
		year=y;
		Month() ;
	}
	// Declaring the prototype of few Date function .
	Date(const Date& d) ;		// copy constructor
	
	Date& operator= (const Date& d );		// operator overloading
	
	Date& addDay(const int& n) ;			// function responsible to add day
	
	Date& addMonth(const int& n) ;			// function responsible to add month
	
	Date& addYear(const int& n) ;			// function responsible to add year
	
	int dayIndex() const ;					// function responsible to find the day index
		
	// Defining the setter function prototype
	void setMonth(const string& m);

	void setDay(const int& d) ;

	void setYear(const int& y) ;
	//Defining the getter function prototype
	string getMonth() const ;

	int getDay() const ;

	int getYear() const ;
	
	// Defining the prototype of Month function which will be used to convert the first character to upper and rest to lower .
	void Month() ;

	// Defining the prototype of isValidDate fucntion which will be used to perform validation .
	bool isValidDate() const ;

	// Defining the prototype of  toString function which will be used to convert the date into string  .
	string toString() const ;
	
		
	// Defining the friend function prototype to overload the operator .
	friend ostream& operator<<(ostream& os,const Date& d) ;

	friend istream& operator>>(istream& is, Date& d) ;
	
	
};
/*
Below is the definition of non-member function dateDiff which will be used to find the difference .
*/
unsigned dateDiff(const Date&,const Date&);

