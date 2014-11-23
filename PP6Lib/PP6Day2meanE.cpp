//Standard Library
#include <iostream>
#include <cmath>//to use math functionss
#include <limits>//to use the error in cin functions
#include <cstdlib>//to use random generator
#include <stdlib.h>//for abs to work?


#include "PP6MathDay1.hpp"
//----------------------------------------------------------------------
// Function Defintion
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//------------Day 2 Get double, int and char with error checks on cin----------
//---------------------------------------------------------------
double get_double_number()
{
	double m(0.);
	std::cin >> m;
	while(!std::cin)
	{
		//for error in std::cin
		std::cerr << "There is an error in the type of character you have passed in, try again" << std::endl;
		std::cin.clear();//clear the buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> m;
	}
	return m;
}

int get_int_number()
{
	int m(0);
	std::cin >> m;
	while(!std::cin)
	{
		//for error in std::cin
		std::cerr << "There is an error in the type of character you have passed in, try again" << std::endl;
		std::cin.clear();//clear the buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> m;
	}
	return m;
}

char get_char()
{
	char m('0');
	std::cin >> m;
	while(!std::cin)
	{
		//for error in std::cin
		std::cerr << "There is an error in the type of character you have passed in, try again" << std::endl;
		std::cin.clear();//clear the buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> m;
	}
	return m;
}

std::string get_string(bool &success)
{
	std::string m("dafd");
	std::cin >> m;
	success = true;
	while(!std::cin)
	{
		//for error in std::cin
		std::cerr << "There is an error in the type of string you have passed in, try again" << std::endl;
		std::cin.clear();//clear the buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> m;
		success = false;
	}
	return m;
}

//---------------------------DAY 2-------------------------------------------
//-----------Day 2 Swap function
//----------------------------------------------------------------------

void swap_double(double &a, double &b, bool &swap_performed)
{
	double temp_num;
	temp_num = a;
	a = b;
	b = temp_num;
	swap_performed = true;
}
void swap_int(int &a, int &b, bool &swap_performed)
{
	int temp_num;
	temp_num = a;
	a = b;
	b = temp_num;
	swap_performed = true;
}
//-----------Day 2 Sort 1 and 2(with index sorting) functions---------
//----------------------------------------------------------------------
void bubble_sort_1(double *a, int size, bool &sort)
{	
	if (!a)
	{
		sort = false;
	}
	else
	{
		do
		{
			sort = false;
			for ( int i = 0; i < size; i++)
			{	
				if (a[i] < a[i+1])
				{
					swap_double(a[i],a[i+1], sort);
				}
			}
		}
		while(sort);
	}
}

void bubble_sort_2(double *a, int *index, int size, bool& sort)
{
	if (!a || !index)
	{
		sort = false;
	}
	else
	{
		do
		{
			sort = false;
			for ( int i = 0; i < size; i++)
			{	
				if (a[i] < a[i+1])
				{
					swap_double(a[i],a[i+1], sort);
					swap_int(index[i],index[i+1], sort);
				}
			}
		}
		while(sort);
	}
}
//-----------Day 2 Function for standard deviation----------
//---------------------------------------------------------------------
double std_deviation(double *a, double mean, int size, bool& getE)
{
	double std(0.);
	if(!a)//valid pointer check
	{
		getE = false;
	}
	else
	{
		double sum(0.); 
		double c[size];
		
		for (int i = 0; i < size; i++)
		{
			c[i] = subtract(a[i],mean)*subtract(a[i],mean); 
			sum += c[i];
		}
		std = sqrt(divide(sum,size));
		getE = true;
	}
	return std;
}
//------------Day 2 Generate double type random number-------------------
//----------------------------------------------------------------------
double random(int fMin, int fMax)
{
	double r(0.), f(0.);
	f = divide((double)rand(),RAND_MAX);//type casting
	r = add(fMin,multiply(f,subtract(fMax,fMin)));
	return r;
}
//---------------------------------------------------------------------
//------------Day 2 Get Mean Energy and Standard deviaiton on mean-------------------
//----------------------------------------------------------------------
bool get_AveE_stddevE(double *arr)
{
	int n(0); bool getE;
	if (!arr)//valid pointer check 
	{
		return getE = false; 
	}
	else 
	{
		std::cout << "How many particles would you like to generate?" << std::endl;
		n = get_int_number();
		
		double b[n];
		int index[n];//for sorting later
		double sum(0.);
		for(int i = 0; i < n; i++)
		{
			double p[4];
			double sum_sq(0.);
			for(int j = 0; j < 4; j++)
			{
				p[j] = random(1,100);//random mass and 3-momenta component generation
				sum_sq += multiply(p[j], p[j]);//sum the square of each components
			}
			b[i] = sqrt(sum_sq);//Energy of a particle
			sum += b[i];
			index[i] = i;
		}
		arr[0] = divide(sum,n); //mean
		arr[1] = std_deviation(b,arr[0],n, getE);//standard deviation
		bubble_sort_2(b,index,n,getE); //for sorting accorinding to energy with index sorting included
		std::cout << "The highest Energy particle amoung " << n << " particles is the " << index[0] << "th particle with energy " << b[0] << " relevant units" << std::endl;
	}
	return getE;
}
