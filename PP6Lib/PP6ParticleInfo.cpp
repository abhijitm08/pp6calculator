//Standard Library
#include <iostream>
#include <cmath>//to use math functionss
#include <stdlib.h>
#include <map>

#include "FileReader.hpp"//for reading file used here and also the template getField
#include "PP6ParticleInfo.hpp"

ParticleInfo::ParticleInfo(const ParticleInfo& other)
	:stringtoint(other.stringtoint), inttostring(other.inttostring), inttodouble(other.inttodouble), inttoint(other.inttoint)
{}

size_t ParticleInfo::size() const
{
	return stringtoint.size();
}

ParticleInfo& ParticleInfo::operator=(const ParticleInfo& rhs)
{
	if (&rhs != this)
	{
		stringtoint = rhs.stringtoint;
		inttostring = rhs.inttostring;
		inttodouble = rhs.inttodouble;
		inttoint = rhs.inttoint;
	}
	return *this;
}

ParticleInfo::ParticleInfo(std::string filename)
{
	FileReader f(filename);
	if(f.isValid())
	{
		int pdg_code(0), charge(0);
		double mass(0.);
		std::string name("");  
  		// Loop until out of lines
  		while(f.nextLine()) 
		{
			name = f.getField<std::string>(1);
			if (f.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 1" << std::endl;
				break;
			}

			pdg_code = f.getField<int>(2);
			if (f.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 2" << std::endl;
				break;
			}
			
			charge = f.getField<int>(3);
			if (f.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 3" << std::endl;
				break;
			}

			mass = f.getField<double>(4);
			if (f.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 4" << std::endl;
				break;
			}
			
			stringtoint[name] = pdg_code;	
			inttostring[pdg_code] = name;
			inttodouble[pdg_code] = mass;
			inttoint[pdg_code] = charge;
  		}
	}
	else
	{
		std::cerr << "The file that you input is not valid" << std::endl;
	}	
}

double ParticleInfo::getMassMeV(const int pid) const 
{
	IntToDouble::const_iterator p = inttodouble.find(pid);
	if(p != inttodouble.end())
	{
		return (*p).second;
	}
	else 
	{
		return 0.0;
	}
}

double ParticleInfo::getMassGeV(const int pid) const 
{
	return this -> getMassMeV(pid) / 1000;
}	

int ParticleInfo::getPDGCode(const std::string& name) const 
{
	StringToInt::const_iterator p = stringtoint.find(name);
	if(p != stringtoint.end())
	{
		return p->second;
	}
	else 
	{
		return 0;
	}
}

int ParticleInfo::getCharge(const int pid) const 
{
	IntToInt::const_iterator p = inttoint.find(pid);	
	if(p != inttoint.end())
	{
		return (*p).second;
	}
	else 
	{
		return 0.0;
	}
}

std::string ParticleInfo::getName(const int pid) const 
{
	IntToString::const_iterator p = inttostring.find(pid);	
	if(p != inttostring.end())
	{
		return p->second;
	}
	else 
	{
		return "";
	}
}
