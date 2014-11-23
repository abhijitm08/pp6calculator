//! \file PP6Math
//! \author Abhijit Mathad
//! \brief Declaration of ThreeVector Class, member variables, member functions
#ifndef PP6CALCULATOR_PP6ThreeVector_HH
#define PP6CALCULATOR_PP6ThreeVector_HH
//C in the initial Class name according to personal naming convention
class ThreeVector
{
     private:
	// Member variables with underscore at end accord to naming convention
	double x_;
	double y_;
	double z_;
	double l_;//length
	void compute_length();
     public:
	// Constructors
	ThreeVector() {x_ = 0; y_ = 0; z_ =0; l_ = 0;}//when a pointer defined with no arguments the variables are set to zero.
	ThreeVector(const double x, const double y, const double z);//pass in arguments which are then set to member variables.
	ThreeVector(const ThreeVector &other);//copies one 3-vector components to other.
	
	// Member Functions		
	double getX() const {return x_;}//personal naming convention of camelCase
	double getY() const {return y_;}
	double getZ() const {return z_;}
	double getLength() const {return l_;}
	double getR() const;
	double getTheta() const;
	double getPhi() const;
	void setX(const double x);
	void setY(const double y);
	void setZ(const double z);
	void setR(const double r);
	void setTheta(const double theta);
	void setPhi(const double phi);
	ThreeVector& operator=(const ThreeVector &rhs);
	ThreeVector& operator+=(const ThreeVector &rhs);
	ThreeVector& operator-=(const ThreeVector &rhs);
	ThreeVector& operator*=(const double a);
	ThreeVector& operator/=(const double a);
};

//Free operators and functions
double dotProduct(const ThreeVector &other1, const ThreeVector &other2);
ThreeVector operator+(const ThreeVector &lhs, const ThreeVector &rhs);
ThreeVector operator-(const ThreeVector &lhs, const ThreeVector &rhs);
ThreeVector operator*(const double a, const ThreeVector &rhs);
ThreeVector operator/(const ThreeVector &lhs, const double a);
std::ostream& operator<<(std::ostream& streamoutput, const ThreeVector& v);
std::istream& operator>>(std::istream& streaminput, ThreeVector& v);

#endif // PP6CALCULATOR_PP6ThreeVector_HH
