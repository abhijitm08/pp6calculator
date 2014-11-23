//Standard Library
#include <iostream>
#include <cmath>
#include <limits>
#include <stdlib.h>

#include "PP6MathDay1.hpp"
#include "PP6FourVector.hpp"
#include "PP6Particle.hpp"
#include "PP6Day2meanE.hpp"
#include "PP6Day2muon.hpp"
//#include "PP6Day3boost.hpp"

//----------------------------------------------------------------------
// day2 Function Run by the program
//---------------------------------------------------------------------

void day3() 
{
	//Declare the variables that will be used globally here
	char m('0');	

	//loop through
	while (true)
	{	
		//day3------------------------------------------------
		std::cout << "	   	If you want to find the length of a 4 vector or Invariant mass of a particle, type 'e' \n";
		std::cout << "	   	If you want to use boost a 4-vector along z-axis, type 'f'" << std::endl;
		std::cout << "	   	If you want to do muon analysis from day 2, type 'g'" << std::endl;
		std::cout << "------------------" << std::endl;
		std::cout << "	   	If you want to quit, type 'q'" << std::endl;
		std::cout << std::endl;

		m = get_char();
		
		//pick what task the user has specified to do
		if(m == 'e')
		{
			FourVector p4;
			std::cout <<"Type in 4-components of 4-vector either t,x,y,z or E,px,py,pz with space b/w them" << std::endl;
			std::cin >> p4; 
			std::cout <<"The Length squared of 4-vector is" << p4.getInterval() << std::endl;
			if(p4.getInterval() > 0)
			{
				std::cout << "It is a space-like interval with width of " << sqrt(p4.getInterval()) << " units" << std::endl;  
			}
			else if (p4.getInterval() == 0)
			{
				std::cout << "It is a light-like interval with width of zero. \n";  
			}
			else
			{
				std::cout << "It is a time-like interval being imaginary " << sqrt(abs(p4.getInterval())) << "*i units \n";
			}
		}
		else if (m == 'f')
		{
			double v(0.);
			std::cout << "Type in the boost velocity" << std::endl;
			v = get_double_number();			
	
			FourVector p4;
			std::cout <<"Type in 4-components of 4-vector either t,x,y,z or E,px,py,pz with space b/w them" << std::endl;
			std::cin >> p4; 
			p4.boost_z(v);
			std::cout << " The boosted vector along z-axis is " << p4 << std::endl; 
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
