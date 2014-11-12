//! \file PP6Math.hpp
//! \author Abhijit Mathad
//! \brief Declaration of Functions or protocols used pp6calculator.cpp
#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH
 
//----------------------------------------------------------------------
//Function Declaration
//----------------------------------------------------------------------

//Day 1: Basic Functions
double add(double a, double b);
double subtract(double a, double b);
double divide(double a, double b);
double multiply(double a, double b);

//Day 1: Arithmatic Functions
void intercept(double m, double c);
bool quadratic(double a, double b, double c, double *solutions);
double InvMass2part(double E1, double px1, double py1, double pz1, double E2, double px2, double py2, double pz2);
double length3vector(double x, double y, double z);
double length4vector(double E, double px, double py, double pz);

//Day 2: swap and sort functions
void swap(double &a, double &b);
void bubble_sort(double *a, int size);

#endif // PP6CALCULATOR_PP6MATH_HH
