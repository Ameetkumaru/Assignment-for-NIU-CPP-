
/*
*****************************************************************************************************************************************************************
CSCI 689
Assignment number 4 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 18 February,2016

Purpose : This  C++ program copies the character from input stream to output stream except the characters that appear in c++ comments .

*****************************************************************************************************************************************************************
*/


#include "prog4.h"  	         // This is the user-defined library which include function prototype, standard library 

/*
The main function is responsible for invoking the defined functions .
The return type of main function is int and hence, we are returning the 0 value at the end . 				
*/

int main()
{
				// Initializing the stream variable as the open function needs to be called with the help of ifstream and outstream 
	ifstream infile;
    	ofstream outfile;
	
			// Calling the function with the input arguments(ifs,ofs) to invoke open file function and execute the process function after opening the file .
	open_files( infile, outfile );     
	process_data( infile, outfile );
	close_files( infile, outfile );

	return 0 ;  		// Returning 0 as return type of main function is int .
}

/*
The return type of open_files is void hence it won't return any value .	
open_files function will open the input.cc  and output.cc file .
If the function is not able to open , it will invoke the error function .
*/ 

void open_files(ifstream& is, ofstream& os)
{
	
   is.open(PATH);		 // Opening the file located at Path location
    if(is.fail())                // If file cannot be open ,then it will invole error function .
        error(" Unable to open prog4-in.cc file ! Try Again... ");
  
  
   os.open("prog4-out.cc");      // Opening the outfile for writing the output . 
    if(os.fail())
        error("Unable to open prog4-out.cc file ! Try Again... ");
}

/*
The return type of process_data function is void hence , it won't return any value .
	--> process_data function reads the input file character by character with the help of get function .
	--> It starts comparing the character with '/' &  '*' 
	--> If found , it will ignore the character after comments .
	--> Remaining character will be send to output.cc file . 
*/
void process_data(ifstream& is, ofstream& os)
{
	char char_compare ;			// Declaring the variable char
	is.get(char_compare);			// get() will read the file character by character through input stream
	
	do					//do loop will make sure that the below statements are executed atleast once
	{	
		
		if(char_compare == '"') 	// comparing the character 
		{
			do
			{
				os << char_compare ;
				is.get( char_compare ) ;
			
			} while( char_compare != '"' ) ;
			
						
			os << char_compare ;
			is.get(char_compare) ;
		}
		
		 if(char_compare != '/')         // checking if character matches '/' & if not matches then will send to output file
                        os << char_compare ;
		

		// This will check for comment character and will ignore if found  .
		if(char_compare == '/')
		{
		
			is.get(char_compare);
			if(char_compare == '/')
			{
				do
				{
					is.get( char_compare );
				}while(char_compare != '\n');	// Will ignore the line till end if it finds '/' as this will '//' comment
			}
		
			else if(char_compare =='*')
			{	
				while( char_compare != '/')
				{
			
					is.get(char_compare);
			
					if(char_compare != '/')
					{	
						while(char_compare != '*')
						{
							is.get(char_compare);
						}
					}
				}
			}
		}	
	} while( is.get(char_compare)) ;	 // This will run till there is input from stream file.

}

/*
The return type of close_files is void and hence , it won't return any value.
close_files function will be invoked once , all the character is been processed by process_data() function . 
close_files function will close the input and output files.				
*/

void close_files(ifstream& is, ofstream& os)
{
	is.close();
	os.close();
}

/*
The below function will print the message passed as Argument if some error is found while opening the file .
*/

void error(const string& msg)
{
	cout << msg << endl;
}
