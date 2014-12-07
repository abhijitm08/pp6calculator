//Standard Library
#include <iostream>//for standard operators to work on C++
#include <cmath>//to use math functionss

#include "PP6Particle.hpp"
#include "PP6FourVector.hpp"
#include "PP6ThreeVector.hpp"
#include "PP6Day1Math.hpp"

Particle::Particle(int pdg_code,int charge, const std::string& name, const double mass, FourVector& mom)
       :pdg_code_(pdg_code), charge_(charge),name_(name),mass_(mass),mom_(mom)
{}

Particle::Particle(const int pdg_code, const int charge,const std::string& name, const double mass, const ThreeVector &mom)
       :pdg_code_(pdg_code), charge_(charge),name_(name),mass_(mass)
{
	double E(0.);
	E = sqrt(multiply(mass,mass) + multiply(mom.getLength(),mom.getLength()));
	mom_.setT(E); mom_.setThreeVector(mom);
}

Particle::Particle(const int pdg_code, const int charge,const std::string& name, const double mass, const double px, const double py, const double pz)
       :pdg_code_(pdg_code), charge_(charge),name_(name),mass_(mass) 
{
	double E(0.);
	E = sqrt(multiply(mass,mass) + px*px + py*py + pz*pz);
	mom_.setX(px); mom_.setY(py); mom_.setZ(pz); mom_.setT(E);
}

Particle::Particle(const Particle &other)
	:pdg_code_(other.pdg_code_), charge_(other.charge_), name_(other.name_), mass_(other.mass_), mom_(other.getFourMomentum())
{}


void Particle::setMass(const double mass)
{
	mass_ = mass;
}

void Particle::setPDGCode(const int pdg_code)
{
	pdg_code_ = pdg_code;
}

void Particle::setName(const std::string name)
{
	name_ = name;
}

void Particle::setCharge(const int charge)
{
	charge_ = charge;
}

void Particle::setThreeMomentum(const ThreeVector& v3)
{
	double E(0.);
	mom_.setThreeVector(v3);
	E = sqrt(add(multiply(getMass(),getMass()), multiply(v3.getLength(),v3.getLength())));
	mom_.setT(E);
}

void Particle::setFourMomentum(const FourVector& p4)
{
	mom_ = p4;
}

void Particle::setThreeMomentum(const double px, const double py, const double pz)
{
	double E(0.);
	ThreeVector p(px,py,pz);
	mom_.setThreeVector(p);
	E = sqrt(multiply(getMass(),getMass()) + multiply(p.getLength(),p.getLength()));
	mom_.setT(E);
}

bool Particle::boost_z(const double v)
{
	return mom_.boost_z(v);
}

Particle& Particle::operator=(const Particle &rhs)
{
	if (&rhs != this)
	{
		pdg_code_ = rhs.getPDGCode();
		charge_ = rhs.getCharge();
		name_ = rhs.getName();
		mass_ = rhs.getMass();
		mom_ = rhs.getFourMomentum();	
	}
	return *this;
}

std::ostream& operator<<(std::ostream& streamoutput, const Particle& p)
{
	streamoutput << "Name:";
	streamoutput << p.getName() << ", Charge: " << p.getCharge() << ", Mass: " << p.getMass() << ", PDG Code: " << p.getPDGCode();
	streamoutput << ", Four Momentum: " << p.getFourMomentum() << ", Three Momentum " << p.getThreeMomentum() << "]";
	//defined operator '<<' acting on three and four momentum so should print them off.
	return streamoutput;
}

std::istream& operator>>(std::istream& streaminput, Particle& p)
{
	int pdg_code(0), charge(0);
	std::string name("");
	double mass(0.);
	FourVector p4;
	streaminput >> pdg_code >> charge >> name >> mass >> p4;
	p.setPDGCode(pdg_code); 
	p.setMass(mass); 
	p.setCharge(charge); 
	p.setName(name); 
	p.setFourMomentum(p4); 
	p.setThreeMomentum(p4.getThreeVector());
	return streaminput;
}

double invariant_Mass_2particle(const Particle& p1, const Particle p2)
{
	FourVector p = p1.getFourMomentum() + p2.getFourMomentum();
	return sqrt(p.getInterval());
}
