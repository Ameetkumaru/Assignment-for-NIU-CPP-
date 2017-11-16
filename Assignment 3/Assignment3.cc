#include "Assignment3.h"

int main()
{
	int shift;
	while(cin>>shift)
	{
		process_infile(shift) ; 
	}
	return 0;
}

void process_infile(int shift)
{
	string str ;
	ifstream infile;
	ofstream outfile;
//	infile.open(PATH);
	infile.open("/home/cs689/progs/16s/p3/prog3.d2"); 
	if(infile.fail())
		 error(" Unable to open Prog3.d2 file ! Try Again... ") ;
		
	while(!infile.fail())
	{	
		getline(infile,str);
		cout <<  encodeCaesarCipher(str,shift) <<endl;
	}
	infile.close();
}

string encodeCaesarCipher (string str ,int shift)
{
    string output_str = "";
        for(unsigned int i = 0; i < str.length(); i++)
        {
            int new_posi=new_position(str[i],shift) ;
            output_str += new_posi;
        }

    return output_str ;
}

int new_position (char c,int shift)
{
    int posi=0 ;
    int new_shift=shift ;
    new_shift=shift%26;

    if( isalpha(c) && new_shift>0)
    {
        posi = c+new_shift;
        if(isupper(c))
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
        else if(islower(c))
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
   if( isalpha(c) && new_shift < 0)
    {
        posi = c+new_shift;
        if(isupper(c))
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
        else if(islower(c))
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
}

void error (string msg)
{
	cout << msg <<endl ;
}

