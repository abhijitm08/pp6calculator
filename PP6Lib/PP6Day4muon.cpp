//Standard Library
#include <iostream>
#include <vector>
#include <cmath>//to use math functionss
#include <limits>
#include <algorithm>
#include <iterator>

#include "FileReader.hpp"
#include "PP6Particle.hpp"
#include "PP6ThreeVector.hpp"
#include "PP6Day4muon.hpp"
#include "PP6ParticleInfo.hpp"


//to map invariant mass onto muon and antimuon event numbers
typedef std::map<double, int> DoubleToInt;//index of invariant mass map to Event number

//store particle vector and event number vector objects for muons and antimuons
bool store(std::string inputfile, std::vector<Particle>& muons, std::vector<Particle>& antimuons, std::vector<int>& mueventnum, std::vector<int>& antimueventnum, const ParticleInfo& pdgdata)
{
	bool success(true);
	Particle mu;
	Particle antimu;
	int eventnum(0);
	std::string name(""),run("");
	double px(0.), py(0.), pz(0.);
	ThreeVector p3;
		
	FileReader f(inputfile);
	if(!f.isValid())
	{
		std::cerr << "The file that you input is not valid" << std::endl;
		success = false;
	}	
	else
	{
		f.nextLine();//so that it doesn't read the first line
		while (f.nextLine()) 
		{
			eventnum = f.getField<int>(1);
			if (f.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 1" << std::endl;
				success = false;
				break;
			}

    			name = f.getField<std::string>(2);
			if (f.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 2" << std::endl;
				success = false;
				break;
			}	
			
			for(int i = 0; i < 3; i++)
			{
   				if (i == 0)
				{
					px = f.getField<double>(i+3);
					if (f.inputFailed()) 
					{
		 				std::cerr << " There was an error in getting input from field " << i+3 << std::endl;
						success = false;
						break;
					}	
				}
				else if ( i == 1)
				{
					py = f.getField<double>(i+3);
					if (f.inputFailed()) 
					{
		 				std::cerr << " There was an error in getting input from field " << i+3 << std::endl;
						success = false;
						break;
					}	
				}
				else 
				{
					pz = f.getField<double>(i+3);
					if (f.inputFailed()) 
					{
		 				std::cerr << " There was an error in getting input from field " << i+3 << std::endl;
						success = false;
						break;
					}	
				}

			}	
			
    			run = f.getField<std::string>(6);
			if (f.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 6" << std::endl;
				success = false;
				break;
			}	
			
			if (run == "run4.dat")
			{
				if (pdgdata.getName(-13) == name)
				{		
					p3.setX(px);	
					p3.setY(py);	
					p3.setZ(pz);
					//construct particle object	
					antimu.setMass(pdgdata.getMassGeV(pdgdata.getPDGCode(name)));
					antimu.setName(name);
					antimu.setPDGCode(pdgdata.getPDGCode(name));
					antimu.setCharge(pdgdata.getCharge(pdgdata.getPDGCode(name)));
					antimu.setThreeMomentum(p3);//sets four momentum components				
					//populate vector
					antimuons.push_back(antimu);
					antimueventnum.push_back(eventnum);
					continue;
				}
				else if (pdgdata.getName(13) == name)
				{		
					p3.setX(px);	
					p3.setY(py);	
					p3.setZ(pz);
					//construct particle object	
					mu.setMass(pdgdata.getMassGeV(pdgdata.getPDGCode(name)));
					mu.setName(name);
					mu.setPDGCode(pdgdata.getPDGCode(name));
					mu.setCharge(pdgdata.getCharge(pdgdata.getPDGCode(name)));
					mu.setThreeMomentum(p3);//sets four momentum components				
					//populate vector
					muons.push_back(mu);
					mueventnum.push_back(eventnum);
					continue;
				}
				else
				{
					continue;
				}
			}
			else
			{
				continue;
			}	
  		}
	}
	return success;	
}

bool pp6day4muon()
{
	//declare var
	bool success(true);
	std::string inputfile("");
	std::string pdgfile("");
	std::vector<Particle> muons;
	std::vector<Particle> antimuons;
	std::vector<int> mueventnum;
	std::vector<int> antimueventnum;
	DoubleToInt invtomuevent;
	DoubleToInt invtoantimuevent;

	std::cout << " Type in the location of the pdg file (e.g. \"../pp6calculator.git/pdg.dat\"): " << std::endl;
	pdgfile = getType<std::string>();	
	const ParticleInfo pdgdata(pdgfile);
	std::cout << "Check if ParticleInfo has entries... ";
  	if (!pdgdata.size()) 
	{
    		std::cout << "failed to read pdg.dat" << std::endl;
    		success = false;
  	} 
	else 
	{
    		std::cout << "read pdg data file" << std::endl;
	}	

	std::cout << " Type in the location of the data file (e.g. \"../pp6calculator.git/observedparticles.dat\"): " << std::endl;
	inputfile = getType<std::string>();	

	if(!store(inputfile, muons, antimuons, mueventnum, antimueventnum, pdgdata))
	{
		std::cerr << " Error in storing Particle vector objects" << std::endl;
		success = false;
	}
	
	//==================For Debuging================
	//std::cout << " The size of muon vector is " << muons.size() << std::endl;
	//std::cout << " The size of antimuon vector is " << antimuons.size() << std::endl;
	//std::cout << " The size of muon event number is " << mueventnum.size() << std::endl;
	//std::cout << " The size of antimuon event number is " << antimueventnum.size() << std::endl;
	//for(unsigned int i = 0; i < muons.size(); ++i)
	//{	
	//	std::cout << " Properties of particle " << muons[i].getMass() << " " << muons[i].getName() << " " << muons[i].getPDGCode() << " " << muons[i].getCharge() << " " << muons[i].getFourMomentum() << " " << muons[i].getMag3Momentum() << " " << muons[i].getMag4Momentum() << std::endl;
	//}
	//
	//for(unsigned int j = 0; j < antimuons.size(); ++j)
	//{	
	//	std::cout << " Properties of antiparticle " << antimuons[j].getMass() << " " << antimuons[j].getName() << " " << antimuons[j].getPDGCode() << " " << antimuons[j].getCharge() << " " << antimuons[j].getFourMomentum() << " " << antimuons[j].getMag3Momentum() << " " << antimuons[j].getMag4Momentum() << std::endl;
	//}
	//==================================
		
	//Define vectors and iterators to hold invariant mass and map corresponding event numbers
	std::vector<double> M2;

	std::vector<Particle>::iterator itermuons = muons.begin();
	std::vector<Particle>::iterator muonsEnd = muons.end();
	
	std::vector<Particle>::iterator iterantimuons = antimuons.begin();
	std::vector<Particle>::iterator antimuonsEnd = antimuons.end();

	std::vector<int>::iterator itermuevent = mueventnum.begin();
	std::vector<int>::iterator mueventEnd = mueventnum.end();
	
	std::vector<int>::iterator iterantimuevent = antimueventnum.begin();
	std::vector<int>::iterator antimueventEnd = antimueventnum.end();

	//store Invarant mass of muon and antimuons cominations
	for( ; itermuons != muonsEnd, itermuevent != mueventEnd; ++itermuons, ++itermuevent)
	{
		for( ;iterantimuons != antimuonsEnd, iterantimuevent != antimueventEnd; ++iterantimuons, ++iterantimuevent)
		{
			//calculate invariant mass of mu+/mu- combination and populate vector
			M2.push_back(invariant_Mass_2particle(*itermuons,*iterantimuons));
			//map the corresping events number ie muons and antimuons to the invarant mass of mu+/mu- combination	
			invtomuevent[invariant_Mass_2particle(*itermuons,*iterantimuons)] = *itermuevent;
			invtoantimuevent[invariant_Mass_2particle(*itermuons,*iterantimuons)] = *iterantimuevent;
			
		}	
		iterantimuons = antimuons.begin();//have to reset the value of iterantimuons to begin next itermuons loop
		iterantimuevent = antimueventnum.begin();
	}

	//itermuons = muons.begin();//reset value of itermuons
	//itermuevent = mueventnum.begin();

	//define iterators to map inv mass to the event number
	std::vector<double>::iterator iterM2= M2.begin();
	std::vector<double>::iterator M2End = M2.end();
	
	//=====================For Debuggin================
	//std::cout << " The size of invariant mass vector is " << M2.size() << std::endl;	
	//for(; iterM2 != M2End; ++iterM2)
	//{
	//	std::cout << "The invariant mass is " << *iterM2 << std::endl;
	//}
	//iterM2= M2.begin();//reset value of iterM2
	//=====================================

	//sorts the inv. mass according to increasing value.
	std::sort(M2.begin(), M2.end());
	
	//------------Results-------------------------------------
	std::cout << " The number of muons in run4.dat are " << muons.size() << std::endl;
	std::cout << " The number of antimuons in run4.dat are " << antimuons.size() << std::endl;
	std::cout << "The 10 largest to lowest invariant mass that we got out of mu+/mu- combinations are: " << std::endl;	
	M2End -= 1;//decrease the value to ignore the "one after the end" element
	for (size_t i(0) ; M2End != iterM2, i < 10 ; --M2End, ++i)
	{
		DoubleToInt::iterator p = invtomuevent.find(*M2End);
		DoubleToInt::iterator q = invtoantimuevent.find(*M2End);
		std::cout<< "("<< i+1 <<")   Invariant Mass of mu+/mu-  " << (*p).first << " the corresponding event number of mu+ is " << (*p).second <<"  and for mu- is " << (*q).second << std::endl;
		success = true;
	}
	//------------End of Results---------------------------------
	return success;
}
