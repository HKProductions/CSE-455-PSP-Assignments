#include "doublyList.h"

doublyList::doublyList()
{
	head = NULL;
	tail = NULL;
}

doublyList::~doublyList()
{
}

int doublyList::search(float x, string z)
{
	node *temp = new node();
	node *remove = new node();
	node *cur = new node();
	temp = head;

	//Declare local variables
	int pos = 0;

	//
	if (z == "delete") {
		remove = tail;
		//Go through list and see if the float exists
		if (remove == NULL) {
			return -1;
		}

		while (remove->next != NULL) {
			if (remove->data == x)
				return pos;

			else {
				remove = remove->next;
				pos++;
			}
		}
	}

	else if (z == "insert") {
		//Check if the linked list is empty;
		if (head == NULL)
			return 0;


		while (temp->next != NULL) {
			prev->data = temp->data;

			if (temp->data >= x)
				return pos;

			else {
				temp = temp->next;
				pos++;
			}

			cur->data = temp->data;
		}

		if ((x >= prev->data && x <= cur->data) || (prev->data == 0 || cur->data == 0))
			return pos;

		else {
			pos++;
			return pos;
		}
	}

	return -1;
}

void doublyList::insert(float x, int y)
{
	node *Insert = new node();
	Insert->data = x;
	Insert->next = NULL;
	Insert->prev = NULL;

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

void doublyList::remove(int y)
{
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

void doublyList::display()
{
	if (head != NULL) {
		cout << "\n Printing linked list after sorting insertions \n";
		while (head != NULL) {
			cout << head->data << endl;
			head = head->next;
		}
	}

	else {
		cout << "\n Printing linked list after deletions \n";
		while (tail != NULL) {
			cout << tail->data << endl;
			tail = tail->next;
		}
	}
}
