/*
******************************************************************************************************************************************************************
CSCI 689
Assignment number 3 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 10 February,2016

Purpose : This  C++ program for encryption 'Caesar cipher' replaces each letter in a text by a letter that appears a fixed distance(shift) in the alphabet.

*****************************************************************************************************************************************************************
*/

#include "Assignment3.h"   // library has been defined with string, fstream ,iostream system library .Header file contains function prototype .

int main()
{
        int shift;
        while(cin>>shift)     // Will run till shift value is entered by user.
        {
                process_infile(shift) ;    // Passing argument 'shift' to process_infile() function 
        }
        return 0;       // Returning 0 as 'int' is the datatype of main function .
}

// The below function will read the input file to encrypt the text .
void process_infile(int shift)
{
        string str ;
        ifstream infile;
        ofstream outfile;
        infile.open(PATH);       // open() function will read the file stored at PATH location.
       
        if(infile.fail())    // Checking if file is able to open or not. If not , it will throw an error message .
                 error(" Unable to open Prog3.d2 file ! Try Again... ") ;
	cout<<"Shift = " << shift << endl ;
        while(!infile.fail())   // Run till all the Text is read by function .
        {
                getline(infile,str);      //getline() will read full line instead of single word 
                cout <<  encodeCaesarCipher(str,shift) <<endl;              // Printing the value returned by encodeCaesarCipher functiom .
        }
        infile.close();
}

// The below function will encode the string and return the string after replacing each letter with letter that appears at fixed distance .
string encodeCaesarCipher (string str ,int shift)
{
    string output_str = "";
        for(unsigned int i = 0; i < str.length(); i++)
        {
            int new_posi=new_position(str[i],shift) ;   // Calling the new_position which will return the new position of letter.
            output_str += new_posi;
        }

    return output_str ;                    // Returning the string after replacing the letter with new one.
}

// The below function will find the new position of a letter that needs to be replaced by a shift value .
int new_position (char c,int shift)
{
    int posi=0 ;
    int new_shift=shift ;
    new_shift=shift%26;

    if( isalpha(c) && new_shift>0)             // isalpha() function will check whether the character passed to function is character & shift is positive  
    {
        posi = c+new_shift;
        if(isupper(c))				//isupper() will check is character is upper character or not.
        {
            if(posi <=90)
            {
                return posi ;
            }
            else
            {
               int add=posi-90 ;
               int ret=add+64 ;
                return ret ;
            }
        }
        else if(islower(c))			//islower() will check is character is lower character or not.
        {
            if(posi <=122)
            {
                return posi ;
            }
            else
            {
                int add=posi-122 ;
                int ret=add+96 ;
                return ret ;
             }
        }
   }
   else if( isalpha(c) && new_shift < 0)		// isalpha() function will check whether the character passed to function is character & shift is negative
   {
        posi = c+new_shift;
        if(isupper(c))				//isupper() will check is character is upper character or not.
        {
           if(posi >=65 )
           {
               return posi ;
           }
           else
           {
              int add=posi+26 ;
              return add ;
           }
        }
        else if(islower(c))			//isupper() will check is character is lower  character or not.

        {
            if(posi >=97)
            {
                 return posi ;
            }
            else
            {
                int add=posi+26 ;
                return add ;
            }
        }
    }
    else
    {
        return c ;
    }
	return 0 ;
}

// The below function will print the message passed as Argument if some error is found while opening the file 
void error (string msg)
{
        cout << msg <<endl ;
}
