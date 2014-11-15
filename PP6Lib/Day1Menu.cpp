//Standard Library
#include <iostream>
#include <cmath>
#include <limits>
#include <stdlib.h>

#include "PP6MathDay1.hpp"

//----------------------------------------------------------------------
// day1 Function Run by the program
//---------------------------------------------------------------------

void day1() 
{
	//Declare the variables that will be used globally here
	char m('0');	

	//loop through
	while (true)
	{	
		//-----------------------------------------------------------------
		//what the user wants to do	
		std::cout << std::endl;
		std::cout << "Specify what you want to do by typing the number or character:" << std::endl;
		std::cout << "	If you want to find the intercept of two lines type 1 \n";
		std::cout << "	If you want to find the solutions to a quadratic equation type 2 \n";
		std::cout << "	If you want to find the length of a 3 vector type 3 \n";
		std::cout << "	If you want to find the length of a 4 vector or Invariant mass of a particle type 4 \n";
		std::cout << "	If you want to find the invariant mass of 2 particles type 5 \n";
		std::cout << "	If you want to perform normal operations such as subtract, add, multiply, divide type 6" << std::endl;
		std::cout << "	If you are bored and would rather watch a Ninja Cat Video, type 7" << std::endl;
		std::cout << "	If you want to quit type q" << std::endl;
		std::cout << std::endl;
		
		std::cin >> m;
		//for error in std::cin
		if (!std::cin){
			std::cerr << "There is an error in the type of operation you have passed in" << std::endl;
		 	std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue; //skip the looping and continues to the next looping
		}
		//------------------------------------------------------------------	

		//-----------------------------------------------------------------
		//pick what task the user has specified to do
		if(m == '1') 
		{
			double C(0.0), M(0.0); //for intercept calculation
			std::cout << "Type the slope (m) and intercept(c) in that order with a space b/w them from equation of line of the form y = mx+c" << std::endl;
			std::cin >> M >> C;
			intercept(M,C);
		}
		else if(m == '2')
		{
			double a(0.0), b(0.0), c(0.0); //for solutions of quadratic equation
			double solutions[2];	
			std::cout << "Type the co-efficients of 2nd, 1st and 0th order in x with a space b/w them in that order of a quadratic equation of the form ax^2 + bx + c = 0" << std::endl;
			std::cin >> a >> b >> c;
			quadratic(a, b, c, solutions);
			std::cout << "The function was successful(0) in getting the distinct real roots" << quadratic(a, b, c, solutions) << std::endl;
			std::cout << "Values are from the pointers" << solutions[0] << solutions[1] << std::endl;
		}
		else if(m == '3')
		{		
			double x(0.0), y(0.0), z(0.0); //for length of 3 vector
			std::cout << "Type the x,y,z components in that order with a space b/w them for a 3 vector" << std::endl;
			std::cin >> x >> y >> z;
			length3vector(x,y,z);
		}
		else if(m == '4')
		{
			double E(0.0), px(0.0), py(0.0), pz(0.0); //for length or inv mass of four vector
			std::cout <<"Type the four components either t,x,y,z or E,px,py,pz in that order with space b/w them for a 4 vector" << std::endl;
			std::cin >> E >> px >> py >> pz;
			length4vector(E,px,py,pz);
		}
		else if(m == '5')
		{
			double E1(0.0), px1(0.0), py1(0.0), pz1(0.0), E2(0.0), px2(0.0), py2(0.0), pz2(0.0);//for inv mass or 2 particles
			std::cout <<"Type the four components E,px,py,pz in that order with space b/w them for a Particle 1" << std::endl;
			std::cin >> E1 >> px1 >> py1 >> pz1;
			std::cout <<"Type the four components E,px,py,pz in that order with space b/w them for a Particle 2" << std::endl;
			std::cin >> E2 >> px2 >> py2 >> pz2;
			InvMass2part(E1,px1,py1,pz1,E2,px2,py2,pz2);
		}
		else if(m == '6')
		{
			double a(0.0),b(0.0), d(0.0);//for performing basic arithmatic functions
			char c('/');
			
			std::cout << "Type the numbers a and b in that order with a space in b/w to perform operations a+b,a*b,a-b,a/b" << std::endl;
			std::cin >> a >> b;
			
			std::cout << "What operation should I perform?(type symbols:*,+,-,/).If want to quit type q." << std::endl;
			std::cin >> c;
			//Error in input then do the below
			if (!std::cin)
			{
				std::cerr << "There is an error in the type of operation you have passed in" << std::endl;
		 		std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue; //skip the looping and continues to the next looping
			}
		
						
			//Perform the operation	
			if (c == '*') 
			{
				d = multiply(a,b);
			}
			else if ( c == '/')
			{
				if ( b == 0) 
				{
					std::cerr << "Error! The second number that you passed in in zero. Try a non-zero number" << std::endl;
				} 
				else 
				{
					d = divide(a,b);
				}
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
		else if (m == 'q')
		{
			break; //breaks the loop completly and return to shell
		}
		else if (m == '7')
		{
			system("xdg-open https://www.youtube.com/watch?v=kDCXma0v-fY &");
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
// End of day1 function
//----------------------------------------------------------------------

