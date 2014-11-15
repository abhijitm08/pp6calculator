//Standard Library
#include <iostream>
#include <cmath>
#include <limits>
#include <stdlib.h>

#include "PP6MathDay1.hpp"
#include "PP6Day2meanE.hpp"
#include "PP6Day2muon.hpp"

//----------------------------------------------------------------------
// day2 Function Run by the program
//---------------------------------------------------------------------

void day2() 
{
	//Declare the variables that will be used globally here
	char m('0');	

	//loop through
	while (true)
	{	
		//day 1-------------------------------------------------
		//what the user wants to do	
		std::cout << std::endl;
		std::cout << "Specify what you want to do by typing the number or character:" << std::endl;
		std::cout << "		If you want to find the intercept of two lines type 1 \n";
		std::cout << "	  	If you want to find the solutions to a quadratic equation type 2 \n";
		std::cout << "	        If you want to find the length of a 3 vector type 3 \n";
		std::cout << "	   	If you want to find the length of a 4 vector or Invariant mass of a particle type 4 \n";
		std::cout << "	   	If you want to find the invariant mass of 2 particles type 5 \n";
		std::cout << "	   	If you want to perform normal operations such as subtract, add, multiply, divide type 6" << std::endl;
		std::cout << "------------------" << std::endl;
		//day2------------------------------------------------
		std::cout << "		If you want to swap two numbers, type 'a'" << std::endl;
		std::cout << "	   	If you want to use Bubble sort to sort your array of number, type 'b'" << std::endl;
		std::cout << "     	If you want to generate n particles and calculate their mean Energy and its standard deviation, type 'c'" << std::endl;
		std::cout << "     	If you want to pick out mu+/mu- particles from run4.dat and calculate their 10 largest combined invariant mass, type 'd'" << std::endl;
		std::cout << "------------------" << std::endl;
		std::cout << "	   	If you want to quit, type 'q'" << std::endl;
		std::cout << std::endl;

		//------------------------------------------------------------------	
		m = get_char();
		
		//-----------------------------------------------------------------
		//pick what task the user has specified to do
		if(m == '1') 
		{
			double C(0.0), M(0.0); //for intercept calculation
			std::cout << "Type the slope (m) and intercept(c) in that order with a space b/w them from equation of line of the form y = mx+c" << std::endl;
			M = get_double_number();
			C = get_double_number();
			//std::cin >> M >> C;
			intercept(M,C);
		}
		else if(m == '2')
		{
			double a(0.0), b(0.0), c(0.0); //for solutions of quadratic equation
			double solutions[2];	
			std::cout << "Type the co-efficients of 2nd, 1st and 0th order in x with a space b/w them in that order of a quadratic equation of the form ax^2 + bx + c = 0" << std::endl;
			a = get_double_number();
			b = get_double_number();
			c = get_double_number();
			//std::cin >> a >> b >> c;
			quadratic(a, b, c, solutions);
			
			if(quadratic(a, b, c, solutions))
			{
			
				std::cout << "The function was successful(1) in getting the distinct real roots :" << quadratic(a, b, c, solutions) << std::endl;
				std::cout << "The solutions are " << solutions[0] <<" " << solutions[1] << std::endl;
			}
			else
			{
				std::cout <<"Your discriminant (b^2-4ac) is negative, therefore there exists 2 distinct complex roots for your quadratic equation."<<std::endl;
				std::cout << "The function was not successful(0) in getting the distinct real roots :" << quadratic(a, b, c, solutions) << std::endl;
				std::cout << "The two std::complex roots are (" << solutions[0] << ") " << " +/- (" << solutions[1] << "i)" << std::endl;
			}
		}
		else if(m == '3')
		{		
			double x(0.0), y(0.0), z(0.0); //for length of 3 vector
			std::cout << "Type the x,y,z components in that order with a space b/w them for a 3 vector" << std::endl;
			//std::cin >> x >> y >> z;
			x = get_double_number();
			y = get_double_number();
			z = get_double_number();
			length3vector(x,y,z);
		}
		else if(m == '4')
		{
			double E(0.0), px(0.0), py(0.0), pz(0.0); //for length or inv mass of four vector
			std::cout <<"Type the four components either t,x,y,z or E,px,py,pz in that order with space b/w them for a 4 vector" << std::endl;
			//std::cin >> E >> px >> py >> pz;
			E = get_double_number();
			px = get_double_number();
			py = get_double_number();
			pz = get_double_number();
			length4vector(E,px,py,pz);
		}
		else if(m == '5')
		{
			double E1(0.0), px1(0.0), py1(0.0), pz1(0.0), E2(0.0), px2(0.0), py2(0.0), pz2(0.0);//for inv mass or 2 particles
			std::cout <<"Type the four components E,px,py,pz in that order with space b/w them for a Particle 1" << std::endl;
			//std::cin >> E1 >> px1 >> py1 >> pz1;
			E1 = get_double_number();
			px1 = get_double_number();
			py1 = get_double_number();
			pz1 = get_double_number();
			std::cout <<"Type the four components E,px,py,pz in that order with space b/w them for a Particle 2" << std::endl;
			//std::cin >> E2 >> px2 >> py2 >> pz2;
			E2 = get_double_number();
			px2 = get_double_number();
			py2 = get_double_number();
			pz2 = get_double_number();
			InvMass2part(E1,px1,py1,pz1,E2,px2,py2,pz2);
		}
		else if(m == '6')
		{
			double a(0.0),b(0.0), d(0.0);//for performing basic arithmatic functions
			char c('/');
			
			std::cout << "Type the numbers a and b in that order with a space in b/w to perform operations a+b,a*b,a-b,a/b" << std::endl;
			//std::cin >> a >> b;
			a = get_double_number();
			b = get_double_number();
			
			std::cout << "What operation should I perform?(type symbols:*,+,-,/).If want to quit type q." << std::endl;
			c = get_char();
						
			//Perform the operation	
			if (c == '*') 
			{
				d = multiply(a,b);
			}
			else if ( c == '/')
			{
					d = divide(a,b);
			} 
			else if ( c == '-') 
			{
				d = subtract(a,b);
			}
			else 
			{
				d = add(a,b);
			}
		
			std::cout << "The result is " << d << std::endl;
		} 	
		else if (m == 'a')
		{
			double a(0.0),b(0.0);
			bool swap_performed;
			std::cout << "Type the two numbers to be swaped, with space in b/w" << std::endl;
			//std::cin >> a >> b;
			a = get_double_number();
			b = get_double_number();
			std::cout << "The 1st number you typed is " << a << ". The 2nd number is" << b << std::endl;
			swap_double(a,b,swap_performed);
			if(swap_performed)
			{
				std::cout << "The 1st swaped number is " << a << ". The 2nd swaped number is " << b << std::endl;
			}
			else
			{
				std::cerr << " There was an error when swapping the numbers " << std::endl;
			}
		}		
		else if (m == 'b')
		{
			int n;
			std::cout << "Type how many numbers you want sorting" << std::endl;
			n = get_int_number();	
			
			double a[n];

			for (int i = 0; i < n; i++)
			{	
				double b(0.0);	
				std::cout << "Type your " << (i+1) << " number" << std::endl;
				b = get_double_number();
				a[i] = b;
			}
			bool sort;
			bubble_sort_1(a, n, sort);
			
			if(sort)
			{
				std::cout << "The output of the numbers in the descending order is " << std::endl;
				for (int i = 0; i < n; i++)
				{	
					std::cout << a[i] << std::endl;
				}
			}
			else
			{
				std::cerr << "There was some error in performing swap" << std::endl;
			}
		}
		else if(m == 'c')
		{
			double arr[2];
			if(!get_AveE_stddevE(arr))
			{
				std::cerr << "Failed to run this operation" << std::endl;
			}
			
			std::cout << "The mean energy of all the particles generated is " << arr[0] << " relavant units" << std::endl;
			std::cout << "The standard deviation on the mean energy generated for all the particles is " << arr[1] << " relavant units" <<std::endl;
		}
		else if (m == 'd')
		{
			if(!pp6day2muon())
			{
				std::cerr << "Failed to run this operation" << std::endl;
			}
		}
		else if (m == 'q')
		{
			break; //breaks the loop completly and return to shell
		}
		else 
		{
			std::cout << "The thing that you want to do doesn't exist here, try another task" << std::endl;
		}
		//-----------------------------------------------------------------------
		
		std::cout << std::endl;
		std::cout << "Try another task that you may want to perform" << std::endl;
		std::cout << std::endl;
	}
		
	std::cout << "Thanks for using pp6calculator, please do come back"<<std::endl;
}

//----------------------------------------------------------------------
// End of Main function
//----------------------------------------------------------------------
