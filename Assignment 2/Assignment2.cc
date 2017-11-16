/*
****************************************************************************************************************************************
CSCI 689
Assignment number 2 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 2 February,2016

Purpose : This  C++ program checks the Perfect number in the range of 1-9999 and then displays the divisors of that Perfect /number .

*****************************************************************************************************************************************
*/


# include "Assignment2.h"   // library has been defined with string,iostream system library .Header file contains function prototype .

int main()
{
	//This for loop will iterate over the range 1-9999.
	for (unsigned int i = 1; i <= number; i++ )  //unsigned int is defined as number range is unsigned .i.e. 1-9999
	{
		if(isPerfect(i) == true) // If isPerfect function returns true, then it will pass the i value to divisors function to find divisors.
		{
			divisors(i) ;	//This function will find the divisors for the Perfet number.
		}
		else
			continue ;
	}		
	return 0 ;   // Returning 0 as 'int' is the datatype of main function .
}

bool isPerfect (int num)     //isPerfect function will check whether the number is Perfect number or not.
{
	//Initializing the variable and declaring the int and bool variable .
	int sum = 0;
	bool status;
	
	// This for loop will check whether the number is Perfect number or not. If number is equal to addition of divisors,then it is Perfect number.
	for(int i = 1 ; i < num ; i++ )
	{
		if ( num % i == 0 )
                {	
                       	sum = sum + i ;			     
		}	
                else
                       	continue ;
		
	        if ( sum == num)    //if sum is equal to number, the function will return true saying that number is Perfect number else it will return false
		{
			status = true ;
		}
		else
			status = false ;
	}
	return status ;   // Returning the status as boolean true or false as datatype of function is bool.
}

void divisors(int perfectNumber) //divisors function will find the divisor for a Perfect number.This function won't return any value as datatype is void .
{
	// Initializing the variable and declaring the int and string variable .
        int sum = 0;
        string divisor = ""; // This variable will store the divisor value 
	
	//This for loop will find the divisors of the perfect number and display it .
        for(int i = 1 ; i < perfectNumber ; i++ )
        {
                if (perfectNumber % i == 0 )  // '%' character is used to check for a remainder after division .
                {
                        sum = sum + i ;
          		divisor = ( divisor + to_string(i)).append("+") ; //'to_string' will convert the int into string and 'append' will add the character
               }
                else
                        continue;
      
        }     
	divisor = divisor.substr(0,divisor.length()-1) ; // 'substr' function will discard the additional character which is given by apppending.
    
	cout << perfectNumber << " = " << divisor <<endl ;     //Displaying the output .
	cout << endl ; 
}
