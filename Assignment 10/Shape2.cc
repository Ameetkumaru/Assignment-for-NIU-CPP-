/*
*****************************************************************************************************************************************************************

CSCI 689
Assignment number 689 --> Spring 2016
Ameetkumar Omprakash Upadhyay
Zid : Z1791181
Date due : 20 April,2016
Assignment Number : 10
Purpose : This c++ program implements the Geometric Shapes .

*****************************************************************************************************************************************************************
*/


#include "/home/cs689/progs/16s/p10/Shape2.h"
//#include "Shape2.h"

//Rectangle class functions implementations.

/*
	Below is the constructor implementation
*/
Rectangle:: Rectangle(const double& l,const double& w):length(l),width(w){}

/*
	Below is the implementation of copy constructor 
*/
Rectangle::Rectangle(const Rectangle& rect):length(rect.length),width(rect.width){}

/*
	Below is the operator overloading function for '=' .
*/
Rectangle& Rectangle::operator=(const Rectangle& rect)
{
	if(this!=&rect)
	{
		length=rect.length;
		width=rect.width;
	}
	return *this;
}

/*
	Below is the operator overloading function for '+' .
*/
Rectangle& Rectangle::operator+=(const Rectangle& rect)
{
	if(this!=&rect)
	{
		length+=rect.length;
		width+=rect.width;
	}
	return *this;
}
/*
	Below is the destrutor implementation .
*/
Rectangle::~Rectangle(){}
/*
	Below function will calculate the perimeter for rectangle.
*/
double Rectangle::perimeter() const
{
	return ((length+width)*2);
}
/*
	Below function will calculate the area for rectangle.
*/
double Rectangle::area() const
{
	double area=length*width ;
	return area;
}
/*
	Below function will print the rectangle value.
*/
void Rectangle::print() const
{
	cout<<" length = "<<length<<" : "<<"width = "<<width;
}

//Circle class functions implementations.
/*
	Below is the constructor implementation
*/
Circle:: Circle(const double& cir):radius(cir){}
/*
	Below is the implementation of copy constructor 
*/
Circle::Circle(const Circle& cir):radius(cir.radius){}

/*
	Below is the implementation of operator overloading '=' 
*/
Circle& Circle::operator=(const Circle& cir)
{
	if(this!=&cir)
	{
		radius=cir.radius;
	}
	return *this;
}
/*
	Below is the implementation of operator overloading '+'
*/
Circle& Circle::operator+=(const Circle& cir)
{
	if(this!=&cir)
	{
		radius=radius+cir.radius;
	}
	return *this;
}
/*
	Below is the destrutor implementation .
*/
Circle::~Circle(){}
/*
	Below function calculates the perimeter
*/
double Circle::perimeter() const
{
	return ((PI)*(radius)*2);
}
/*
	Below function calculates the area
*/
double Circle::area() const
{
	return ((radius)*(radius)*(PI));
}
/*
	Below function is used to print
*/
void Circle::print() const
{
	cout<<" radius = "<<radius;
}

//Triangle class functions implementations.

/*
	Below is the constructor implementation
*/
Triangle:: Triangle(const double& a,const double& b,const double& c):a(a),b(b),c(c){}
/*
	Below is the copy constructor implementation
*/
Triangle::Triangle(const Triangle& tri):a(tri.a),b(tri.b),c(tri.c){}
/*
	Below is the operator overloading for '='
*/
Triangle& Triangle::operator=(const Triangle& tri)
{
	if(this!=&tri)
	{
		a=tri.a;
		b=tri.b;
		c=tri.c;
	}
	return *this;
}
/*
	Below is the operator overloading for '+'
*/
Triangle& Triangle::operator+=(const Triangle& tri)
{
	if(this!=&tri)
	{
		a+=tri.a;
		b+=tri.b;
		c+=tri.c;
	}
	return *this;
}
/*
	Below is the destructor function
*/
Triangle::~Triangle(){}

//Below function will caluclate perimeter
double Triangle::perimeter() const	
{
	return (b+c+a);
}

//Below function will caluclate area
double Triangle::area() const
{
	double side,tri_area;
	side=(a+b+c)/2;
	tri_area=sqrt(side*(side-a)*(side-b)*(side-c));
	return tri_area;
}

//Below function will print triangle
void Triangle::print() const
{
	cout<<" a = "<<a<<" b = "<<b<<" c = "<<c;
}

//Square class functions implementations.

// Below function is constructor
Square::Square(const double& s)
{
	length=s;
	width=s;
}
//Below is the implementation of copy constructor
Square:: Square(const Square& l):Rectangle(l.length,l.width){}
/*
	Below is the implementation of operator overloading
*/
Square& Square::operator=(const Square& rect)
{
	if(this!=&rect)
	{
		length=rect.length;
		width=rect.width;
	}
	return *this;
}
/*
	Below is the operator overloading function for '+' .
*/
Square& Square::operator+=(const Square& rect)
{
	if(this!=&rect)
	{
		length+=rect.length;
		width+=rect.width;
	}
	return *this;
}

//Below function is destructor function
Square::~Square(){}

//Below function will print	
void Square::print() const
{
	cout<<" length = "<<length;
}

//rightTriangle class functions implementations.

//Constructor implementation
rightTriangle::rightTriangle(const double& rx,const double& ry)
{
	a=rx; b=ry;
	c=sqrt(rx*rx+ry*ry);
}

//destructor implementation
rightTriangle::~rightTriangle(){}

//Below function will print
void rightTriangle::print() const
{
	cout<<" length = "<<a<<" : height = "<<b;
}

//equTriangle class functions implementations.

//Constructor implementation
equTriangle::equTriangle(const double& eq_tri)
{
	a=b=c=eq_tri;		
}

//Desturctor implementation	
equTriangle::~equTriangle(){}

//Below function will print
void equTriangle::print() const
{
	cout<<" length = "<<a;
}

