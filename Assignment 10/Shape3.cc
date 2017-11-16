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


#include "/home/cs689/progs/16s/p10/Shape3.h"
//#include "Shape3.h"

//Box class functions implementations.

// Construtor implementations function
Box::Box(const double& len,const double& wid, const double& hei)
{
	length=len;
	width=wid;
	height=hei;
}
/*
	Below is the implementation of copy constructor 
*/
Box::Box(const Box& box):Rectangle(box.length,box.width),height(box.height){}

/*
	Below is the operator overloading function for '=' .
*/
Box& Box::operator=(const Box& box)
{
	if(this!=&box)
	{
		length=box.length;
		width=box.width;
		height=box.height;
	}
	return *this;
}

/*
	Below is the operator overloading function for '+' .
*/
Box& Box::operator+=(const Box& box)
{
	if(this!=&box)
	{
		length+=box.length;
		width+=box.width;
		height+=box.height;
	}
	return *this;
}

//Destructor implementation
Box::~Box(){}

//Below function will caluclate perimeter
double Box::perimeter() const
{
    Rectangle::perimeter();
	return 0;
}

//Below function will caluclate area
double Box::area() const
{
	return (((Rectangle::perimeter())*height)+((Rectangle::area())*2)) ;
}

//Below function will caluclate volume
double Box:: volume() const
{
	return ((Rectangle::area())*height);
}

//Below function will print
void Box::print() const
{
	cout<<" length = "<<length<<" : width = "<<width<<" : height = "<<height;
}

//Cube class functions implementations.

//Construtor implementation
Cube::Cube(const double& len)
{
	length=len;
	width=len;
}
/*
	Below is the implementation of copy constructor 
*/
Cube::Cube(const Cube& cube):Square(cube){}
/*
	Below is the implementation operator overloading function for '='  
*/
Cube& Cube::operator=(const Cube& cube)
{
	if(this!=&cube)
	{
		length=cube.length;
		width=cube.width;
	}
	return *this;
}
/*
	Below is the operator overloading function for '+' .
*/
Cube& Cube::operator+=(const Cube& cube)
{
	if(this!=&cube)
	{
		length+=cube.length;
		width+=cube.width;
	}
	return *this;
}

//Destructor implementation
Cube::~Cube(){}

//Below function will caluclate perimeter
double Cube::perimeter() const
{
    Square::perimeter();
	return 0;
}

//Below function will caluclate area
double Cube::area() const
{
	return ((Square::area())*6);
}

//Below function will caluclate volume
double Cube:: volume() const
{
	return ((Square::area())*length);
}

//Below function will print
void Cube::print() const
{
	cout<<" length = "<<length;
}

//Cylinder class functions implementations.

//Construtor implementation
Cylinder::Cylinder(const double& rad,const double& hei)
{
	radius=rad;
	height=hei;
}
/*
	Below is the implementation of copy constructor
*/
Cylinder::Cylinder(const Cylinder& cylinder):Circle(cylinder.radius),height(cylinder.height){}

/*
	Below is the implementation of operator overloading '='
*/
Cylinder& Cylinder::operator=(const Cylinder& cylinder)
{
	if(this!=&cylinder)
	{
		radius=cylinder.radius;
		height=cylinder.height;
	}
	return *this;
}

/*
	Below is the operator overloading function for '+' .
*/
Cylinder& Cylinder::operator+=(const Cylinder& cylinder)
{
	if(this!=&cylinder)
	{
		radius+=cylinder.radius;
		height+=cylinder.height;
	}
	return *this;
}

//Destructor implementation
Cylinder::~Cylinder(){}

//Below function will caluclate perimeter
double Cylinder::perimeter() const
{
    Circle::perimeter();
	return 0;
}

//Below function will caluclate area
double Cylinder::area() const
{	
	return (((Circle::perimeter())*height)+((Circle::area())*2));
}

//Below function will caluclate volume
double Cylinder:: volume() const
{
	return ((Circle::area())*height);
}

//Below function will print
void Cylinder::print() const
{
	cout<<" radius = "<<radius<<" : height = "<<height;
}

//Cone class functions implementations.

//Construtor implementation
Cone::Cone(const double& r,const double& h)
{
	radius=r;
	height=h;
}
/*
	Below is the implementation of copy constructor
*/
Cone::Cone(const Cone& cone):Circle(cone.radius),height(cone.height){}

/*
	Below is the implementation of operator overloading '='
*/
Cone& Cone::operator=(const Cone& cone)
{
	if(this!=&cone)
	{
		radius=cone.radius;
		height=cone.height;
	}
	return *this;
}

/*
	Below is the operator overloading function for '+' .
*/
Cone& Cone::operator+=(const Cone& cone)
{
	if(this!=&cone)
	{
		radius+=cone.radius;
		height+=cone.height;
	}
	return *this;
}

//Destructor implementation
Cone::~Cone(){}

//Below function will caluclate perimeter
double Cone::perimeter() const
{
    Circle::perimeter();
	return 0;
}

//Below function will caluclate area
double Cone::area() const
{
	double area,s_area,cone_area;
	area=Circle::area();
	s_area=sqrt((height*height)+(radius*radius));
	cone_area=area+(s_area*(Circle::perimeter()))/2;
	return cone_area;
}

//Below function will caluclate volume
double Cone:: volume() const
{
	double volume;
	volume=(height*(Circle::area()))/3;
	return volume;
}

//Below function will print
void Cone::print() const
{
	cout<<" radius = "<<radius<<" : height = "<<height;
}

//Sphere class functions implementations.

//Construtor implementation
Sphere::Sphere(const double& rad)
{
	radius=rad;
}

//Implementation of copy constructor
Sphere::Sphere(const Sphere& sphere):Circle(sphere.radius){}

/*
	Below is the operator overloading function for '+' .
*/
Sphere& Sphere::operator=(const Sphere& sphere)
{
	if(this!=&sphere)
	{
		radius=sphere.radius;
		
	}
	return *this;
}

/*
	Below is the operator overloading function for '+' .
*/
Sphere& Sphere::operator+=(const Sphere& sphere)
{
	if(this!=&sphere)
	{
		radius+=sphere.radius;
	}
	return *this;
}

//Destructor implementation
Sphere::~Sphere(){}

//Below function will caluclate area
double Sphere::area() const
{
	double area;
	area=4*(Circle::area());
	return area;
}

//Below function will caluclate volume
double Sphere:: volume() const
{
	double volume;
	volume=(4*(Circle::area())*radius)/3;
	return volume;
}

//Tetrahedron class functions implementations.

//Construtor implementation
Tetrahedron::Tetrahedron(const double& tetra):equTriangle(tetra){}

//copy construtor implementation
Tetrahedron::Tetrahedron(const Tetrahedron& tetra):equTriangle(tetra.a){}
/*
	Below is the operator overloading function for '=' .
*/
Tetrahedron& Tetrahedron::operator=(const Tetrahedron& tetra)
{
	if(this!=&tetra)
	{
		a=tetra.a ;
		b=tetra.b;
		c=tetra.c ;		
	}
	return *this;
}

/*
	Below is the operator overloading function for '+' .
*/
Tetrahedron& Tetrahedron::operator+=(const Tetrahedron& tetra)
{
	if(this!=&tetra)
	{
		a+=tetra.a ;
		b+=tetra.b;
		c+=tetra.c ;
	}
	return *this;
}

//Destructor implementation
Tetrahedron::~Tetrahedron(){}

//Below function will caluclate perimeter
double Tetrahedron::perimeter() const
{
	Triangle::perimeter();
	return 0;
}

//Below function will caluclate area
double Tetrahedron::area() const
{
	double area;
	area=(Triangle::area())*4;
	return area;
}

//Below function will caluclate volume
double Tetrahedron::volume() const
{
	double height,area;
	height=(sqrt(2)/sqrt(3))*c;
	area=((height*(Triangle::area()))/3);
	return area;
}

