///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name:
// Student No:
// Date: 
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

// ***** QUESTION 3 ******
// Question 3 has 3 parts
// 3.1 Using the MINIMAL "Fraction" class provided, overload the greater than operator to work with
//     objects of class Fraction as a NON-MEMBER FUNCTION.   You may modify the Fraction class to 
//     demonstrate friendship.  DO NOT USE FLOATING POINT MATH!!!
// 3.2 Overload two functions called "add" which take two arguements, an integer and a fraction (in 
//     either order) and return a fraction.  
// 3.3 create a driver program to test your overloaded > operators and your overloaded 

class Fraction {
private:
	int num;				// numerator;
	int denom;				// denominator;
public:
	Fraction(int n, int d) : num(n), denom(d) { };
	void print() { cout << num << "/" << denom; };
	friend bool operator>(Fraction Y, Fraction Z);
	friend Fraction ADD(const int, const Fraction);
	friend Fraction ADD(const Fraction, const int);
};

bool operator>(Fraction Y, Fraction Z)
{
	if ((Y.num - Y.denom) > (Z.num - Z.denom))
		return true;
	else
		return false;
}

Fraction ADD(const int Y, const Fraction Z)
{
	Fraction X((Z.denom*Y + Z.num), (Z.denom));
	
	return X;
}

Fraction ADD(const Fraction Z, const int Y)
{
	Fraction X((Z.denom*Y + Z.num), (Z.denom));

	return X;
}

int main()
{
	Fraction Fr1(1, 3);
	Fraction Fr2(4, 3);
	int Z = 2;

	if (Fr2 > Fr1)
		cout << "Fr2=4/3 is more than Fr1=1/3" << endl;
	else
		cout << "Fr2=4/3 is not more than Fr1=1/3" << endl;

	cout << "using the first addition function the answer is ";
	ADD(Z, Fr1).print();
	cout << "\nAfter swapping arguments the answer is still ";
	ADD(Fr1, Z).print();


}