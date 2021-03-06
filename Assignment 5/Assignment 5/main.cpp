#include "stdafx.h"
#include "list.h"
#include "linear.h"
#include <iomanip>

using namespace std;

int main()
{
	//Create list objects to store values in list
	list eObject, eNew, aNew;

	//Create local variables to get user inputs and store values
	float value1, value2, value3, b0, b1;
	int count = 0;

	//Ask the user how many programs they want to get the data for 
	cout << "How many programs do you want to run through: ";
	cin >> count;
	cout << endl << endl;

	//For loop to get user input for estimated object, estimated new and changed, 
	// and actual new and changed LOC and insert into list objects
	for (int i = 1; i <= count; i++) {
		cout << "Enter in the estimated Object LOC for program " << i << ": ";
		cin >> value1;
		eObject.insert(value1, i-1);

		cout << "Enter in the estimated new and changed LOC for program " << i << ": ";
		cin >> value2;
		eNew.insert(value2, i-1);

		cout << "Enter in the actual new and changed LOC for program " << i << ": ";
		cin >> value3;
		aNew.insert(value3, i-1);

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

	//Reset the b0 and b1 values to that the values aren't carried over
	b0 = 0;
	b1 = 0;

	//Create linear objects to calculate and store b0 and b1 values
	linear regression2;
	b1 = regression2.b1Calculate(eNew, aNew, count);
	b0 = regression2.b0Calculate();

	//Output data for estimated new and changed and actual new and changed LOC for b0 and b1 values
	cout << "Estimated New and Changed LOC vs Acutal New and Changed LOC: \n";
	cout << "B0 = " << b0 << endl;
	cout << "B1 = " << b1 << endl << endl;

    return 0;
}

