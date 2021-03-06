#include "stdafx.h"
#include "list.h"
#include "significance.h"
#include <iomanip>

using namespace std;

int main() {
	//Create a new list to store and manipulate numbers
	list List1;
	list List2;
	list List3;

	//Declare local variables
	float values, R, T;
	double p;
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

	//Calculate significe and t Distribution between List1 and List2
	significance sig(R, n);
	T = sig.significanceFormula();
	p = sig.findMaxT();

	//Output the significane formula data
	cout << "\nSignificance Formula Output: \n";
	cout << setprecision(3) << "T = " << T << endl;

	//Output the t Table data
	cout << "\nP value output: \n";
	if (p == -1)
		cout << "Unable to find p value\n";
	else {
		cout << "p = " << p << endl;
		cout << "2(1-p) = " << 2 * (1 - p) << endl << endl;
	}

	//Exit the program
	return 0;
}

