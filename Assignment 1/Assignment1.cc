/*
****************************************************************************************************************************************
CSCI 689
Assignment number 1 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 25 January,2016

Purpose : This  C++ program takes input from user and calculates the sum of first 'N' Odd integer
  
*****************************************************************************************************************************************
*/

#include "Assignment1.h"

int main()
{
	// Initializing the variable and assigning them value
	long sum = 0 ;	
	int number,oddNumber = 1  ;					

	// Asking for input from user to calculate the sum of odd integer
	cout << "N = ";
	cin >> number ;

	// Checking if number entered by user is Positive integer or Non-positive integer
	if (number >0)
	{
		// Here we begin with calculating the sums of first N odd number as number entered is Positive intger
		if (number == 1) // If number entered is 1 , then it will go in this block  
       		{
			sum = sum + oddNumber ; // Calculating the sum                	
       		}
		else {
			// Number entered is positive integer greater than 1 .Hence, we will use for loop to calculate the sum
			for(int i=1 ;i <= number ; i++)
			{
				sum = sum + oddNumber ;// Calculating the sum
				oddNumber = oddNumber + 2 ; // TO calculate the next odd integer ,we need to increment it by 2 as oddNumber is initialize to 1
			}							
		}
		cout << "sum = " << sum << endl ; // Displaying the sum after calculating the sum
	}
	else // If number entered is non-positive integer, then it will enter the below block  
	{
		cout << "The number entered is a Non-positive integer" << endl ;
	}
	
	// Returning the value as main function has been defined with 'int' datatype
	return 0 ;
}

