//Standard Library
#include <iostream>//for standard operators to work on C++
#include <cmath>//to use math functionss

#include "PP6FourVector.hpp"
#include "PP6ThreeVector.hpp"
#include "PP6Day1Math.hpp"

const double FourVector::c_(3e8);//for boosting along z axis
const double FourVector::c2_(1);//natural
//pass in arguments which are then set to member variables.
FourVector::FourVector(const double t, const ThreeVector& v3)
	: t_(t), v3_(v3)
{
	compute_interval();
}

//copies one 3-vector components to other.
FourVector::FourVector(const FourVector &other)
	:t_(other.getT()), v3_(other.getThreeVector())
{
	compute_interval();
}

void FourVector::compute_interval()
{
	s_ = subtract(multiply(c2_,multiply(t_,t_)),multiply(v3_.getLength(), v3_.getLength()));
}

bool FourVector::boost_z(const double v)
{
	double boost_factor(0.), lorentz_factor(0.), t(0.), z(0.);

	boost_factor = divide(v,c_);
	if(boost_factor > 1)
	{
		std::cerr << "The boost factor (v/c) is greater than 1!" << std::endl;
		return false;
	}
	else
	{
		lorentz_factor = sqrt(divide(1,subtract(1,multiply(boost_factor,boost_factor))));
		
		t = multiply(lorentz_factor,subtract(t_,divide(multiply(boost_factor,v3_.getZ()), c_)));	
		setT(t);	
		z = multiply(lorentz_factor,subtract(v3_.getZ(),multiply(boost_factor,multiply(c_,t_))));	
		setZ(z);
	}
	return true;
}

void FourVector::setT(const double t)
{
	t_ = t;
	compute_interval();
}

void FourVector::setThreeVector(const ThreeVector& v3)
{
	v3_ = v3;
	compute_interval();
}
void FourVector::setX(const double x)
{
	v3_.setX(x);
	compute_interval();
}  

void FourVector::setY(const double y)
{
	v3_.setY(y);
	compute_interval();
}  

void FourVector::setZ(const double z)
{
	v3_.setZ(z);
	compute_interval();
}

FourVector& FourVector::operator=(const FourVector &rhs)
{
	if (&rhs != this)
	{
		t_ = rhs.getT();
		v3_ = rhs.getThreeVector();
		compute_interval();
	}
	return *this;
}

FourVector& FourVector::operator+=(const FourVector &rhs)
{
	t_ += rhs.getT();
	v3_ += rhs.getThreeVector();
	compute_interval();
	return *this;
}

FourVector& FourVector::operator-=(const FourVector &rhs)
{
	t_ -= rhs.getT();
	v3_ -= rhs.getThreeVector();
	compute_interval();
	return *this;
}

FourVector& FourVector::operator*=(const double a)
{
	t_ *= a;
	v3_ *= a; 
	compute_interval();
	return *this;
}

FourVector& FourVector::operator/=(const double a)
{
	t_ /= a;
	v3_ /= a; 
	compute_interval();
	return *this;
}

double scalarProduct(const FourVector &other1, const FourVector &other2)
{
	return multiply(other1.getT(),other2.getT()) - dotProduct(other1.getThreeVector(),other2.getThreeVector());
}

FourVector operator+(const FourVector &lhs, const FourVector &rhs)
{
	FourVector temp(lhs);
	temp += rhs;
	return temp;
}

FourVector operator-(const FourVector &lhs, const FourVector &rhs)
{
	FourVector temp(lhs);
	temp -= rhs;
	return temp;
}

FourVector operator*(const double a, const FourVector &rhs)
{
	FourVector temp(rhs);
	temp *= a;
	return temp;
}

FourVector operator/(const FourVector &lhs, const double a)
{
	FourVector temp(lhs);
	temp /= a;
	return temp;
}

std::ostream& operator<<(std::ostream& output, const FourVector& v)
{
	output << "[";
	output << v.getT() << ", " << v.getThreeVector() << " ]";
	return output;//as this operator already defined for 3-vector
}

std::istream& operator>>(std::istream& input, FourVector& v)
{
	double t(0.);
	ThreeVector v3;
	input >> t >> v3;//again already set this operator in class for 3 vectors
	v.setT(t); 
	v.setThreeVector(v3); 
	return input;
}
