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

// This is the user-defined library which include function prototype, standard library
#include"prog9.h"

/*
Below is the main function which will be used to call the different function for calculating the values.
Here we are defining the stack and using stream funtion to read the input file.
Once, file is read, we are calling process_token() function.
*/
int main()
{
	stack<double> e_stack;	
	string line;	
	string token;	
	
	//getline() is used to read the line.
	while(getline(cin, line))
	{		
		istringstream is(line);	
			
		while(getline(is, token, ' '))
		{	
			// calling the function process_token()
			process_token(token, e_stack);		
		}
	}
	
	// Returning '0' as main function is supposed to return . 
	return 0 ;
}

/*
The return type of unarySign() is boolean.
This function is checking if the character passed is correct unary symbol or not.
If the symbol is not unary, then it will return false else it will return true.
*/
bool unarySign ( const char& c, const string& token, const unsigned& i )
{
	bool flag=false;
	string val=token ;
	
	// Checking the unary symbol
	if(c=='-')
		flag=true ;
	else if(c=='+')
		flag=true ;
	else
		flag=false ;
	
	// checking the condition for unary symbol and will return the boolean value accordingly.
	return ((flag)&&((isdigit(val.at(i+1)))||(val.at(i+1)=='.')));		
	
}

/*
The return type of process_token() is void.
The below function takes the token as a string and then converts it into character.
After converting to character, it performs various operations like lowering the character,calling floatPoint function,getNumber().
If condition is not satisfied, it is throwing error as invalid number .
*/
void process_token(const string& token, stack < double >& S )
{
	// Declaring the variable .
	string cal=token ;
	bool Unry_sign,point_float, flag=false;	
	double digit, output, m, n;
	char symbol, o;
	
	//Using for loop for converting the string into bunch of character to perform operations.
	for(unsigned i=0;i<cal.length();i++)
	{
		if(tolower(cal.at(i))=='c')
		{		
			// Caling emptyStack() to check if it is empty or not.
			emptyStack(S);				
		}	
		
		if(i!=cal.length()-1)
		{		
			//Calling unarySign() function.
			Unry_sign=unarySign(cal.at(i), cal, i);	
		
			if(Unry_sign)
			{	 		
				symbol=cal.at(i);	
			}
		
			if(cal.at(i)=='.')
			{	
				// Calling floatPoint() function to check if the number is float or not.
				point_float=floatPoint(cal.at(i), cal, i);	
				if(point_float)
				{		
					i++;
				}	
			}
		}
		if(!Unry_sign)
		{		
			flag=isValidOperator(cal.at(i));  
	
			if(flag) 
				o=cal.at(i);
		}
		if(flag) // If the condition is true, then we are popping 2 elements from stack .
		{		
			n=popStack(S);	
			m=popStack(S);		
			output=operation(o,m,n);
			S.push(output);		
		}
		if(cal.at(i)=='=')
		{	
			printResult(S);		
		}
		if(isdigit(cal.at(i)))
		{	
			// If the character is number, then it is calling getNumber().
			digit=getNumber(symbol,cal, i, point_float); 
			if(symbol=='-')
			{ 					
					digit=(digit)*(-1);		
					S.push(digit);			
			}
			else 
			{
				S.push(digit);	
			}
		}
		// Checking for condition and if met, it is used to throw the error statement.
		if((!isdigit(cal.at(i))) && (!Unry_sign) && (tolower(cal.at(i))!='c') && (!flag) && (cal.at(i)!='='))
		{
			cerr<<"error: character '"<<cal.at(i)<<"' is invalid"<<endl; 
		}
	}
}


/*
The return type of below function is bool.
The below function will check if the character passed is floating or not.
And accordingly will return the boolean value.
*/
bool floatPoint( const char& c, const string& token, const unsigned& i )
{
	bool flag=false;
	if(c=='.')
	{
		//if it has digit, assign flag as true .
		if((isdigit(token.at(i+1))))
			flag=true;
	}
	// Returning the flag value.
	return flag;
}

/*
The return type of below function is double.
getNumber() function is used to get the double value .The function performs various operations in order to get the number.
It uses the substring function to remove any character presence.
At end, it will return the double value.
*/
double getNumber(const char& c, const string& token, unsigned& i, const bool& floatPointFlag)
{
	// Declaring the variable .
	string cal=token ;
	char c1=c ;
	if(c1=='A')
	{}
	string num,num1;
		
	int first=i;	
	int nums=0, pts=0;
	double val;
	// do-while loop is used get the length to get the substring.
	do
	{
		i++;
		nums++;			
	}while((i<=cal.length()-1)&&(isdigit(cal.at(i))|| cal.at(i)=='.'));
					
	int m=0;
	i--;
	// post decrementing the i value.
	while(m<nums)
	{
		if(cal.at(m)=='.')
			pts++;	
		m++;
	}
	// If there is more then 1 decimal, then it will throw the error.
	if(pts>1)
	{		
		num1=cal.substr(first,nums);
		cerr<<"error: number '"<<num1<<"' is invalid"<<endl;
	}
	else
	{
		//passing the substring to get the number
		num=cal.substr(first,nums);	
	}
	
	val=stringToDouble(num);		
	if(floatPointFlag)
	{ 
		//Using the power function of math library to get th proper decimal.
		val=(val/pow(10,nums));		
	}
	// returning the value.
	return val;  
}

/*
The return type of stringToDouble() is double.
The beow function will convert the string into double.
*/
double stringToDouble(string str)
{
 	double val;
	string con=str ;
    val=atof(con.c_str());  
    return val;
}

/*
The return type of isValidOperator() is boolean.
This function accepts the character and check if passed character is valid operator or not.
*/
bool isValidOperator(const char& c)
{		
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return true ;
	
	else	
		return false ;	// Returning the boolean value.
}

/*
The return typf of operation() is double.
The below function is accepting the value and performing the arithmetic operation.
*/
double operation(const char& c, const double& x, const double& y)
{
	double output=0 ;
	if(c=='+')
		output=x+y ;
	else if(c=='-')
		output=x-y ;
	else if(c=='*')
		output=x*y ;
	else if(c=='/')
		output=x/y ;
	else
		return output ;
	
	// returning the output.
	return output ;	
}

/*
The return type of below function is double.
This function is called to add the value.
If stack is empty , then it will throw error.
*/
double popStack ( stack < double >& S )
{
	double digit;
	if(S.empty())
	{ 
		cerr<<"error: stack is  empty"<<endl;
	}
	else
	{
		digit=S.top();	
		S.pop();	
	}
	return digit;
}

/*
The return type of printResult() is void.
The below function is used to display the output.
*/
void printResult(const stack<double>& S)
{
	double output;
	if(S.empty())
	{	
		//If empty, it will throw error.
		cerr<<"error: stack is empty!"<<endl;
	}
	else
	{
		// Using width and setprecision function for proper alignment of output.
		cout.width(8);
		output=S.top();			
		cout<<fixed<<setprecision(2)<<output<<endl;
	}
}

/*
The return type of emptyStack() is void.
The function is used to empty the stack.
*/
void emptyStack(stack<double>& S)
{
	int number=S.size();        
	for(int i=0;i<number;i++)
	{
		// popping all the value from stack.
		S.pop();		
	}
}

