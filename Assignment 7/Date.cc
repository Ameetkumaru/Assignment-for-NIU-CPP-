/*
*****************************************************************************************************************************************************************

CSCI 689
Assignment number 689 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 24 March,2016
Assignment Number :7
Purpose : This c++ program implements the Date class with some extra funcions like dayIndex(),monthIndex(),addDay,addMonth,addYear() .

*****************************************************************************************************************************************************************
*/

#include "Date.h"	// This is the user-defined library which include function prototype, standard library

	/*
	The below function is copy constructor .
	This function copies and create another object of Date object which can be used to for other purpose.	
	*/
	Date::Date(const Date& d):month(d.month),day(d.day),year(d.year){}	
	
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
        if(isValidMonth()==true && year !=0)   // Calling the isValidMonth() which will return true or false .
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
	
	/*
	The return type of dateDiff function is unsigned .
	This function is used to find the difference is number of days between two dates .
	We are passing two dates and calling dayIndex() function to get the value and then subtracting to find difference.	
	*/
	unsigned dateDiff(const Date & d1,const Date & d2)
	{
		// Declaring two int variable 
		int d1_Difference=0 ;
		int d2_Difference=0 ;
		// Declaring the unsigned variable 
		unsigned difference=0 ;
		
		// Calling dayIndex() function to get the number of days 
		d1_Difference=d1.dayIndex() ;
		d2_Difference=d2.dayIndex() ;

		if(d1_Difference<d2_Difference)
            difference=d2_Difference-d1_Difference ;
        else
            difference=d1_Difference-d2_Difference ;
		
	// Checking if year is negative or not. If yes, we have '-1' as here we don't need to consider '0' as year.
        if((d1.getYear()<0 && d2.getYear()>0)||(d1.getYear()>0 && d2.getYear()<0))
            difference=difference-1 ;

        return difference ;		// Returning the unsigned value
	}
	
	/*
	The return type of the below function is int.
	The below function is returning the position of a month in vector. 
	We are using for loop to get the position for vector of string contaning months.	
	*/	
	int Date::monthIndex()
	{
		int monthIndex ;
		for(unsigned i=0;i<months.size();i++)
		{
			if(months[i]==month)
				monthIndex=i ;
		}
		return monthIndex ;			// Returning the position of month
	}
	
	/*
	The return type of below function is Date.
	The below function is operator overloading , which is used to overload '=' function .
	The below function works like copy constructor .	
	*/
	Date& Date::operator= (const Date& d )
	{
		if(this != &d)
		{
			month=d.month ;
			day=d.day ;
			year=d.year ;
		}
		return *this ;
	}
	
	/*
	The return type of addDay() function is date.
	This function is adding the number of days passed by main to add.
	We are checking various condition like leap year , or if by adding , year is changing to next year.
	*/
	Date& Date::addDay(const int& n) 
	{
	// Declaring the variable and assigning them.
        int total_days=n;
        int days_in_month=daysInMonth(month);
        int position_of_month ;
	// Checking if the value pass is positive or negative.
        if(total_days>0)
        {
	/*
	Below block of code will check various condition for adding the days.
	Block of code will check if after adding days , year is changing or month is changing.
	*/
            if((days_in_month-day)>=n)
            {
                day=day+n ;
            }
            else
            {
                total_days=total_days-(days_in_month-day) ;

                while(total_days>0)
                {
                    position_of_month=monthIndex();
                    if(position_of_month<=11)
                    {
                        if(position_of_month==11)
                        {
                            month=months[0] ;
                            year=year+1 ;
                        }
                        else
                            month=months[position_of_month+1];
                    }
                    days_in_month=daysInMonth(month) ;
                    day=0 ;
                    if(total_days<=days_in_month)
                    {
                        day=total_days;
                        total_days=0 ;
                    }
                    else
                    {
                        total_days=total_days-days_in_month ;
                    }
                }
            }
        }
		// Checking for days for negative value
        if(total_days<0)
        {
		/*
		Below block of code will run until the condiiton become false.
		*/
            while(total_days<0)
            {
		/*
		Checking if day is equal to 1. 
		If yes, then it will reduce tehe month and if month is January, it will reduce the year.
		Below block of code is used for such logic where we are adding and subtracting years and month.
		*/
                if(day==1)
                {
                    position_of_month=monthIndex() ;
                    if(position_of_month>=0)
                    {
                        if(position_of_month==0)
                        {
                            month=months[11] ;
                            year=year-1 ;
                            if(year==0)
                            year=year-1 ;
                        }
                        else
                        {
                            month=months[position_of_month-1] ;
                        }
                    }
                    day=daysInMonth(month) ;
                    total_days++ ;
                }
                else
                {
                    day=day-1 ;
                    total_days++ ;
                }
            }
        }
        return *this ;			// Returning the date day.
	}
	
	
	/*
		The addMonth() function will return the date month.
		Here we are adding the number of months asked by user to add to particular date.
		We are checking for positive or negative month and then adding accordingly.
	*/
	Date& Date::addMonth(const int& n) 
	{
		// Declaring the variable and assigning the value by dividing it by 12 to get year and month.
	    int new_yr=n/12 ;
	    int new_mn=n%12 ;
		int size=months.size() ;	
		
		//Using for loop to iterate 
        for(int i=0;i<size;i++)
        {
		/*
		Below block of statement will check the various condition and then accordingly add the months.
		We are checking for various negative month also if after adding year is reducing or not.
		*/
            if(months[i]==month)
            {
                if((i+new_mn)>size && n>0)
                {
                    int j=(i+new_mn)-size ;
                    year=year+1 ;
                    month=months[j] ;
                }
                else if((i+new_mn)==size && n>0)
                {
                    int j=(i+new_mn)-size ;
                    year=year+new_yr+1 ;
                    month=months[j] ;
                }
                else if ((i+new_mn)<12 && n<0)
                {
                    if(i<6 && ((i+new_mn)>=0))
                    {
                        month=months[i+new_mn] ;
                    }
					/*
                    else if(i<6 && ((i+mn)<0))
                    {
                        year=year-1 ;
                        int k=12+(i+mn) ;
                        month=months[k];
                    }*/
                    else
                        {
                        year=year-1 ;
                        int new_month=12+(i+new_mn) ;
                        month=months[new_month];
                    }
                }
                else if((i+new_mn)<size && n>0)
                {
                    year=year+new_yr ;
                    month=months[i+new_mn] ;
                       if((isLeapYear()))
                    {
                        if(month=="February")
                        {
                            if(day>29)
                                day=1 ;
                                month="March" ;
                        }
                    }
                }
                else{
                    month=months[i+new_mn] ;
                    year=year+new_yr ;
                }
                break ;
            }
        }
        return *this ;			// Returning the date month
	}

	/*
	The return type of addYear() funtion is date.
	This function will add the number to the year and return the year.
	This function will also check for leap year and accordingly will add the day if it is leap year.
	*/
	Date& Date::addYear(const int& n) 
	{
		year =year+n ;
		if(n<0 && year==0)
			year=-1 ;
		else if (n>0 && year==0)
			year=1;
		else 
			year=year ;
		// Below block of statement will check for leap year and assign the year accordingly.
		if(!(isLeapYear()))				
		{
			if(day==29 && month=="February")
			{
				day=1 ;
				month="March" ;
			}
		}
			return *this ;				// Returning year
	}
	
	/*
	The return type of dayIndex() function is int.
	This function is considering the reference date called as base date. 
	After comparing this date, the date value passed to this function is calculating the difference in days.
	It is checking the positive and negative date and then calculates accordingly.
	*/
	int Date::dayIndex() const 
	{
	// Declaring the variable
	int dayIndex=0 ;
        int count =0 ;
        Date compare=(*this) ; 	// assigning the date object value to compare 

        Date base("January",1,1) ;	// Declare as reference Date object which will be used to find difference
		
	// Checking if year is positive or negative
        if(compare.year > 0 )
        {
            // Using for loop to iterate over the years to add days
			for(int i=1;i<compare.year ;i++)
            {
                Date a ;
                a.year=compare.year ;
                a.setYear(i) ;
		// Checking if the year is leap or not. If yes, we will add 366 days and if not , we will add 365
                if(a.isLeapYear())	
                    dayIndex=dayIndex+366 ;
                else
                    dayIndex=dayIndex+365 ;
            }
            int mIndex=compare.monthIndex() ;		// Getting the position of month
			
	// USing for loop for iterating over the months
            for(int i=0;i<mIndex;i++)
            {
                string m=months[i] ;
                int d=daysInMonth(m) ;
                dayIndex=dayIndex+d ;
            }
            dayIndex=compare.day+dayIndex ;
            return dayIndex ;		// Returning the days.
        }
	// Now we will be checking if year is negative
        else
        {
	// Using for loop to find the number of leap years and using a variable to store the leap year.
             for(int i=1;i<(-(compare.year)) ;i++)
             {
                 Date a ;
                 a.year=compare.year ;
                 a.setYear(i) ;
                 if(a.isLeapYear())
                    count++ ;
             }
	/*
	The below block of statement will calculate the days for negative year.
	*/
            while(compare.year<0)
            {
                int mIndex=compare.monthIndex() ;
                int d=daysInMonth(compare.month) ;
	
                dayIndex=dayIndex + (d-compare.day) ;
                compare.day=0 ;

                if((mIndex+1)<=11)
                {
                    compare.month=months[mIndex+1];
                }
                else
                {
                    compare.month=months[0] ;
                    compare.year=compare.year+1 ;
                    if(compare.year==0)
                    compare.year=1 ;
                }
            }
            dayIndex =-(dayIndex)-1-count  ; 
        }
	// Checking if the date is reference date and yes then will return 1 as mentioned in problem statement.
        if((day==1)&&(month=="January")&&(year==1))
            return 1;
        else
            return dayIndex ;		// returning dayIndex
	}
	
	

