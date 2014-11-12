//Standard Library
#include <iostream>
#include <cmath>//to use math functionss
#include <limits>//to use the error in cin functions
#include <complex>//to use complex number functions
#include <stdlib.h>//for xdg-open?

//----------------------------------------------------------------------
// Function Defintion
//---------------------------------------------------------------------

//---------Day 1 Basic Function--------------
double add(double a, double b)
{
	return a + b;
}
double subtract(double a, double b)
{
	return a - b;
}
double multiply(double a, double b)
{
	return a * b;
}
double divide(double a, double b)
{
	return a / b;
}	

//---------Day 1 Maths Function--------------

//-----Find intercept function---------
void intercept(double m, double c)
{
	std::cout << "The x-intercept of your straight line is " << -divide(c,m) << std::endl;
	std::cout << "The y-intercept of your straight line is " << c << std::endl;
}	

//-----Find solutions to quadratic function---------
bool quadratic(double a, double b, double c, double *solutions)
{
	//Initialize variables
	double d(0.0);
	double s1(0.0);
	double s2(0.0);
	bool real_roots = false;
	d = subtract(pow(b,2), 4*multiply(a,c)) ;

	if (d > 0 || d == 0)//for real roots
	{
		s1 = divide(subtract(-b, sqrt(d)), (2*a));	
		s2 = divide(add(-b, sqrt(d)), (2*a));
		solutions[0] = s1;//*(solutions+ 0) = s1;
		solutions[1] = s2;//*(solutions + 1) = s2;
		real_roots = true;
		
		if (d > 0) //for two distinct real roots
		{
			std::cout <<"Your discriminant (b^2-4ac) is "<< d <<". As it is positive, there exists 2 distinct real roots for your quadratic equation."<<std::endl;
			std::cout << "The two distinct real solutions are " << s1 << " , " << s2 << std::endl; 
		}
		if (d == 0) //for two equal real roots
		{
			std::cout <<"Your discriminant (b^2-4ac) is zero. Therefore the two real roots are equal ie. s1 = s2."<<std::endl;
			std::cout << "The solution to your quadratic equation is " << s1 << std::endl; 
		}
	}
	else //for two distinct std::complex roots
	{
		//Initialize
		double r(0.0);
		double i(0.0);
 	
		r = divide(-b, 2*a); //real factor
		i = divide(sqrt(abs(d)), 2*a); //std::complex factor
		
		std::complex<double> cs1(r, i); // cs1 = r + i(i)
		//std::complex<double> cs2 = conj(cs1); //cs2 = r - i(i) 
		
		std::cout <<"Your discriminant (b^2-4ac) is "<< d <<". As it is negative, there exists 2 distinct std::complex roots for your quadratic equation."<<std::endl;
		std::cout << "The two std::complex roots are (" << cs1.real() << ") " << " +/- (" << cs1.imag() << "i)" << std::endl;
	}
	return real_roots;
}	

//---------- Find Length of 3 vectors----------
double length3vector(double x, double y, double z)
{
	double l3(0.0);
	
	l3 = sqrt((pow(x,2) + pow(y,2) + pow(z,2)));
	std::cout << "The length of your 3 vector is " << l3 << " relavant units" << std::endl;  
	return l3;
}

//---------Find Length of 4 vectors----------
double length4vector(double E, double px, double py, double pz)
{	
	//Initialize
	double p2(0.0);//square of magnitude of momentum
	double E2(0.0); //square of energy
	double l4(0.0);//length or invariant mass

	p2 = ((pow(px,2) + pow(py,2) + pow(pz,2)));
	E2 = (E*E);

	if(E2 > p2)
	{
		l4 = sqrt(E2-p2);
		std::cout << "It is a space-like interval and the length of 4 vector or Invariant mass of particle is " << l4 << " relavant units" << std::endl;  
	}
	else if (E2 == p2)
	{
		std::cout << "It is a light-like interval and the length of 4 vector or Invariant mass of particle is zero.\n";  
	}
	else
	{
		l4 = sqrt(abs(E2-p2));
		std::cout << "It is a time-like interval and the length of 4 vector or Invariant mass of particle is imaginary ie. " << l4 << "*i relavant units" << std::endl;
	}

	return l4;
}	
//---------Invariant Mass of 2 particles----------
double InvMass2part(double E1, double px1, double py1, double pz1, double E2, double px2, double py2, double pz2)
{	
	//Initialize
	double E(E1+E2);
	double px(px1+px2);
	double py(py1+py2);
	double pz(pz1+pz2);
	
	return length4vector(E, px, py, pz);
}

//---------------------------DAY 2-------------------------------------------
//-----------Day 2 Swap function
//----------------------------------------------------------------------

void swap(double &a, double &b)
{
	double temp_num;
	temp_num = a;
	a = b;
	b = temp_num;
	return;
}
//-----------Day 2 Sort function
//----------------------------------------------------------------------
void bubble_sort(double *a, int size)
{
	bool swap_performed = false;
	
	do
	{
		swap_performed = false;
		for ( int i = 0; i < size; i++)
		{	
			if (a[i] < a[i+1])
			{
				swap(a[i],a[i+1]);
				swap_performed = true;
			}
		}
	}
	while(swap_performed);
}
