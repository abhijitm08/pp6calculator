//! \file PP6Math
//! \author Abhijit Mathad
//! \brief Declaration of ParticleInfo Class, member variables, member functions
#ifndef PP6CALCULATOR_PP6ParticleInfo_HH
#define PP6CALCULATOR_PP6ParticleInfo_HH

#include <map>
#include <string>//for name of particle

typedef std::map<std::string, int> StringToInt;
typedef std::map<int, std::string> IntToString;
typedef std::map<int, double> IntToDouble;
typedef std::map<int, int> IntToInt;

class ParticleInfo
{
     public:
	//Constructors
	ParticleInfo(std::string filename);
  	//dtor
	~ParticleInfo() {}
	
	// Member Functions and operators		
	size_t size() const;
	double getMassMeV(const int pid) const; 
	double getMassGeV(const int pid) const;
	int getPDGCode(const std::string&) const;
	int getCharge(const int pid) const;
	std::string getName(const int pid) const; 

     private:
	StringToInt stringtoint;
	IntToString inttostring;
	IntToDouble inttodouble; 
	IntToInt inttoint; 
	ParticleInfo(const ParticleInfo& other);
	ParticleInfo& operator=(const ParticleInfo &rhs);
};

#endif // PP6CALCULATOR_PP6ParticleInfo_HH
