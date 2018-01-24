#include "list.h"

list::list()
{
	head = NULL;
	tail = NULL;
}

list::~list()
{
	node *next = head;

	//Go through all the linked list
	while (next) {
		node *Delete = next;
		//Get the next pointer 
		next = next->next;
		//Delete that element in the list
		delete Delete;
	}
}

int list::search(float x, string z)
{
	node *temp = new node();
	node *remove = new node();
	node *pre = new node();
	node *cur = new node();
	temp = head;

	//Declare local variables
	int pos = 0;

	//
	if(z == "delete") {
		remove = tail;
		//Go through list and see if the float exists
		if (remove == NULL) {
			return -1;
		}

		while (remove->next != NULL) {
			if (remove->data == x) {
				cout << pos << endl;
				return pos;
			}
			else {
				remove = remove->next;
				pos++;
			}
		}
	}

	else if (z == "insert") {
		//Check if the linked list is empty;
		if (temp == NULL) {
			cout << pos << endl;
			return 0;
		}

		while (temp->next != NULL) {
			pre = temp;

			if (temp->data >= x) {
				cout << pos << endl;
				return pos;
			}
			else if (temp->data < x) {
				temp = temp->next;
				pos++;
			}

			cur = temp;
		}
		cout << "Pre: " << pre->data << endl;
		cout << "Cur: " << cur->data << endl;

		if (x >= pre->data || x <= cur->data) {
			cout << pos << endl;
			return pos;
		}
		else {
			pos++;
			cout << pos << endl;
			return pos;
		}
	}

	return -1;
}

void list::insert(float x, int y)
{
	node *Insert = new node();
	Insert->data = x;
	Insert->next = NULL;

	if (y == 0) {
		Insert->next = head;
		head = Insert;
		tail = head;
	}

	else {
		node *temp = head;
		for (int i = 0; i < y - 1; i++) {
			temp = temp->next;
		}

		Insert->next = temp->next;
		temp->next = Insert;
		tail = temp;
	}
}

void list::remove(int y)
{
	cout << "Trying to delete number\n";
	node *Remove = new node();
	Remove = tail;
	
	if (y == 0) {
		Remove = Remove->next;
	}

	else {
		for (int i = 0; i < y - 1; i++)
			Remove = Remove->next;

		node *temp = new node();
		temp = Remove->next;
		Remove->next = temp->next;
	}
}

void list::display()
{
	if (head != NULL) {
		while (head != NULL) {
			cout << head->data << endl;
			head = head->next;
		}
	}

	else {
		while (tail != NULL) {
			cout << tail->data << endl;
			tail = tail->next;
		}
	}
}
