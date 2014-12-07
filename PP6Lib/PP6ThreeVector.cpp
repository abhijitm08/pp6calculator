//Standard Library
#include <iostream>//for standard operators to work on C++
#include <cmath>//to use math functionss

#include "PP6ThreeVector.hpp"
#include "PP6Day1Math.hpp"

//pass in arguments which are then set to member variables.
ThreeVector::ThreeVector(const double x, const double y, const double z)
	: x_(x), y_(y), z_(z)
{
	compute_length();
}

//copies one 3-vector components to other.
ThreeVector::ThreeVector(const ThreeVector &other)
	:x_(other.x_),y_(other.y_),z_(other.z_)
{
	compute_length();
}

void ThreeVector::compute_length()
{
	l_=sqrt(x_*x_ + y_*y_ + z_*z_);
}

void ThreeVector::setX(const double x)
{
	x_ = x;
	compute_length();
}  

void ThreeVector::setY(const double y)
{
	y_ = y;
	compute_length();
}  

void ThreeVector::setZ(const double z)
{
	z_ = z;
	compute_length();
}

double ThreeVector::getR() const
{
	return getLength();
}

double ThreeVector::getTheta() const
{
	if (x_ == 0)
	{
		std::cout << " Error! Denominator is zero " << std::endl;
		return 0.0;
	}
	else 
	{
		return atan2(y_,x_);
	}
}	
	
double ThreeVector::getPhi() const
{
	return acos(divide(z_,l_));
}	

void ThreeVector::setR(const double r)
{
	x_ = r*cos(getTheta())*sin(getPhi());
	y_ = r*sin(getTheta())*sin(getPhi());
	z_ = r*cos(getPhi());
	compute_length();
}

void ThreeVector::setTheta(const double theta)
{
	x_ = getLength()*cos(theta)*sin(getPhi());
	y_ = getLength()*sin(theta)*sin(getPhi());
	compute_length();
}

void ThreeVector::setPhi(const double phi)
{
	x_ = getR()*cos(getTheta())*sin(phi);
	y_ = getR()*sin(getTheta())*sin(phi);
	z_ = getR()*cos(phi);
	compute_length();
} 

ThreeVector& ThreeVector::operator=(const ThreeVector &rhs)
{
	if (&rhs != this)
	{
		x_ = rhs.getX();
		y_ = rhs.getY();
		z_ = rhs.getZ();
		compute_length();
	}
	return *this;
}

ThreeVector& ThreeVector::operator+=(const ThreeVector &rhs)
{
	x_ += rhs.getX();
	y_ += rhs.getY();
	z_ += rhs.getZ();
	compute_length();
	return *this;
}

ThreeVector& ThreeVector::operator-=(const ThreeVector &rhs)
{
	x_ -= rhs.getX();
	y_ -= rhs.getY();
	z_ -= rhs.getZ();
	compute_length();
	return *this;
}

ThreeVector& ThreeVector::operator*=(const double a)
{
	x_ *= a;
	y_ *= a;
	z_ *= a;
	compute_length();
	return *this;
}

ThreeVector& ThreeVector::operator/=(const double a)
{
	x_ /= a;
	y_ /= a;
	z_ /= a;
	compute_length();
	return *this;
}

double dotProduct(const ThreeVector &other1, const ThreeVector &other2)
{
	return multiply(other1.getX(),other2.getX()) + multiply(other1.getY(),other2.getY()) + multiply(other1.getZ(),other2.getZ());
}

ThreeVector operator+(const ThreeVector &lhs, const ThreeVector &rhs)
{
	ThreeVector temp(lhs);
	temp += rhs;
	return temp;
}

ThreeVector operator-(const ThreeVector &lhs, const ThreeVector &rhs)
{
	ThreeVector temp(lhs);
	temp -= rhs;
	return temp;
}

ThreeVector operator*(const double a, const ThreeVector &rhs)
{
	ThreeVector temp(rhs);
	temp *= a;
	return temp;
}

ThreeVector operator+(const ThreeVector &lhs, const double a)
{
	ThreeVector temp(lhs);
	temp /= a;
	return temp;
}

std::ostream& operator<<(std::ostream& streamoutput, const ThreeVector& v)
{
	streamoutput << "[";
	streamoutput << v.getX() << ", ";
	streamoutput << v.getY() << ", " << v.getZ() << "]";
	return streamoutput;
}

std::istream& operator>>(std::istream& streaminput, ThreeVector& v)
{
	double x(0.), y(0.), z(0.);
	streaminput >> x >> y >> z;
	v.setX(x); 
	v.setY(y);
	v.setZ(z);
	return streaminput;
}
