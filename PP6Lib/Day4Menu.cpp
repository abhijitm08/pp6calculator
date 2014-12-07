//Standard Library
#include <iostream>
#include <cmath>//to use math functionss
#include <limits>
#include <stdlib.h>

#include "PP6Day4Exercises.hpp"//for temp() function
#include "PP6Day4muon.hpp"//for getType() function and for pp6day4muon() function

void day4() 
{
	//Declare the variables that will be used globally here
	char m('0');	

	//loop through
	while (true)
	{	
		//day4------------------------------------------------
		std::cout << "	   	If you want print and check things from pdg.dat, type 'a' \n";
		std::cout << "	   	If you want access day 4 homework, type 'b' \n";
		std::cout << "	   	If you want to quit, type 'q'" << std::endl;
		std::cout << std::endl;
		std::cout << "============================================================================================" << std::endl;

		m = getType<char>();
		
		//pick what task the user has specified to do
		if(m == 'a')
		{
			temp();
		}
		else if (m == 'b')
		{
			if(!pp6day4muon())
			{
				std::cerr <<"Error in the function defined in day 4 homework it return false" << std::endl;
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
// End of Day4 function
//----------------------------------------------------------------------

