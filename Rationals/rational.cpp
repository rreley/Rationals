#include "Rational.h"
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;


// Default constructor
Rational::Rational()
{
	numerator = denominator = 1;
}// End of default constructor

// Input redirection operator overloaded
ostream& operator<<(ostream &os, const Rational &f)
{
	// Stores numerator, operator symbol (/) and denominator in os stream
	os << f.numerator << " / " << f.denominator;
	// Returns output stream
	return os;
}// End of function

// Output redirection operator overloaded
istream& operator >> (istream &is, Rational &f)
{
	// To store symbol
	char ch;
	// Stores numerator in is stream
	is >> f.numerator;
	// To discard fraction symbol
	is >> ch;
	// Stores denominator in is stream
	is >> f.denominator;
	// Returns input stream
	return is;
}// End of function

// Overloading + operator
// Addition operator overloaded
Rational Rational::operator + (Rational f)
{
	// Creates a temporary object of Rational class
	Rational t;
	// Multiplies the implicit object numerator with parameter object denominator
	// and multiplies the parameter object numerator with implicit object denominator
	// Add both the result and store it in the temporary object numerator
	t.numerator = numerator * f.denominator + f.numerator * denominator;
	// Multiply implicit object denominator with parameter object denominator and store it in the temporary object denominator
	t.denominator = denominator * f.denominator;
	// Return the result object
	return t;
}// End of function

// Overloading - operator
// Subtraction operator overloaded
Rational Rational::operator - (Rational f)
{
	// Creates a temporary object of Rational class
	Rational t;
	// Multiplies the implicit object numerator with parameter object denominator
	// and multiplies the parameter object numerator with implicit object denominator
	// Subtracts both the result and store it in the temporary object numerator
	t.numerator = numerator * f.denominator - f.numerator * denominator;
	// Multiply implicit object denominator with parameter object denominator and store it in the temporary object denominator
	t.denominator = denominator * f.denominator;
	// Return the result object
	return t;
}// End of function

// Overloading * operator
// Function to perform multiplication operation and return the result object
Rational Rational::operator * (Rational f)
{
	// Creates a temporary object of Rational class
	Rational t;
	// Multiplies the implicit object numerator with parameter object denominator and stores it in temporary object numerator
	t.numerator = numerator * f.numerator;
	// Multiply implicit object denominator with parameter object denominator and store it in the temporary object denominator
	t.denominator = denominator * f.denominator;
	// Return the result object
	return t;
}// End of function

// Overloading / operator
// Function to return the object after division
Rational Rational::operator / (Rational f)
{
	// Creates a temporary object of Rational class
	Rational t;
	// Checks for divide by zero error
	if (f.denominator == 0 || denominator == 0)
	{
		cout << "\n Cannot divide by zero";
		exit(0);
	}// End of if condition
	// Otherwise denominator is not zero
	else
	{
		// Multiply implicit object numerator with parameter object denominator and store it in the temporary object numerator
		t.numerator = numerator * f.denominator;
		// Multiply parameter object numerator with implicit object denominator and store it in the temporary object denominator
		t.denominator = f.numerator * denominator;
		// Return the result object
		return t;
	}// End of else
}// End of function

// Overloading > operator
// Returns true if both numerator and denominator cross multiplication is greater
bool Rational::operator > (Rational f)
{
	return (numerator * f.denominator > denominator * f.numerator);
}// End of function

// Overloading < operator
// Returns true if both numerator and denominator cross multiplication is less
bool Rational::operator < (Rational f)
{
	return (numerator * f.denominator < denominator * f.numerator);
}// End of function

// Overloading = operator
// Returns the object after assignment
bool Rational::operator == (Rational f)
{
	if ((numerator == f.numerator) && (denominator == f.denominator))
		return true;
	else
		return false;
}// End of function

// Function to minimize
void Rational::reduce()
{
	// Loops from 2 to denominator value
	for (int x = 2; x < denominator; x++)
	{
		// Checks if x is divisible by both numerator and denominator
		if ((numerator % x == 0) && (denominator % x == 0))
		{
			// Divide numerator by x and store the quotient in numerator
			numerator = numerator / x;
			// Divide denominator by x and store the quotient in denominator
			denominator = denominator / x;
		}// End of if condition
	}// End of for loop
	// Displays the result
	cout << numerator << "/" << denominator;
}// End of function

// Displays the menu for Operator
void selectOperator()
{
	cout << "\n + for Addition \n - for Subtraction \n * for Multiplication \n / for Division \
\n > - for greater than \n < for less than \n == for check equals \n $ - for exit.";
}// End of function

// Main method
int main()
{
	// To store operator symbol
	string operatorSymbol;
	// Creates two Rational class object
	Rational f1, f2;
	// Creates an object to store result
	Rational t;

	// Loops till operator symbol is not "$"
	do
	{
		// Displays the menu for operator symbol
		selectOperator();

		// Accepts the symbol
		cout << "\n Enter the expression symbol: ";
		cin >> operatorSymbol;

		// Checks if operator symbol is "$" exit the program
		if (operatorSymbol == "$")
			exit(0);
		cout << "\n Example First fraction 2/3 + second fraction 3/2\n";

		// Accepts first fraction
		cout << "Enter an First Fraction: ";
		cin >> f1;

		// Accepts second fraction
		cout << "\n Enter an Second Fraction: ";
		cin >> f2;

		// Checks if the operator symbol is "+"
		if (operatorSymbol == "+")
		{
			// Overloads the + operator to perform addition and store the result in t
			t = f1 + f2;
			// Displays the result
			cout << f1 << " " << operatorSymbol << " " << f2 << " = " << t;
			// Calls the function to reduce the fraction
			cout << "\n Reduced Fraction -> ";
			t.reduce();
		}// End of if condition

		// Otherwise checks if the operator symbol is "-"
		else if (operatorSymbol == "-")
		{
			// Overloads the - operator to perform subtraction and store the result in t
			t = f1 - f2;
			// Displays the result
			cout << f1 << " " << operatorSymbol << " " << f2 << " = " << t;
			// Calls the function to reduce the fraction
			cout << "\n Reduced Fraction -> ";
			t.reduce();
		}// End of if condition

		// Otherwise checks if the operator symbol is "*"
		else if (operatorSymbol == "*")
		{
			// Overloads the * operator to perform multiplication and store the result in t
			t = f1 * f2;
			// Displays the result
			cout << f1 << " " << operatorSymbol << " " << f2 << " = " << t;
			// Calls the function to reduce the fraction
			cout << "\n Reduced Fraction -> ";
			t.reduce();
		}// End of if condition

		// Otherwise checks if the operator symbol is "/"
		else if (operatorSymbol == "/")
		{
			// Overloads the / operator to perform division and store the result in t
			t = f1 / f2;
			// Displays the result
			cout << f1 << " " << operatorSymbol << " " << f2 << " = " << t;
			// Calls the function to reduce the fraction
			cout << "\n Reduced Fraction -> ";
			t.reduce();
		}// End of if condition

		// Otherwise checks if the operator symbol is ">"
		else if (operatorSymbol == ">")
		{
			// Overloads the > operator to check if object f1 is greater than f2
			if (f1 > f2)
				// If true display the result
				cout << "\n " << f1 << " is greater than " << f2;
			// Otherwise f1 is not greater than f2
			else
				// If false display the result
				cout << "\n " << f2 << " is greater than " << f1;
		}// End of if condition

		// Otherwise checks if the operator symbol is "<"
		else if (operatorSymbol == "<")
		{
			// Overloads the < operator to check if object f1 is less than f2
			if (f1 < f2)
				// If true display the result
				cout << "\n " << f1 << " is smaller than " << f2;
			// Otherwise f1 is not less than f2
			else
				// If false display the result
				cout << "\n " << f2 << " is smaller than " << f1;
		}// End of if condition

		// Otherwise checks if the operator symbol is "=="
		else if (operatorSymbol == "==")
		{
			// Overloads the == operator to check if object f1 is equals to f2
			if (f1 == f2)
				// If true display the result
				cout << f1 << " is equals to " << f2;
			// Otherwise f1 is not equals to f2
			else
				// If false display the result
				cout << f1 << " is not to " << f2;
		}// End of if condition

		// Otherwise display invalid symbol
		else
			cout << "\n Invalid symbol";
	} while (1); // End of do while
}//End of main
