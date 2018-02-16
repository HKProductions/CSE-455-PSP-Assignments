#include <iostream>
#include "list.h"

using namespace std;

int main() {
	//Create a new list to store and manipulate numbers
	list List1;
	list List2;

	//Declare local variables
	float values, top, bottom, R;
	int position, n = 0;

	//Ask the user how many inputs they are going to enter
	cout << "How many numbers do you want to input: ";
	cin >> n;

	//Ask the user for the X inputs and store in a list
	cout << "Please enter in the X inputs \n";
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

	top = ((n * List1.oneTimeUse(List2)) - List1.repeatSum() * List2.repeatSum());
	bottom = sqrt((n * List1.squareSum() - pow(List1.repeatSum(), 2.0)) * (n * List2.squareSum() - pow(List2.repeatSum(), 2.0)));
	R = top / bottom;

	cout << endl;
	cout << "R = " << R << endl;
	cout << "R^2 = " << pow(R, 2.0) << endl;

	//Exit the program
	return 0;
}