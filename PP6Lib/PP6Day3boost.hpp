//! \file PP6Math
//! \author Abhijit Mathad
//! \brief Declaration of Functions or protocols used pp6calculator.cpp
#ifndef PP6CALCULATOR_PP6Day3BOOST_HH
#define PP6CALCULATOR_PP6Day3BOOST_HH
 
//----------------------------------------------------------------------
//Function Declaration
//----------------------------------------------------------------------
//void boost_z(double *a, double v, double c);
//struct Fourvector;
//Fourvector* createFourvector();
//void destroyFourvector(Fourvector *&q);
class FourVector
{
     public:
	//member variables
	double t;
	double x;
	double y;
	double z;
	const double c;

	//member functions
	//FourVector() {t = 0; x = 0; y = 0; z =0; c = 0;}//while defining a pointer pass no arguments are passed and this is run
	FourVector(double c_);//pass in an agument that sets value of c
	double interval() const;
	void boost_z(const double velocity);
	void setboostvariables();
	void getboostedvariables();
};
#endif // PP6CALCULATOR_PP6Day3BOOST_HH
