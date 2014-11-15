//Standard Library
#include <iostream>
#include <cmath>//to use math functionss
#include <limits>//to use the error in cin functions
#include <cstdlib>//to use random generator
#include <stdlib.h>

#include "FileReader.hpp"
#include "PP6MathDay1.hpp"
#include "PP6Day2meanE.hpp"
//----------------------------------------------------------------------
// Function Defintion
//---------------------------------------------------------------------
bool print(int &a, std::string &b, double *c, std::string &d)
{
	if(!c)
	{
		return false;
	}
	std::cout <<"Event number: " << a << ", Particle type: " << b << ", Px: " << c[0] << ", Py: " << c[1] << ", Pz: " << c[2] << ", E: " << c[3] << ", Data Source: " << d << std::endl;
	return true;
}

bool getenergy(double *c)
{
	if(!c)
	{
		return false;
	}
	double muonmass = 0.106; //GeV
	c[3] = sqrt(c[0]*c[0] + c[1]*c[1] + c[2]*c[2] + (muonmass * muonmass));
	return true;
}

bool count(std::string &input, int &numberofmuons, int &numberofantimuons)
{
	//open the file to be read
	FileReader f(input);
	bool success;
	// Only process if the file is open/valid
	if (f.isValid())
	{
  		// Loop until out of lines
		std::cout << "=======================================================================" << std::endl;
		std::cout << "=======================================================================" << std::endl;
  		while (f.nextLine()) 
		{
			int a = f.getFieldAsInt(1);
			if (f.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 1" << std::endl;
				success = false;
				break;
			}

			
    			std::string b = f.getFieldAsString(2);
			if (f.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 2" << std::endl;
				success = false;
				break;
			}	
			
			double c[4];
			for(int i = 0; i < 3; i++)
			{
   				c[i] = f.getFieldAsDouble(i+3);
				if (f.inputFailed()) 
				{
		 			std::cerr << " There was an error in getting input from field " << i+3 << std::endl;
					success = false;
					break;
				}	
			}	
			c[3] = 0.0;
			
    			std::string d = f.getFieldAsString(6);
			if (f.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 6" << std::endl;
				success = false;
				break;
			}	
			
			if (d == "run4.dat")
			{
				if (b == "mu+")
				{		
					success = getenergy(c);//gets energy
					success = print(a,b,c,d);//prints out run4 muons energy and momentum
					numberofmuons++;
					continue;
				}
				else if(b == "mu-")
				{		
					success = getenergy(c);//gets energy
					success = print(a,b,c,d);//prints out run4 muons energy and momentum
					numberofantimuons++;
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
		std::cout << "=======================================================================" << std::endl;
		std::cout << "=======================================================================" << std::endl;
		std::cout << " There are " << numberofmuons << " muons in run4.dat data file" << std::endl;
		std::cout << " There are " << numberofantimuons << " anti-muons in run4.dat data file" << std::endl;
	}
	else
	{
		std::cerr << "The file that you input is not valid" << std::endl;
		success = false;
	}	
	return success;	
}

bool store4momentum(std::string &input, double *muonE, double *antimuonE, double *muonpx, double *antimuonpx, double *muonpy, double *antimuonpy, double *muonpz, double *antimuonpz, int *muonevtnumber, int *antimuonevtnumber)
{
	bool success;
	if(!muonE || !antimuonE || !muonpx || !antimuonpx || !muonpy || !antimuonpy || !muonpz || !antimuonpz || !muonevtnumber || !antimuonevtnumber)
	{
		success = false;
	}

	//open the file to be read
	FileReader f1(input);
	
	int numberofmuons(0);
	int numberofantimuons(0);
	// Only process if the file is open/valid
	if (f1.isValid())
	{
		std::cout << "=======================================================================" << std::endl;
		std::cout << "=======================================================================" << std::endl;
  		// Loop until out of lines
  		while (f1.nextLine()) 
		{
    			int a = f1.getFieldAsInt(1);
			if (f1.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 1" << std::endl;
				success = false;
				break;
			}

			
    			std::string b = f1.getFieldAsString(2);
			if (f1.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 2" << std::endl;
				success = false;
				break;
			}	
			
			double c[4];
			for(int i = 0; i < 3; i++)
			{
   				c[i] = f1.getFieldAsDouble(i+3);
				if (f1.inputFailed()) 
				{
		 			std::cerr << " There was an error in getting input from field " << i+3 << std::endl;
					success = false;
					break;
				}	
			}	
			c[3] = 0.0;
			
    			std::string d = f1.getFieldAsString(6);
			if (f1.inputFailed()) 
			{
		 		std::cerr << " There was an error in getting input from field 6" << std::endl;
				success = false;
				break;
			}	
			
			if (d == "run4.dat")
			{
				if (b == "mu+")
				{
					success = getenergy(c);//gets energy and prints out run4 muons
					muonE[numberofmuons] = c[3];
					muonpx[numberofmuons] = c[0];
					muonpy[numberofmuons] = c[1];
					muonpz[numberofmuons] = c[2];
					muonevtnumber[numberofmuons] = a;
					numberofmuons++;
					continue;
				}
				else if(b == "mu-")
				{		
					success = getenergy(c);//gets energy and prints out run4 muons
					antimuonE[numberofantimuons] = c[3];
					antimuonpx[numberofantimuons] = c[0];
					antimuonpy[numberofantimuons] = c[1];
					antimuonpz[numberofantimuons] = c[2];
					antimuonevtnumber[numberofantimuons] = a;
					numberofantimuons++;
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
		std::cout << "=======================================================================" << std::endl;
		std::cout << "=======================================================================" << std::endl;
    		
	}
	else
	{
		std::cerr << "The file that you input is not valid" << std::endl;
		success = false;
	}	
	return success;	
}

bool pp6day2muon()
{
	//------Get the input file location
	bool success;
	std::string input;
	std::cout << " Type in the name of the file that you want to analyse with its location (e.g. \"../pp6calculator.git/observedparticles.dat\"): " << std::endl;
	input = get_string(success);	
	
	//Define variables
	int numberofmuons(0), numberofantimuons(0);
	
	//Part 1 of homework day 1 prints out mu+ and mu- properties in run4.dat
	success = count(input,numberofmuons,numberofantimuons);

	//------------Define new arrays to hold values---------------
	double muonE[numberofmuons];
	double muonpx[numberofmuons];
	double muonpy[numberofmuons];
	double muonpz[numberofmuons];
	int muonevtnumber[numberofmuons];

	double antimuonE[numberofantimuons];
	double antimuonpx[numberofantimuons];
	double antimuonpy[numberofantimuons];
	double antimuonpz[numberofantimuons];
	int antimuonevtnumber[numberofantimuons];
	//--------------------------------------------------------------
	
	// Store the Event#,energy,px,py,pz values in the newly defined variables for mu+, mu-
	success = store4momentum(input,muonE,antimuonE,muonpx,antimuonpx,muonpy,antimuonpy,muonpz,antimuonpz,muonevtnumber,antimuonevtnumber);
	
	//Define variables to hold invariant mass
	int numberofinvmass2part = (numberofantimuons*numberofmuons);
	double M2[numberofinvmass2part];
	int indexM2[numberofinvmass2part];
	

	//-----------Get Invariant mass of mu+/mu- combinations-------------------------
	for(int j = 0; j < numberofmuons; j++)
	{	
		for(int k = 0; k < numberofantimuons; k++)
		{
			M2[j*numberofantimuons+k] = InvMass2part(muonE[j], muonpx[j], muonpy[j], muonpz[j], antimuonE[k], antimuonpx[k], antimuonpy[k], antimuonpz[k]);
			indexM2[j*numberofantimuons+k] = j*numberofantimuons + k;
		}	
	}
	//-------------------------------------------------------------------------------
	
	
	//sorts the inv. mass and it's corresponding index array according to descending value.
	bubble_sort_2(M2,indexM2,numberofinvmass2part,success);
	
	//------------Results-------------------------------------
	std::cout << "The 10 largest to lowest invariant mass that we got out of mu+/mu- combinations are: " << std::endl;	
	for (int i = 0; i < 10; i++)
	{
		for(int j = 0; j < numberofmuons; j++)
		{	
			for(int k = 0; k < numberofantimuons; k++)
			{
				int x = j*numberofantimuons+k;
				if(x == indexM2[i])
				{
					std::cout<< "("<< i <<")   Invariant Mass of mu+/mu-  " << M2[i] << " the corresponding event number of mu+ is " << muonevtnumber[j] <<"  and for mu- is " << antimuonevtnumber[k] << std::endl;
					success = true;
				}
				else
				{
					continue;
				}
			}
		}
		
	}
	//------------End of Results---------------------------------
	return success;
}
