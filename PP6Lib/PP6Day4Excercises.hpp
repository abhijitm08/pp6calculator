//! \file PP6Math.hpp
//! \author Abhijit Mathad
//! \brief Declaration of Functions or protocols used pp6calculator.cpp
#ifndef PP6CALCULATOR_PP6Day4template_HH
#define PP6CALCULATOR_PP6Day4template_HH
 
//----------------------------------------------------------------------
//Function Declaration
//----------------------------------------------------------------------
#include <vector>//for vector use
#include <limits>//to use the error in cin functions

template <typename T>
void printvector(typename std::vector<T> v)
{
	typename std::vector<T>::iterator iter = v.begin();
	typename std::vector<T>::iterator vEnd = v.end();
	std::cout << "======================================" << std::endl;
	std::cout << "Size is " << v.size() << std::endl;
	for( ; iter != vEnd; ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "======================================" << std::endl;
}

void temp();
#endif // PP6CALCULATOR_PP6Day4template_HH
