// File Name: Rational.h
#ifndef Rational_H
#define Rational_H
#include <iostream>
using namespace std;

// Class Rational definition
class Rational
{
public:
	// Data member for numerator and denominator
	int numerator;
	int denominator;
	// Default constructor
	Rational();
	// Input redirection operator overloaded
	friend ostream& operator<<(ostream &os, const Rational &f);
	// Output redirection operator overloaded
	friend istream& operator >> (istream &is, Rational &f);
	// Overloading + operator
	// Addition operator overloaded
	Rational operator + (Rational f);
	// Overloading - operator
	// Subtraction operator overloaded
	Rational operator - (Rational f);
	// Overloading * operator
	// Function to perform multiplication operation and return the result object
	Rational operator * (Rational f);
	// Overloading / operator
	// Function to return the object after division
	Rational operator / (Rational f);
	// Overloading > operator
	//Returns true if both numerator and denominator cross multiplication is greater
	bool operator > (Rational f);
	// Overloading < operator
	//Returns true if both numerator and denominator cross multiplication is less
	bool operator < (Rational f);
	// Overloading = operator
	// Returns the object after assignment
	bool operator == (Rational f);
	// Function to minimize
	void reduce();
};// End of class
#endif