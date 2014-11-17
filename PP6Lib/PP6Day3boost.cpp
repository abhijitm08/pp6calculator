//Standard Library
#include <iostream>
#include <cmath>//to use math functionss


#include "PP6MathDay1.hpp"

//----------------------------------------------------------------------
// Function Defintion
//---------------------------------------------------------------------

void boost_z(double *a, double v, double c)
{
	double boost_factor(0.), lorentz_factor(0.);
		
	boost_factor = divide(v,c);
	lorentz_factor = sqrt(divide(1,subtract(1,boost_factor*boost_factor)));
		
	a[0] = multiply(lorentz_factor,subtract(a[0],multiply(boost_factor,a[3])));	
	a[3]= multiply(lorentz_factor,subtract(a[2],multiply(boost_factor,a[0])));	
}
