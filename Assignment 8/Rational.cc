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

#include "Rational.h"		// This is the user-defined library which include function prototype, standard library

/*
	The below function is friend function .
	This is overload function for '<<' which will be used to display the output .
	Here we are storing the output in ostream object .
*/
ostream& operator<<(ostream& os,const Rational& r)
{
    if(r.den<0 && r.num>0)			// If the denominator is negative then we are multiplying by (-1)
    {
        os<<r.num*(-1) ;
        if(r.den != 1)
            os<<"/"<<r.den*(-1);
    }
    else
    {
        os<<r.num ;
        if(r.den != 1)
            os<<"/"<<r.den;
    }
    return os;					// Returning the output stream
}
/*
	The below function is friend function.
	Here , the below function is taking the input which might have ':' or " " or tab character .
	In order to get rid of this , we are using unget function.
	After getting the value rid of special character , we are storing them in is and returning it.
*/
istream& operator>>(istream& is, Rational& r)
{
	// Defining the variable 
	int numt,dent ;				
	char spcl,spcl_char,char_spcl ;				
	r.num=1,r.den=1 ; 		
	//	Getting the value from line
	is.get(spcl) ;				  
	if(spcl=='\t')
		is>>r.num ;
	// if above condition fails , then it will go into below block and unget() will get rid of any character
	else
	{
		is.unget() ; 
		is>>r.num ;
	}
	//	Getting the value from line
	is.get(spcl) ;
	if(spcl=='\n')
		return is ;
	if(spcl=='\t' || spcl==32)
	{
		is.get(spcl_char) ;
		if(spcl_char!='\n')
		{
			char_spcl=spcl_char ;
			if(char_spcl!=47)    // '/'
			{
				dent=1;
				cerr<<"Error: line\"\t"<<r.num<<" "<<char_spcl<<" " ;
			}
		}
		else
			return is ;	
	}
	if(spcl==47)    //'/'
	{
		char_spcl=spcl ;
	}	
	//	Getting the value from line
	is.get(spcl);
	if(spcl=='\n')
		return is;
	else if(spcl=='\t')
	{
		is.get(spcl_char);
		if(spcl_char !='\n')
		{
			is.unget() ;
			is>>r.den ;
		}
		else
			return is ;
	}
	else
	{
		is.unget() ;
		is>>r.den ;
	}
	if(dent==1)
		cerr<<r.den<<"\"contains invalid number"<<endl ;
	is.get(spcl) ;
	if(spcl=='\n')
		return is ;
	if(spcl==' ' || spcl==32 || spcl=='\t')
	{
		// unget() will get rid of any character
		is.get(spcl_char) ;
		is.unget() ;
		is>>numt ;
		if(spcl_char !='\n')
			cerr<<"Error: line \""<<r.num<<char_spcl<<r.den<<" "<<numt<<"\" contains invalid number "<<endl ;
		else
			return is ;
	}
	return is ;		// Returning the input stream 
}
/*
	The below function is gcd()  i.e. Greater common divisor
	This function calculates the GCD value of two numerator and denominator which is of 'int' return type . 
*/
int Rational::gcd(int x,int y)
{
    int r=x%y ;
	while (r != 0)
	{
		x = y ;
		y = r;
		r = x % y;
	}
   	return y;				// Returning the gcd value
}
/*
	The below function is copy constructor .
	This function copies and create another object of Date object which can be used to for other purpose.	
*/
Rational::Rational(const Rational& r):num(r.num),den(r.den){}

/*
	The below function is operator overloading function .
	This function overloads the operator '=' and returns the rational
*/
Rational& Rational::operator= (const Rational& r)
{
	if(this != &r)
	{
	    num=r.num ;
	    den=r.den ;
	}
	return *this ;
}
/*
	The below function is operator overloading function .
	This function overloads the operator '+=' and returns the rational
*/
Rational& Rational::operator+=(const Rational& r)
{
     Rational rat ;
     num =num*r.den+r.num*den ;
     den=den*r.den ;
	//Below block of statement is calling gcd function .
     int g=gcd(num,den) ;
     num=num/g ;den=den/g ;
     return *this ;
}
/*
	The below function is operator overloading function .
	This function overloads the operator '-=' and returns the rational
*/
Rational& Rational::operator-=(const Rational& r)
{
     Rational rat ;
     num =num*r.den-r.num*den ;
     den=den*r.den ;
	 //Below block of statement is calling gcd function .
     int g=gcd(num,den) ;
     num=num/g ;den=den/g ;
     return *this ;
}
/*
	The below function is operator overloading function .
	This function overloads the operator '*=' and returns the rational
*/
Rational& Rational::operator*=(const Rational& r)
{
     Rational rat ;
     num =num*r.num ;
     den=den*r.den ;
	 //Below block of statement is calling gcd function .
     int g=gcd(num,den) ;
     num=num/g ;den=den/g ;
     return *this ;
}
/*
	The below function is operator overloading function .
	This function overloads the operator '/=' and returns the rational
*/
Rational& Rational::operator/=(const Rational& r)
{
     Rational rat ;
     num =num*r.den ;
     den=den*r.num ;
	 //Below block of statement is calling gcd function .
     int g=gcd(num,den) ;
     num=num/g ;den=den/g ;
     return *this ;
}
/*
	The below function is operator overloading function .
	This function overloads the operator '++' and returns the rational .
	The function is preincrementing  the value.
*/
Rational& Rational::operator++()
{
     Rational rat ;
     num =num+den ;
     den=den ;
	 //Below block of statement is calling gcd function .
     int g=gcd(num,den) ;
     num=num/g ;den=den/g ;
     return *this ;
}
/*
	The below function is operator overloading function .
	This function overloads the operator '--' and returns the rational .
	The function is decrementing  the value.
*/
Rational& Rational::operator--()
{
     Rational rat ;
     num =num-den ;
     den=den ;
	 //Below block of statement is calling gcd function .
     int g=gcd(num,den) ;
     num=num/g ;den=den/g ;
     return *this ;
}
/*
	The below function is operator overloading function .
	This function overloads the operator '++' and returns the rational .
	The function is postincrementing  the value.
*/
Rational& Rational::operator++(int r)
{
	 // We are using static so that while passing the value to output, we are getting the actual value.
     static Rational rat ;
     rat.num = num;
     rat.den = den ;
     num = num+den ;
     den = den ;
     int g=r ;
	 //Below block of statement is calling gcd function .
	 g = gcd(num,den) ;
     num=num/g ;den=den/g ;
     return rat   ;
}
/*
	The below function is operator overloading function .
	This function overloads the operator '--' and returns the rational .
	The function is postdecrementing  the value.
*/
Rational& Rational::operator--(int r)
{
	 // We are using static so that while passing the value to output, we are getting the actual value.
     static Rational rat ;
     rat.num = num;
     rat.den = den ;
     num = num - den ;
     den = den ;
	 int g=r ;
	 //Below block of statement is calling gcd function .
     g = gcd(num,den) ;
     num=num/g ;den=den/g ;
     return rat   ;
}
/*
	The below function is a friend operator overloading function .
	This function overloads the operator '+' and returns the rational .
*/
Rational operator+(const Rational& r1,const Rational& r2)
{
    return Rational(r1.num*r2.den+r2.num*r1.den,r1.den*r2.den) ;
}
/*
	The below function is a friend operator overloading function .
	This function overloads the operator '-' and returns the rational .
*/
Rational operator-(const Rational& r1,const Rational& r2)
{
    return Rational(r1.num*r2.den-r2.num*r1.den,r1.den*r2.den) ;
}
/*
	The below function is a friend operator overloading function .
	This function overloads the operator '*' and returns the rational .
*/
Rational operator*(const Rational& r1,const Rational& r2)
{
   return Rational(r1.num*r2.num,r1.den*r2.den) ;
}
/*
	The below function is a friend operator overloading function .
	This function overloads the operator '/' and returns the rational .
*/
Rational operator/(const Rational& r1,const Rational& r2)
{
   return Rational(r1.num*r2.den,r1.den*r2.num) ;
}
/*
	The below function is a friend operator overloading function .
	This function overloads the operator '==' and returns true or false accordingly .
*/
bool operator==(const Rational& r1,const Rational& r2)
{
    int up,down ;
    up=r1.num*r2.den ;
    down=r1.den*r2.num ;
    if(up==down)
        return true ;
    else
        return false ;
}
/*
	The below function is a friend operator overloading function .
	This function overloads the operator '!=' and returns true or false accordingly .
*/
bool operator!=(const Rational& r1,const Rational& r2)
{
    int up,down ;
    up=r1.num*r2.den ;
    down=r1.den*r2.num ;
    if(!(up==down))
        return true ;
    else
        return false ;
}
/*
	The below function is a friend operator overloading function .
	This function overloads the operator '<' and returns true or false accordingly .
*/
bool operator<(const Rational& r1,const Rational& r2)
{
    int up,down ;
    up=r1.num*r2.den ;
    down=r1.den*r2.num ;
    if(up<down)
        return true ;
    else
        return false ;
}
/*
	The below function is a friend operator overloading function .
	This function overloads the operator '<=' and returns true or false accordingly .
*/
bool operator<=(const Rational& r1,const Rational& r2)
{
    int up,down ;
    up=r1.num*r2.den ;
    down=r1.den*r2.num ;
    if(up<=down)
        return true ;
    else
        return false ;
}
/*
	The below function is a friend operator overloading function .
	This function overloads the operator '>' and returns true or false accordingly .
*/
bool operator>(const Rational& r1,const Rational& r2)
{
    int up,down ;
    up=r1.num*r2.den ;
    down=r1.den*r2.num ;
    if(up>down)
        return true ;
    else
        return false ;
}
/*
	The below function is a friend operator overloading function .
	This function overloads the operator '>=' and returns true or false accordingly .
*/
bool operator>=(const Rational& r1,const Rational& r2)
{
    int up,down ;
    up=r1.num*r2.den ;
    down=r1.den*r2.num ;
    if(up>=down)
        return true ;
    else
        return false ;
}
