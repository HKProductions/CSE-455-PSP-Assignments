#include "stdafx.h"
#include "list.h"
#include "linear.h"
#include "prediction.h"
#include <iomanip>

using namespace std;

int main()
{
	//Create list objects to store values in list
	list eObject, aNew;

	//Create local variables to get user inputs and store values
	float value1, value2, b0, b1, variance, range1, range2, xk, yk, l1, l2, u1, u2;
	int count = 0;

	//Ask the user how many programs they want to get the data for 
	cout << "How many programs do you want to run through: ";
	cin >> count;
	cout << endl;

	cout << "How many lines of code do you think you will write for the programs in total (xk): ";
	cin >> xk;
	cout << endl;

	//For loop to get user input for estimated object, estimated new and changed, 
	// and actual new and changed LOC and insert into list objects
	for (int i = 1; i <= count; i++) {
		cout << "Enter in the estimated Object LOC for program " << i << ": ";
		cin >> value1;
		eObject.insert(value1, i - 1);

		cout << "Enter in the actual new and changed LOC for program " << i << ": ";
		cin >> value2;
		aNew.insert(value2, i - 1);

		cout << endl;
	}

	//Create linear objects to calculate and store b0 and b1 values
	linear regression1;
	b1 = regression1.b1Calculate(eObject, aNew, count);
	b0 = regression1.b0Calculate();

	//Output data for estimated object and actual new and changed LOC for b0 and b1 values
	cout << "\nEstimated Object LOC vs Actual New and Changed LOC: \n";
	cout << "B0 = " << b0 << endl;
	cout << "B1 = " << b1 << endl;

	prediction p1;
	yk = b0 + (b1 * xk);
	variance = p1.calculateDev(eObject, aNew, b0, b1, count);
	range1 = p1.calcuateRange(eObject, xk, count, 70);
	l1 = p1.calculatePI(yk);
	u1 = p1.calculatePI(yk);
	range2 = p1.calcuateRange(eObject, xk, count, 90);
	l2 = p1.calculatePI(yk);
	u2 = p1.calculatePI(yk);

	cout << "Calcuate yk by doing this yk = b0 + (b1 * xk)\n";
	cout << "yk : " << yk << endl;

	cout << "\nThe Deviation of the program is: " << variance << endl;
	cout << "\nThe Range (70 percent) is: " << range1 << endl;
	cout << "UPI: " << u1 << " LPI: " << l1 << endl;
	cout << "\nThe Range (90 percent) is: " << range2 << endl;
	cout << "UPI: " << u2 << " LPI: " << l2 << endl << endl;

	return 0;
}

