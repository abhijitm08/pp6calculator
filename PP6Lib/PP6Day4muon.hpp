//! \file PP6Math.hpp
//! \author Abhijit Mathad
//! \brief Declaration of Functions or protocols used pp6calculator.cpp
#ifndef PP6CALCULATOR_PP6Day4MUON_HH
#define PP6CALCULATOR_PP6Day4MUON_HH
 
//----------------------------------------------------------------------
//Function Declaration
//----------------------------------------------------------------------
template <typename N>
N getType()
{
	N m;
	std::cin >> m;
	while(!std::cin)
	{
		//for error in std::cin
		std::cerr << "There is an error in the type you have passed in, try again" << std::endl;
		std::cin.clear();//clear the buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> m;
	}
	return m;
}

bool pp6day4muon();
#endif // PP6CALCULATOR_PP6Day4MUON_HH
