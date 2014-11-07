#include <iostream>

int main() {
//This program takes in a number and an operation and gives a result.
double a(0.0);
double b(0.0);
char c;
double d(0.0);

std::cout << "Type the first number" << std::endl;
std::cin >> a;
//Error in input then do the below
if (!std::cin){
std::cout << "There is an error in the type of number you input" << std::endl;
return 0;
}

std::cout << "Type the second number" << std::endl;
std::cin >> b;
//Error in input then do the below
if (!std::cin){
std::cout << "There is an error in the type of number you input" << std::endl;
return 0;
}

std::cout << "What operation between the two numbers do you prefer?(pass in terms of symbols like *, +, -, /" << std::endl;
std::cin >> c;
//Error in input then do the below
if (!std::cin){
std::cout << "There is an error in the type of operation you have passed in" << std::endl;
return 0;
}

if (c == '*') {
	d = a * b;
} else if ( c == '/') {
	if ( b == 0) {
		std::cout << "Error! The second number that you passed in in zero. Try a non-zero number" << std::endl;
	} else {
		d = a / b;
	}
} else if ( c == '-') {
d = a - b;
} else {
d = a + b;
}

std::cout << "The result is " << d << std::endl;

return 0; 
}
