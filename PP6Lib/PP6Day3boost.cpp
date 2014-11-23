//Standard Library
#include <iostream>
#include <cmath>//to use math functionss
#include <stdlib.h>

#include "PP6MathDay1.hpp"
#include "PP6Day3boost.hpp"
#include "PP6Day2meanE.hpp"
//----------------------------------------------------------------------
// Function Defintion
//---------------------------------------------------------------------

FourVector::FourVector(double c_)//pass in an agument that sets value of c
	: c(c_)
{}

void FourVector::boost_z(double v)
{
	double boost_factor(0.), lorentz_factor(0.);

	boost_factor = divide(v,c);
	lorentz_factor = sqrt(divide(1,subtract(1,boost_factor*boost_factor)));
		
	x = multiply(lorentz_factor,subtract(multiply(c,t),multiply(boost_factor,z)));	
	x = x;
	y = y;
	z = multiply(lorentz_factor,subtract(1,multiply(boost_factor,multiply(c,t))));	
}
double FourVector::interval() const
{
	double l4(0.),r2(0.),t2(0.);

	r2 = ((pow(x,2) + pow(y,2) + pow(z,2)));
	t2 = (t*t);

	if(t2 > r2)
	{
		l4 = sqrt(t2-r2);
		std::cout << "It is a space-like interval and the length of 4 vector or Invariant mass of particle is " << l4 << " relavant units" << std::endl;  
	}
	else if (t2 == r2)
	{
		std::cout << "It is a light-like interval and the length of 4 vector or Invariant mass of particle is zero.\n";  
	}
	else
	{
		l4 = sqrt(abs(subtract(t2,r2)));
		std::cout << "It is a time-like interval and the length of 4 vector or Invariant mass of particle is imaginary ie. " << l4 << "*i relavant units" << std::endl;
	}

	return l4;
}	

void FourVector::setboostvariables()
{
	std::cout <<"Type the four components t,x,y,z in that order with space b/w them for a 4 vector" << std::endl;
	t = get_double_number();
	x = get_double_number();
	y = get_double_number();
	z = get_double_number();
	std::cout << " The intial vector is (" << t << " , " << x << " , " << y << " , " << z << " ) " << std::endl;
}		
	
void FourVector::getboostedvariables()
{
	std::cout << " The boosted vector is (" << multiply(c,t) << " , " << x << " , " << y << " , " << z << " ) " << std::endl;
}	
//void boost_z(double *a, double v, double c)
//{
//	double boost_factor(0.), lorentz_factor(0.);
//		
//	boost_factor = divide(v,c);
//	lorentz_factor = sqrt(divide(1,subtract(1,boost_factor*boost_factor)));
//		
//	a[0] = multiply(lorentz_factor,subtract(a[0],multiply(boost_factor,a[3])));	
//	a[3]= multiply(lorentz_factor,subtract(a[2],multiply(boost_factor,a[0])));	
//}
//
//
//Fourvector* createFourvector()
//{
//	return new Fourvector;
//}
//
//void destroyFourvector(Fourvector *&q)
//{
//	if(q)
//	{
//		delete q;
//		q = 0;
//	}
//}
//void setboostvariables(fourvector *q, double)
//{
//std::cout <<"Type the four components t,x,y,z in that order with space b/w them for a 4 vector" << std::endl;
