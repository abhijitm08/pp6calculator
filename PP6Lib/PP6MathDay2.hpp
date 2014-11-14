//! \file PP6Math.hpp
//! \author Abhijit Mathad
//! \brief Declaration of Functions or protocols used pp6calculator.cpp
#ifndef PP6CALCULATOR_PP6MATHDay2_HH
#define PP6CALCULATOR_PP6MATHDay2_HH
 
//----------------------------------------------------------------------
//Function Declaration
//----------------------------------------------------------------------
//Day 2: swap,sort and get mean & standard deviation of variable functions
void swap_double(double &a, double &b);
void swap_int(int &a, int &b);
void bubble_sort_1(double *a, int size);
void bubble_sort_2(double *a, int *index, int size, bool& swap_performed);
bool get_AveE_stddevE(double *arr);
double get_double_number();
int get_int_number();
char get_char();
#endif // PP6CALCULATOR_PP6MATHDay2_HH
