//! \file PP6Math
//! \author Abhijit Mathad
//! \brief Declaration of Particle Class, member variables, member functions
#ifndef PP6CALCULATOR_PP6Particle_HH
#define PP6CALCULATOR_PP6Particle_HH

#include <cmath>//for sqaure root funct
#include "PP6FourVector.hpp"
#include "PP6ThreeVector.hpp"
#include <string>//for name of particle

class Particle
{
     private:
	// Member variables with underscore at end accord to naming convention
	int pdg_code_;
	int charge_;
	std::string name_;
	double mass_;
	FourVector mom_;
     
     public:
	// Constructors
	Particle() { pdg_code_ = 0; charge_ = 0; name_ = "No Particle", mass_ = 0.;}
	Particle(const int pdg_code,const int charge, const std::string& name, const double mass, FourVector& mom);
	Particle(const int pdg_code, const int charge,const std::string& name, const double mass, const ThreeVector &mom);
	Particle(const int pdg_code, const int charge,const std::string& name, const double mass, const double px, const double py, const double pz);
	Particle(const Particle &other);
	
	// Member Functions and operators		
	double getE() const {return mom_.getT();}
	const FourVector& getFourMomentum() const {return mom_;}
	const ThreeVector& getThreeMomentum() const {return mom_.getThreeVector();}
	double getMag4Momentum() const {return sqrt(mom_.getInterval());} 
	double getMag3Momentum() const {return getThreeMomentum().getLength();}
	double getMass() const {return mass_;}//in GeV
	int getPDGCode() const {return pdg_code_;}
	int getCharge() const {return charge_;}
	std::string getName() const {return name_;}
	void setMass(const double mass);//in GeV
	void setPDGCode(const int pdg_code);
	void setName(const std::string name);
	void setCharge(const int charge);
	void setThreeMomentum(const ThreeVector& v3);
	void setFourMomentum(const FourVector& p4);
	void setThreeMomentum(const double px, const double py, const double pz);
	bool boost_z(const double v);
	Particle& operator=(const Particle &rhs);
};

//Free operators and functions
std::ostream& operator<<(std::ostream& streamoutput, const Particle& v);//constant particle type as we want to keep the object unchanged
std::istream& operator>>(std::istream& streaminput, Particle& v);//not constant particle type as we are filling up the object member variables
double invariant_Mass_2particle(const Particle& p1, const Particle p2);

#endif // PP6CALCULATOR_PP6Particle_HH
