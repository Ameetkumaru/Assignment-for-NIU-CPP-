/*
*****************************************************************************************************************************************************************
CSCI 689
Assignment number 5 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 26 February,2016

Purpose : This  C++ program is designed for "Game of MineSweeper" .

*****************************************************************************************************************************************************************
*/


#include "prog5.h"	// This is the user-defined library which include function prototype, standard library

/*
The main function is responsible for invoking the defined functions .
The return type of main function is int and hence, we are returning the 0 value at the end .
*/

int main()
{
    // Initializing the variable m and mineProb which will be input to the program
    int m;
    double mineProb ;
    // Run the block of statement till user provide input .
    while((cin>>m)&&(cin>>mineProb))
    {
     	// Declaring the vector mines & counts of TWO dimensional . 
	vector <vector<bool> > mines(m,vector<bool> (m)) ;
        vector <vector<unsigned> > counts(m,vector<unsigned> (m)) ;

        buildMineField(mines,mineProb) ; 	 // Invoking the function to build the mine field .
        fixCounts( mines,counts) ;  		 // Invoking the function to calculate the count of mines in MineSweeper game .
        cout<<"Mine Locations : size = "<<m<<" x "<<m<<", prob of mine = "<<mineProb<<endl;
        displayMineLocations (mines) ;   	//  Invoking the display function to print the mine locations 
        cout<<"Mine Counts : "<<endl;
        displayMineCounts ( counts ) ;      	 // Invoking the display function to print the count of mines .
    }
    return 0 ;              			 // Returning 0 as return type of main function is int 
}

/*
This function is responsible for generating Random number and then assigning to two dimensional vector 'mines' .
'mines' is the vector where mines are setup . 
buildMineFiled()  uses RAND() function which is responsible for generating the random number. 
With the help of mine probability , we are assigning the two dimension vector with mine .
*/

void buildMineField(vector <vector<bool> >& mines,const double& mineProb)
{
    int seed =1 ;
    srand(seed) ;    // Calling seed function with argument as '1'

    // Checking the mine size 
    if(mines.size() >1)
    {   // Using 2 for loop to navigate through two dimension vector
            for (unsigned int i=0 ; i< mines.size();i++)
            {
                for (unsigned int j=0;j<mines.size();j++)
                {
                    double rnd=rand()/(double(RAND_MAX)+1) ;          // This statement finds the random number
                    if (rnd < mineProb)
                    {
                            mines[i][j]=true ;
                    }else
                        mines[i][j]=false ;
                }
            }
    }else
    {
        for (unsigned int i=0 ; i< mines.size();i++)
            {
                for (unsigned int j=0;j<mines.size();j++)
                {
                    if (mineProb==1)
                    {
                            mines[i][j]=true ;
                    }else
                        mines[i][j]=false ;
                }
            }
    }
}

/*
This function is responsible for counting the number of mines near the mines.
This function uses two dimension vector which will store the number of mines or count of mines near the specified location.
Counter is used to keep the track of number of mines .
*/

void fixCounts( const vector <vector<bool> >& mines,vector <vector<unsigned> >& counts )
{
   // Initializing the vector counts to 0 .
     for(unsigned int i=1;i<counts.size();i++)
    {
       for(unsigned int j=1;j<counts.size();j++)
       {
           counts[i][j]=0 ;
       }
    }

    // Initializing the variable s with the size of mine .
    unsigned int s=mines.size()-1 ;
    int counter=0 ; // Declaring the variable
    // Checking the size of vector 
    if(counts.size()>1)
    {
        for (unsigned int i=0 ; i< mines.size();i++)
        {
            for (unsigned int j=0 ; j<mines.size();j++)
            {   
		// Checking the location of vactor as two dimensional vector has four corner . Hence, we need to check those four corners.
                if(i== 0 && j==0)      // Checking for Top left corner
                {
                    if(mines[i][j] ==true)
                        counter++ ;
                    if(mines[i][j+1] ==true)
                        counter++ ;
                    if(mines[i+1][j] ==true)
                        counter++ ;
                    if(mines[i+1][j+1] ==true)
                        counter++ ;
                }
                else if(i==0 && j==s)    // checking for Bottom left corner
                {
                    if(mines[i][j] ==true)
                        counter++ ;
                    if(mines[i][j-1] ==true)
                        counter++ ;
                    if(mines[i+1][j-1] ==true)
                        counter++ ;
                    if(mines[i+1][j+1] ==true)
                        counter++ ;
                }
                else if(i==s && j==0)		// Checking the Top Right corner
                {
                    if(mines[i][j] ==true)
                        counter++ ;
                    if(mines[i-1][j] ==true)
                        counter++ ;
                    if(mines[i-1][j+1] ==true)
                        counter++ ;
                    if(mines[i][j+1] ==true)
                        counter++ ;
                }
                else if(i==s && j==s)		// Checking the Bottom left corner
                {
                    if(mines[i][j] ==true)
                        counter++ ;
                    if(mines[i-1][j-1] ==true)
                        counter++ ;
                    if(mines[i-1][j] ==true)
                        counter++ ;
                    if(mines[i][j-1] ==true)
                        counter++ ;
                }
                else if(i>0 && j==0)     // Checking Left side
                {
                    if(mines[i][j] ==true)
                        counter++ ;
                    if(mines[i-1][j] ==true)
                        counter++ ;
                    if(mines[i-1][j+1] ==true)
                        counter++ ;
                    if(mines[i][j+1] ==true)
                        counter++ ;
                    if(mines[i+1][j] ==true)
                        counter++ ;
                    if(mines[i+1][j+1] ==true)
                        counter++ ;
                }
                else if(i==0 && j<s)    // Checking the Upper side
                {
                    if(mines[i][j] ==true)
                        counter++ ;
                    if(mines[i][j-1] ==true)
                        counter++ ;
                    if(mines[i][j+1] ==true)
                        counter++ ;
                    if(mines[i+1][j-1] ==true)
                        counter++ ;
                    if(mines[i+1][j] ==true)
                        counter++ ;
                    if(mines[i+1][j+1] ==true)
                        counter++ ;
                }
                else if(i==s && j<s)       // Checking the down side
                {
                    if(mines[i][j] ==true)
                        counter++ ;
                    if(mines[i][j-1] ==true)
                        counter++ ;
                    if(mines[i][j+1] ==true)
                        counter++ ;
                    if(mines[i-1][j-1] ==true)
                        counter++ ;
                    if(mines[i-1][j] ==true)
                        counter++ ;
                    if(mines[i-1][j+1] ==true)
                        counter++ ;
                }
                else if(i >0 && j==s)       // Checking the Right side
                {
                    if(mines[i][j] ==true)
                        counter++ ;
                    if(mines[i-1][j] ==true)
                        counter++ ;
                    if(mines[i+1][j] ==true)
                        counter++ ;
                    if(mines[i-1][j-1] ==true)
                 	counter++ ;
                    if(mines[i][j-1] ==true)
                        counter++ ;
                    if(mines[i+1][j-1] ==true)
                        counter++ ;
                }
                else    			// Will work for rest location
                {
                    if(mines[i-1][j-1] ==true )
                        counter++ ;
                    if(mines[i-1][j] ==true)
                        counter++ ;
                    if(mines[i-1][j+1] ==true)
                        counter++ ;
                    if(mines[i][j-1] ==true)
                        counter++ ;
                    if(mines[i][j] ==true)
                        counter++ ;
                    if(mines[i][j+1] ==true)
                        counter++ ;
                    if(mines[i+1][j-1] ==true)
                        counter++ ;
                    if(mines[i+1][j] ==true)
                        counter++ ;
                    if(mines[i+1][j+1] ==true)
                        counter++ ;
                }
                counts[i][j] =counter ;
                counter=0;
            }
        }
        }else   				// If size is 1 , then only one location needs to be defined .
        {
            for (unsigned int i=0 ; i< mines.size();i++)
            {
                for (unsigned int j=0 ; j<mines.size();j++)
                {
                    if(mines[i][j] == true )
                    {
                        counter++ ;
                        counts[i][j] =counter ;
                    }
                    else
                    {
			 counts[i][j] =counter ;
                    }
                }
            }
        }
}

/*
This function is responsible for displaying the mine locations.
This functions is getting argument of mines vector .
We are using some string like '-----' , '|' to display the output in boxes .
Using for loop, it is iterating to display the output of mine location.
*/

void displayMineLocations ( const vector <vector< bool> >& mines)
{
   unsigned  int i,j,a;
	// Declaring the string to display the output .
    string line=" ----- ";
    for(i=0;i<mines.size();i++)
        cout<<line;
	cout<<endl;
	// using for loop to display output .
    for(i=0;i<mines.size();i++)
    {
		for(a=0;a<mines.size();a++)
		cout<<"|     |";
		cout<<endl;
        for(j=0;j<mines.size();j++)
        {
		cout<<"|  ";
		if(mines[i][j])
		cout<<'X';
		else
		cout<<' ';
		cout<<"  |";
		}
		cout<<endl;
		for(a=0;a<mines.size();a++)
		cout<<"|     |";
		cout<<endl;
		for(a=0;a<mines.size();a++)
		cout<<line;
		cout<<endl;
	}
    cout<<endl;
}

/*
This function is responsible for displaying the count of mines.
This functions is getting argument of mines vector .
We are using some string like '-----' , '|' to display the output in boxes .
Using for loop, it is iterating to display the output of count .
*/

void displayMineCounts ( const vector <vector<unsigned > >& counts)
{

	unsigned int i,j,a;
	//Declaring the variale 
	string line=" ----- ";
	for(a=0;a<counts.size();a++)
		cout<<line;
	cout<<endl;
	// Using for loop to display the count of mines.
	for(i=0;i<counts.size();i++)
    	{
		for(a=0;a<counts.size();a++)
			cout<<"|     |";
		
		cout<<endl;
        	for(j=0;j<counts.size();j++)
        	{
			cout<<"|  "<<counts[i][j]<<"  |";
		}
		cout<<endl;
		for(a=0;a<counts.size();a++)
			cout<<"|     |";
		cout<<endl;
		for(a=0;a<counts.size();a++)
			cout<<line;
		cout<<endl;
	}
	cout<<endl;
}

