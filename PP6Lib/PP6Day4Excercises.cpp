//Standard Library
#include <iostream>
#include <vector>

#include "PP6Day4Exercises.hpp"//for getType template and print vector template which we did not use in excercise 3
#include "PP6Day4muon.hpp"//for getType template
#include "PP6ParticleInfo.hpp"//for particle info class with template get

void temp()
{
	ParticleInfo particle("pdg.dat");		
	std::cout << " Type in the pdg code of the particle " << std::endl;
	int pid = getType<int>();		
	std::cout << " The particle is " << particle.getName(pid) << std::endl;
	std::cout << " The charge is " << particle.getCharge(pid) << std::endl;	
	std::cout << " The Mass in MeV is " << particle.getMassMeV(pid) << std::endl;
	std::cout << " The Mass in GeV is " << particle.getMassGeV(pid) << std::endl;
	std::cout <<"--------------------------------" << std::endl;
	std::cout << " Type in the name of the particle " << std::endl;
	std::string name = getType<std::string>();		
	std::cout << " The particle pid is " << particle.getPDGCode(name) << std::endl;
	std::cout << " The charge is " << particle.getCharge(particle.getPDGCode(name)) << std::endl;	
	std::cout << " The Mass in MeV is " << particle.getMassMeV(particle.getPDGCode(name)) << std::endl;
	std::cout << " The Mass in GeV is " << particle.getMassGeV(particle.getPDGCode(name)) << std::endl;
	//printvector(name);
	//printvector(pid);
	//printvector(charge);
	//printvector(mass);
}	
