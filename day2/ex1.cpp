#include <iostream>
#include <cmath>
#include <limits>
#include <complex>
#include <stdlib.h>

using namespace std;

//----------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------

//---------Day 1 Basic Function--------------
double add(double a, double b)
{
	return a + b;
}
double subtract(double a, double b)
{
	return a - b;
}
double multiply(double a, double b)
{
	return a * b;
}
double divide(double a, double b)
{
	return a / b;
}	

//---------Day 1 Maths Function--------------
//------------------------------------

//-----Find intercept function---------
void intercept(double m, double c)
{
	cout << "The x-intercept of your straight line is " << -divide(c,m) << endl;
	cout << "The y-intercept of your straight line is " << c << endl;
}	

//-----Find solutions to quadratic function---------
bool quadratic(double a, double b, double c, double *solutions)
{
	//Initialize variables
	double d(0.0);
	double s1(0.0);
	double s2(0.0);
	bool real_roots = false;
	d = subtract(pow(b,2), 4*multiply(a,c)) ;

	if (d > 0 || d == 0)//for real roots
	{
		s1 = divide(subtract(-b, sqrt(d)), (2*a));	
		s2 = divide(add(-b, sqrt(d)), (2*a));
		solutions[0] = s1;//*(solutions+ 0) = s1;
		solutions[1] = s2;//*(solutions + 1) = s2;
		real_roots = true;
		
		if (d > 0) //for two distinct real roots
		{
			cout <<"Your discriminant (b^2-4ac) is "<< d <<". As it is positive, there exists 2 distinct real roots for your quadratic equation."<<endl;
			cout << "The two distinct real solutions are " << s1 << " , " << s2 << endl; 
		}
		if (d == 0) //for two equal real roots
		{
			cout <<"Your discriminant (b^2-4ac) is zero. Therefore the two real roots are equal ie. s1 = s2."<<endl;
			cout << "The solution to your quadratic equation is " << s1 << endl; 
		}
	}
	else //for two distinct complex roots
	{
		//Initialize
		double r(0.0);
		double i(0.0);
 	
		r = divide(-b, 2*a); //real factor
		i = divide(sqrt(abs(d)), 2*a); //complex factor
		
		complex<double> cs1(r, i); // cs1 = r + i(i)
		//complex<double> cs2 = conj(cs1); //cs2 = r - i(i) 
		
		cout <<"Your discriminant (b^2-4ac) is "<< d <<". As it is negative, there exists 2 distinct complex roots for your quadratic equation."<<endl;
		cout << "The two complex roots are (" << cs1.real() << ") " << " +/- (" << cs1.imag() << "i)" << endl;
	}
	return real_roots;
}	

//----------Length of 3 vectors----------
double length3vector(double x, double y, double z)
{
	double l3(0.0);
	
	l3 = sqrt((pow(x,2) + pow(y,2) + pow(z,2)));
	cout << "The length of your 3 vector is " << l3 << " relavant units" << endl;  
	return l3;
}

//---------Length of 4 vectors----------
double length4vector(double E, double px, double py, double pz)
{	
	//Initialize
	double p2(0.0);//square of magnitude of momentum
	double E2(0.0); //square of energy
	double l4(0.0);//length or invariant mass

	p2 = ((pow(px,2) + pow(py,2) + pow(pz,2)));
	E2 = (E*E);

	if(E2 > p2)
	{
		l4 = sqrt(E2-p2);
		cout << "It is a space-like interval and the length of 4 vector or Invariant mass of particle is " << l4 << " relavant units" << endl;  
	}
	else if (E2 == p2)
	{
		cout << "It is a light-like interval and the length of 4 vector or Invariant mass of particle is zero.\n";  
	}
	else
	{
		l4 = sqrt(abs(E2-p2));
		cout << "It is a time-like interval and the length of 4 vector or Invariant mass of particle is imaginary ie. " << l4 << "*i relavant units" << endl;
	}

	return l4;
}	
//---------Invariant Mass of 2 particles----------
double InvMass2part(double E1, double px1, double py1, double pz1, double E2, double px2, double py2, double pz2)
{	
	//Initialize
	double E(E1+E2);
	double px(px1+px2);
	double py(py1+py2);
	double pz(pz1+pz2);
	
	return length4vector(E, px, py, pz);
}

//---------------------------DAY 2-------------------------------------------
//-----------Day 2 Swap function
//----------------------------------------------------------------------

void swap(double &a, double &b)
{
	double temp_num;
	temp_num = a;
	a = b;
	b = temp_num;
	return;
}
//-----------Day 2 Swap function
//----------------------------------------------------------------------
void bubble_sort(double *a, int size)
{
	bool swap_performed = false;
	
	do
	{
		swap_performed = false;
		for ( int i = 0; i < size; i++)
		{	
			if (a[i] < a[i+1])
			{
				swap(a[i],a[i+1]);
				swap_performed = true;
			}
		}
	}
	while(swap_performed);
}

//----------------------------------------------------------------------
// Main Function Run by the program
//

int main() 
{
	//Declare the variables that will be used globally here
	char m('0');	

	//loop through
	while (true)
	{	
		//-----------------------------------------------------------------
		//what the user wants to do	
		cout << endl;
		cout << "Specify what you want to do by typing the number or character:" << endl;
		cout << "	If you want to find the intercept of two lines type 1 \n";
		cout << "	If you want to find the solutions to a quadratic equation type 2 \n";
		cout << "	If you want to find the length of a 3 vector type 3 \n";
		cout << "	If you want to find the length of a 4 vector or Invariant mass of a particle type 4 \n";
		cout << "	If you want to find the invariant mass of 2 particles type 5 \n";
		cout << "	If you want to perform normal operation such as subtract, add, multiply, divide type 6" << endl;
		cout << "	If you are bored and would rather watch a Ninja Cat Video, type 7" << endl;
		cout << "	If you want to swap two numbers, type 8" << endl;
		cout << "	If you want to use Bubble sort to sort your array of number, type 9" << endl;
		cout << "	If you want to quit type q" << endl;
		cout << endl;
		
		cin >> m;
		//for error in cin
		if (!cin){
			cerr << "There is an error in the type of operation you have passed in" << std::endl;
		 	cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue; //skip the looping and continues to the next looping
		}
		//------------------------------------------------------------------	

		//-----------------------------------------------------------------
		//pick what task the user has specified to do
		if(m == '1') 
		{
			double C(0.0), M(0.0); //for intercept calculation
			cout << "Type the slope (m) and intercept(c) in that order with a space b/w them from equation of line of the form y = mx+c" << endl;
			cin >> M >> C;
			intercept(M,C);
		}
		else if(m == '2')
		{
			double a(0.0), b(0.0), c(0.0); //for solutions of quadratic equation
			double solutions[2];	
			cout << "Type the co-efficients of 2nd, 1st and 0th order in x with a space b/w them in that order of a quadratic equation of the form ax^2 + bx + c = 0" << endl;
			cin >> a >> b >> c;
			quadratic(a, b, c, solutions);
			cout << "The function was successful(0) in getting the distinct real roots" << quadratic(a, b, c, solutions) << endl;
			cout << "Values are from the pointers" << solutions[0] << solutions[1] << endl;
		}
		else if(m == '3')
		{		
			double x(0.0), y(0.0), z(0.0); //for length of 3 vector
			cout << "Type the x,y,z components in that order with a space b/w them for a 3 vector" << endl;
			cin >> x >> y >> z;
			length3vector(x,y,z);
		}
		else if(m == '4')
		{
			double E(0.0), px(0.0), py(0.0), pz(0.0); //for length or inv mass of four vector
			cout <<"Type the four components either t,x,y,z or E,px,py,pz in that order with space b/w them for a 4 vector" << endl;
			cin >> E >> px >> py >> pz;
			length4vector(E,px,py,pz);
		}
		else if(m == '5')
		{
			double E1(0.0), px1(0.0), py1(0.0), pz1(0.0), E2(0.0), px2(0.0), py2(0.0), pz2(0.0);//for inv mass or 2 particles
			cout <<"Type the four components E,px,py,pz in that order with space b/w them for a Particle 1" << endl;
			cin >> E1 >> px1 >> py1 >> pz1;
			cout <<"Type the four components E,px,py,pz in that order with space b/w them for a Particle 2" << endl;
			cin >> E2 >> px2 >> py2 >> pz2;
			InvMass2part(E1,px1,py1,pz1,E2,px2,py2,pz2);
		}
		else if(m == '6')
		{
			double a(0.0),b(0.0), d(0.0);//for performing basic arithmatic functions
			char c('/');
			
			cout << "Type the numbers a and b in that order with a space in b/w to perform operations a+b,a*b,a-b,a/b" << std::endl;
			cin >> a >> b;
			
			cout << "What operation should I perform?(type symbols:*,+,-,/).If want to quit type q." << std::endl;
			cin >> c;
			//Error in input then do the below
			if (!cin)
			{
				cerr << "There is an error in the type of operation you have passed in" << std::endl;
		 		cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue; //skip the looping and continues to the next looping
			}
		
						
			//Perform the operation	
			if (c == '*') 
			{
				d = multiply(a,b);
			}
			else if ( c == '/')
			{
				if ( b == 0) 
				{
					cerr << "Error! The second number that you passed in in zero. Try a non-zero number" << std::endl;
				} 
				else 
				{
					d = divide(a,b);
				}
			} 
			else if ( c == '-') 
			{
				d = subtract(a,b);
			}
			else 
			{
				d = add(a,b);
			}
		
			cout << "The result is " << d << std::endl;
		} 	
		else if (m == 'q')
		{
			break; //breaks the loop completly and return to shell
		}
		else if (m == '7')
		{
			system("xdg-open https://www.youtube.com/watch?v=kDCXma0v-fY &");
		}
		
		else if (m == '8')
		{
			double a(0.0),b(0.0);
			cout << "Type the two numbers to be swaped, with space in b/w" << endl;
			cin >> a >> b;
			cout << "The 1st number is " << a << ". The 2nd number is" << b << endl;
			swap(a,b);
			cout << "The 1st swaped number is " << a << ". The 2nd swaped number is " << b << endl;
		}		
		else if (m == '9')
		{
			int n(0);
			cout << "Type how many numbers you want sorting" << endl;
			cin >> n;
			double a[n];

			for (int i = 0; i < n; i++)
			{	
				double b(0.0);	
				cout << "Type your " << (i+1) << " number" << endl;
				cin >> b;
				a[i] = b;
			}
			
			bubble_sort(a, n);
			
			cout << "The output of the numbers in the descending order is " << endl;
			for (int i = 0; i < n; i++)
			{	
				cout << a[i] << endl;
			}
		}
		else 
		{
			cout << "The thing that you want to do doesn't exist here, try another task" << endl;
		}
		//-----------------------------------------------------------------------
		
		cout << endl;
		cout << "Try another task that you may want to perform" << endl;
		cout << endl;
	}
		
	cout << "Please do come back and Thanks for using this pp6calculator!"<<std::endl;
	return 0;
}
