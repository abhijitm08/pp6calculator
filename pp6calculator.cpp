//Standard Library
#include <iostream>
#include <cmath>
#include <limits>
#include <stdlib.h>

//pp6calculator library
#include "Day.hpp"

//----------------------------------------------------------------------
// Main Function Run by the program
//---------------------------------------------------------------------

int main() 
{
	while(true)
	{
		char n('0');
		std::cout << std::endl;
		std::cout << "============================================================================================" << std::endl;
		std::cout << "If you would like to access day 1 exercise type '1' or for day 2 type '2' or to quit type 'q'" << std::endl;
		std::cout << "============================================================================================" << std::endl;
		std::cin >> n;
		
		//-----------------------
		//for error in std::cin
		if (!std::cin)
		{
			std::cout << std::endl;
			std::cerr << "There is an error in the type of character you are trying to pass in" << std::endl;
			std::cin.clear();//clear window/buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		//----------------------
	
		if (n == '1')
		{
			std::cout << "============================================================================================" << std::endl;
			std::cout << "				---------- DAY 1 -----------" << std::endl;
			std::cout << "============================================================================================" << std::endl;
			day1();
		}
		else if(n == '2')
		{
			std::cout << "============================================================================================" << std::endl;
			std::cout << "				---------- DAY 2 -----------" << std::endl;
			std::cout << "============================================================================================" << std::endl;
			day2();
		} 
		else if(n == '3')
		{
			std::cout << "============================================================================================" << std::endl;
			std::cout << "				---------- DAY 3 -----------" << std::endl;
			std::cout << "============================================================================================" << std::endl;
			day3();
		} 
	
		else if(n == 'q')
		{
			std::cout << std::endl;
			std::cout<<"Thank you for using pp6calculator!"<<std::endl;
			break;
		} 
		else
		{
			std::cout << std::endl;
			std::cout<<"The character that you typed, \" " << n << " \" is not at all recognised" << std::endl;
			break;
		}
	}
return 0;
}
//----------------------------------------------------------------------
// End of Main function
//----------------------------------------------------------------------

