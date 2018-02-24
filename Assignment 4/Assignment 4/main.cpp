// Assignment 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "list.h"
#include <iomanip>

using namespace std;

int main() {
	//Create a new list to store and manipulate numbers
	list List1;
	list List2;
	list List3;

	//Declare local variables
	float values, top, bottom, R, T;
	int position, n = 0;

	//Ask the user how many inputs they are going to enter
	cout << "How many numbers do you want to input: ";
	cin >> n;

	//Ask the user for the X inputs and store in a list
	cout << "\nPlease enter in the X inputs \n";
	for (int i = 0; i < n; i++) {
		cin >> values;
		List1.insert(values, i);
	}

	//Reset the values so that way numbers aren't transfered over
	cout << endl;
	values = 0;

	//Ask the user for the Y inputs and store in a list
	cout << "Please enter in the Y inputs \n";
	for (int i = 0; i < n; i++) {
		cin >> values;
		List2.insert(values, i);
	}

	//Calculate corralation between List1 and List2
	R = List3.corralationFormula(List1, List2, n);

	//Output the corralation formula data
	cout << "\nCorrelation Formula Output: \n";
	cout << setprecision(3) << "R = " << R << endl;
	cout << setprecision(3) << "R^2 = " << pow(R, 2.0) << endl;

	//Calculate significe between List1 and List2
	T = List3.significanceFormula(List1, List2, n, R);

	//Output the significane formula data
	cout << "\nSignificance Formula Output: \n";
	cout << setprecision(3) << "T = " << T << endl;

	//Exit the program
	return 0;
}

