//! \file PP6Math
//! \author Abhijit Mathad
//! \brief Declaration of FourVector Class, member variables, member functions
#ifndef PP6CALCULATOR_PP6FourVector_HH
#define PP6CALCULATOR_PP6FourVector_HH

#include "PP6ThreeVector.hpp"

class FourVector
{
     private:
	// Member variables with underscore at end accord to naming convention
	double s_;//interval
	double t_;
	static const double c_;
	static const double c2_;
	ThreeVector v3_;
	void compute_interval();
     public:
	// Constructors
	FourVector() {t_ = 0.; s_ = 0.;}//when a pointer defined with no arguments the variables are set to zero.
	FourVector(const double t, const ThreeVector &v3);//pass in arguments which are then set to member variables.
	FourVector(const FourVector &other);//copies one 3-vector components to other.
	
	// Member Functions		
	double getT() const {return t_;}
	const ThreeVector& getThreeVector() const {return v3_;}
	double getX() const {return v3_.getX();}//personal naming convention of camelCase
	double getY() const {return v3_.getY();}
	double getZ() const {return v3_.getZ();}
	double getInterval() const {return s_;};
	void setT(const double t);
	void setThreeVector(const ThreeVector& v3);
	void setX(const double x);
	void setY(const double y);
	void setZ(const double z);
	bool boost_z(const double v);
	FourVector& operator=(const FourVector &rhs);
	FourVector& operator+=(const FourVector &rhs);
	FourVector& operator-=(const FourVector &rhs);
	FourVector& operator*=(const double a);
	FourVector& operator/=(const double a);
};

//Free operators and functions
double scalarProduct(const FourVector &other1, const FourVector &other2);
FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector &lhs, const FourVector &rhs);
FourVector operator*(const double a, const FourVector &rhs);
FourVector operator/(const FourVector &lhs, const double a);
std::ostream& operator<<(std::ostream& streamoutput, const FourVector& v);
std::istream& operator>>(std::istream& streaminput, FourVector& v);

#endif // PP6CALCULATOR_PP6FourVector_HH
