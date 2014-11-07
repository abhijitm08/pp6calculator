#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

//----------------------------------------------------------------------
// Functions
//
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

//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Main Function Run by the program
//

int main() {
	//This program takes in a number and an operation and gives a result.
	double a(0.0);
	double b(0.0);
	char c;
	double d(0.0);
	
	while (true) {
	
		std::cout << "Type the first number" << std::endl;
		std::cin >> a;
		//Error in input then do the below
		if (!std::cin){
			std::cerr << "There is an error in the type of number you input" << std::endl;
			return 0;
		}
	
		std::cout << "Type the second number" << std::endl;
		std::cin >> b;
		//Error in input then do the below
		if (!std::cin){
			std::cerr << "There is an error in the type of number you input" << std::endl;
			return 0;
		}
		
		std::cout << "What operation should I perform?(type symbols:*,+,-,/).If want to quit type q." << std::endl;
		std::cin >> c;
		//Error in input then do the below
		if (!std::cin){
			std::cerr << "There is an error in the type of operation you have passed in" << std::endl;
		 	std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return 0;
			continue; //skip the looping and continues to the next looping
		}
	
		if (c == 'q'){
		 	std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break; //breaks the loop completly and return to shell
		}
			
		//Perform the operation	
		if (c == '*') {
			d = multiply(a,b);
		} else if ( c == '/') {
			if ( b == 0) {
				std::cerr << "Error! The second number that you passed in in zero. Try a non-zero number" << std::endl;
			} else {
				d = divide(a,b);
			}
		} else if ( c == '-') {
			d = subtract(a,b);
		} else {
			d = add(a,b);
		}
	
	std::cout << "The result is " << d << std::endl;
	} 
	
	std::cout << "Thanks for using this calculator!"<<std::endl;
	return 0;
}
