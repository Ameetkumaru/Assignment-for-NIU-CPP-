/*
*****************************************************************************************************************************************************************

CSCI 689
Assignment number 689 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 7 March,2016

Purpose : This c++ program implements the Date class which will validate whether the date entered is valid or not .

*****************************************************************************************************************************************************************
*/

#include "Date.h"	// This is the user-defined library which include function prototype, standard library

    /*
	This function defined below will be used to set the month for variable month .
	This variable will be called in different function to process the validation .
    */
    void Date::setMonth(const string& m)
    {
        month=m ;
        Month();     // We are calling Month() to convert the string's first character to upper case and rest to lower case.
    }

    /*
        This function defined below will be used to set the day for variable day .
        This variable will be called in different function to process the validation .
    */
    void Date::setDay(const int& d)
    {
        day=d ;
    }

    /*
        This function defined below will be used to set the year for variable year .
        This variable will be called in different function to process the validation .
    */
    void Date::setYear(const int& y)
    {
        year=y  ;
    }

    /*
	This function is used to get the month. 
	Return type of this function is string which will be returning string .
    */
    string Date::getMonth() const
    {
        return month ;
    }

   /*
        This function is used to get the Day.
        Return type of this function is int  which will be returning int(day) .
    */
    int Date::getDay() const
    {
        return day ;
    }
  
   /*
        This function is used to get the year.
        Return type of this function is int which will be returning int(year) .
    */
    int Date::getYear() const
    {
        return year ;
    }

    /*
	This void function Month() is used to convert the first character to upper case and rest character to lower case .
	We are taking the first character position to using 'toupper' string's function to convert it to upper case.
	We are using for loop to convert the rest character to lower case using string's 'tolower' function .
    */
    void Date::Month()
    {
        getMonth() ;
        month[0]=toupper(month[0]) ;
        for(unsigned int i=1;i<month.length();i++)
            month[i]=tolower(month[i]) ;
        //cout << month ;
    }
    
    /*
	The return type of the below function is bool i.e. It will return whether the function is true or false .
	In this function, we are calling isValidMonth() to perform validation whether the month entered is correct or not .
        If month is valid. It will call daysInMOnth() to get the number of days in particular month .
    */
    bool Date::isValidDate() const
    {
        if(isValidMonth()==true)   // Calling the isValidMonth() which will return true or false .
        {
            int days=daysInMonth(month) ;    // Calling daysInMonth() to get the number of days in month .
            if(days>=day) 		// If days in month is greater then day entered by user , return true else return false.
                return true ;
            else
                return false ;
        }
        return false ;            // returning the boolean value
    }

    /*
	The return type of the below function is bool. i.e. It will return true or false depending month is valid or not .
	In this function, we are using the defined vector which contains the months in a year .
	This function will check if the entered month is present in vector or not. If present ,it will return true or else it will return false .
    */
    bool Date::isValidMonth() const
    {
        bool flag =false;
        for(unsigned int i=0; i<months.size();i++)  // For loop is  using vector months 
        {
            if(months[i]==month)     // Checking if month entered by user is present in vector
            {
                flag=true ;
                break ;
            }
            else
                flag=false ;
        }
        return flag ;                // returning the boolean value
    }


    /*
	The return type of the below function is string .
	In this function, we are using the month,day and year to append and convert them in string .
	Here , we are using substring function of string to get the first 3 character of month .
	Then we are appening the day and year to this month value which we get from substring  function .
    */
    string Date::toString() const
    {
        string s="";
        int a=day,yr=year;
        s=s+intToString(a)+"-";		// Calling the intToString function to get the string value for day and year .
        s=s+(month.substr(0,3)) ;
        s=s+"-"+intToString(yr);	// Appending the day and year to month .
        return s;			// returning the string after appending the month,day and year
    }

    /*
	The return type of the function is bool .
	This function checks whether the year entered is leap year or not. 
	If the condition for leap year is met, it returns true else it returns false .
    */
    bool Date::isLeapYear() const
    {
        if (((year % 4 == 0) && !(year % 100 == 0))|| (year % 400 == 0))	// Checking whether the year is Leap year or not.
            return true ;
        else
            return false ;
    }


    /*
	The return type of below function is int.
	This function will check whether the month entered by user is having 30 or 31 days.
	It will also compare if month is febrauary . If it is, it will return 29 or 28 according to leap year .
    */
    int Date::daysInMonth(const string& m) const
    {
        int daysInMonth=0 ;

        if(m=="January" || m== "March" || m=="May" || m== "July"||m== "August" ||m== "October" || m== "December"  )
            daysInMonth=31 ;
        else if (m== "April" || m== "June" ||  m== "September" ||m== "November" )
            daysInMonth=30 ;
        else if (m=="February")
        {
            if(isLeapYear())		// calling isLeapYear() to check if month is leap year or not .
                daysInMonth=29 ;
            else
                daysInMonth=28 ;
        }
        else
            cout <<"Not a vaid month"<<endl ;

        return daysInMonth ;      // Returnng the number of days in month .
    }

    /*
	The below function is friend function .
	This is overload function for '<<' which will be used to display the output .
	Here we are storing the output in ostream object .
    */
    ostream& operator<<(ostream& os,const Date& d)
    {
        os<<d.month<<" "<<d.day<<", "<<d.year;
        return os;
    }

    /*
	The below function is friend function.
	Here , the below function is taking the input which might have ':' or ',' character .
	In order to get rid of this , we are using unget function.
	After getting the value rid of special character , we are storing them in is and returning it.
    */
    istream& operator>>(istream& is, Date& d)
    {
        int i;
        is>>d.month>>d.day;
        d.Month();
        i=is.get();       // Getting the object d.
        i=is.get();	  // Getting the object d .
        if(isdigit(i))	  // Checking  if the input is having digit or not.
        {
            is.unget();   // Unget function will be used to get rid of character .
            is>>d.year;
        }
        else
        {
            is>>d.year;
        }
        return is;	// Returning the istream object .
    }

    /*
	The return type of intToString function is string .
	Here we are using stringstream variable which will be used to convert the input day and year .
    */
    string intToString(int& n)
    {
        string intString="";
        stringstream s;
        s<<n;
        intString=s.str();       // converting the value to string .
        return intString ;	
    }
