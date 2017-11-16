
/*
*****************************************************************************************************************************************************************

CSCI 689
Assignment number 689 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 2 May,2016
Assignment Number : 11
Purpose : N Queens Puzzle.

*****************************************************************************************************************************************************************
*/

//Calling the user declared library
#include "prog11.h"

/*
Calling the main function. 
main() will call the solveNQueens function .
*/
int main()
{
	int n=1 ;
	do
	{
		solveNQueens(n);
		n++ ;
	}while(n<9) ;
	
    return 0;
}

/*
The return type of solveNQueens function is void .
This function accepts the dimension of chess board,and then call initBoard function .
If ay error, it will show error.
*/
void solveNQueens(const unsigned& x)
{
	bool val;				
	//Initializing board variable of vector type .	
	vector< vector <bool> > board(x, vector<bool> (x));	
	//Invoking the initBoard function.
	initBoard(board);					
	
	cout<<"Board size = "<<x<<endl;
	//storing the result of solveNqueensUtil function.
	val=solveNqueensUtil(board,0);	
	
	if(val)
	{	
		//If true, then invoking the function printBoard .
		printBoard(board);			
	}
	else
	{ 
		//Displaying the error.
		cerr<<"Solution does not exist."<<endl;	
	}
}

/*
The return type of initBoard function is void .
Board variable of vector type if passed to this function .Function will initialize all box as false .
*/
void initBoard(vector<vector<bool> >& board)
{
    srand(SEED);	
	//Here, SEED is declared as external variable.
	unsigned boardSize = board.size() ;
    for(unsigned i=0;i<boardSize;i++)
	{
        for(unsigned j=0;j<boardSize;j++)
		{
			//Initialize value to false.
            board[i][j]=false;		
        }
    }
}


/*
The return type of solveNqueensUtil is boolean.
This function will check randomly for queen position where it can be placed by calling isSafe function.
Function will check for position where queen can be placed and then if queen cannot be placed, then will use back tracking method 
*/
bool solveNqueensUtil(vector<vector<bool> >& board,const unsigned& chess_row)
{
        if(chess_row==(board.size())) //If condition satisfied, board will display with queen.
		{
			return true;	        
		}
		//Initializing m variable with vector datatype.
		vector<bool> chess_col(board.size());	
        
		/*
		Below do loop will check the safe location of queen to be placed .
		This will continue till the condition becomes false .
		*/
		do
		{			
			// declaring the variable of type boolean .
        	bool column_value=true;			
			
			// Checking if columns is read or not.
        	for(unsigned i=0;i<board.size();i++)
			{
                	column_value=column_value&&chess_col[i];	
        	}
			// checking condition is no solution will exit.
        	if(column_value)
			{			
				return false;
        	}
        	else
			{
				// Generating the random number 
				int random_value=(rand()%board.size());	
        		if(!chess_col[random_value])
				{	
        			chess_col[random_value]=true;			
        			//Invoking the isSafe function .
					if(isSafe(board, chess_row, random_value))
					{	
                		//Fixing the position of queen is condtion is met.
						board[chess_row][random_value]=true;		
                		
						// Using recursive function .
						if(solveNqueensUtil(board, chess_row+1)) 
							return true;
                		board[chess_row][random_value]=false;
                    }
                }
            }
        }while(true);
}
/*
The return type of isSafe function is boolean .
This function is invoked to check if the queen can be fixed and is safe .
*/
bool isSafe(const vector<vector<bool> >& board, const int& chess_rows, const int& chess_column)
{
	int board_size=board.size();

	for(int i=0;i<board_size;i++)
	{
		for(int j=0;j<board_size;j++)
		{
			//For rows
			if(j==chess_column || i==chess_rows)
			{ 	
				//checking if queen can be placed in same row or not.
		        if(board[i][j]==true) 
					return false;	
			}
			//Checking for diagonal
			if(abs(chess_rows-i)==abs(chess_column-j))
			{			
				//Checking for condition for diagonal values .
				if(board[i][j]==true)
					return false;	//If there are any queens on the diagonal, the function should return false
			}
		}	
	}	
	return true;		
}

/*
The return type of below function is void.
printBoard function will print the vector value.
*/
void printBoard(const vector<vector<bool> >&board)
{
/*	unsigned i,j,m;

	unsigned sizeOfBoard=board.size() ;
	string line=" ----- ";

	for(i=0;i<sizeOfBoard;i++)
		cout<<line;
    cout<<endl;

	for(i=0;i<sizeOfBoard;i++)
    {
        for(m=0;m<sizeOfBoard;m++)
			cout<<"|     |";
        cout<<endl;
        for(j=0;j<sizeOfBoard;j++)
        {
			cout<<"|  ";
			if(board[i][j])
				cout<<'Q';
			else
				cout<<' ';
			cout<<"  |";
        }
        cout<<endl;
        
		for(m=0;m<sizeOfBoard;m++)
			cout<<"|     |";
        cout<<endl;
       
		for(m=0;m<sizeOfBoard;m++)
			cout<<line;
        cout<<endl;
    }    
	cout<<endl;
*/		unsigned b_size=board.size(); 
        for(unsigned m=0;m<b_size;m++)
        {
			for(unsigned s=0;s<b_size;s++)
				cout<<"----"; 
			cout<<endl<<"|";      
		
			for(unsigned c=0;c<b_size;c++)
			{
				if(board[m][c])
				{
					cout<<" "<<"Q"<<" "<<"|"; 
				}
				else
				{
					cout<<" "<<" "<<" "<<"|"; 
				}
			}
			cout<<endl; 
        }
        
		for(unsigned d=0;d<b_size;d++)
			cout<<"----"; 
        cout<<endl<<endl; 


}
