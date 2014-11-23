//! \file PP6Math.hpp
//! \author Abhijit Mathad
//! \brief Declaration of Functions or protocols used pp6calculator.cpp
#ifndef PP6CALCULATOR_PP6Day2MUON_HH
#define PP6CALCULATOR_PP6Day2MUON_HH
 
//----------------------------------------------------------------------
//Function Declaration
//----------------------------------------------------------------------
bool print(int &a, std::string &b, double *c, std::string &d);
bool getenergy(double *c);
bool count(std::string &input, int &numberofmuons, int &numberofantimuons);
bool store4momentum(std::string &input, double *muonE, double *antimuonE, double *muonpx, double *antimuonpx, double *muonpy, double *antimuonpy, double *muonpz, double *antimuonpz, int *muonevtnumber, int *antimuonevtnumber);
bool pp6day2muon();
#endif // PP6CALCULATOR_PP6Day2MUON_HH
