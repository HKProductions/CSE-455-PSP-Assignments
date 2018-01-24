#include <iostream>
#include <string>
#include "list.h"

using namespace std;

int main() {
	//Create a new list to store and manipulate numbers
	list List;

	//Declare local variables
	float values;
	int position, count = 0;

	//Do a do while loop so that way the program runs as long as the user wants
	for (int i = 0; i < 10; i++) {
		//Get the users input for variables
		cin >> values;

		//Get the position of where to insert value
		position = List.search(values, "insert");

		//Insert the value at that position
		List.insert(values, position);
	}

	//Display the current list
	cout << endl;
	List.display();

	values = 0;

	for (int i = 0; i < 2; i++) {
		//Ask the user what variable they want to remove from the list
		cout << endl;
		cout << "Enter in a variable that you want to remove from the list: ";
		cin >> values;

		do {
			//Search the list and see if the variable is inside the list
			position = List.search(values, "delete");

			//Error message if the number entered is not in the linked list
			if (position < 0 && count == 0)
				cout << values << " is not found in the list.\n";

			//Don't want an error message to be displayed if the number is not in the linked list
			//and function is being run again to remove any extra copies of the number
			else if (position < 0 && count > 0)
				continue;

			else {
				//Delete that value formt he list by going to that position
				List.remove(position);
				cout << "Deletion Successful!\n";
			}
			//Used to keep track of how many times the do while loop is ran 
			count++;
		} while (position != -1);

		//reset the count so the do while loop works properly
		count = 0;
	}

	//Display the new list
	cout << endl;
	List.display();

	//Exit the program
	return 0;
}