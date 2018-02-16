#include <iostream>
#include <string>

using namespace std;

struct node
{
	float data;
	node *next;
	node *prev;
};

class doublyList {
private:
	node *head, *tail;
	int listSize;

public:
	doublyList();
	int search(float, string);
	void insert(float, int);
	void remove(int);
	void display();
};

doublyList::doublyList()
{
	head = NULL;
	listSize = 0;
}

int doublyList::search(float x, string z)
{
	node *temp = head;
	node *pre = new node();
	node *cur = new node();

	//Declare local variables
	int pos = 0;

	if (z == "delete") {
		//Go through list and see if the float exists
		if (temp == NULL) {
			return -1;
		}

		while (temp != NULL) {
			if (temp->data == x)
				return pos;

			else {
				temp = temp->next;
				pos++;
			}
		}
	}

	else if (z == "insert") {
		//Check if the linked list is empty;
		if (head == NULL)
			return 0;

		while (temp->next != NULL) {
			pre->data = temp->data;

			if (temp->data >= x)
				return pos;

			else {
				temp = temp->next;
				pos++;
			}

			cur->data = temp->data;
		}

		if ((x >= pre->data && x <= cur->data) || (pre->data == 0 || cur->data == 0))
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
	node *temp = head;
	node *Insert = new node();
	Insert->data = x;
	Insert->next = NULL;
	Insert->prev = NULL;

	listSize = listSize++;

	if (y == 0) {
		Insert->next = head;
		head = Insert;
	}

	else if (y < listSize - 1) {
		for (int i = 0; i < y - 1; i++)
			temp = temp->next;

		node *store = temp->next;
		Insert->prev = temp;
		Insert->next = store;
		temp->next = Insert;
		store->prev = Insert;
	}

	else {
		for (int i = 0; i < y - 1; i++)
			temp = temp->next;

		Insert->prev = temp;
		temp->next = Insert;
	}
}

void doublyList::remove(int y)
{
	node *Remove = head;
	node *storeNext = new node();
	node *storePrev = new node();

	listSize = listSize--;

	if (y == 0) {
		head = head->next;
		delete(Remove);
	}

	else if (y < listSize - 1) {
		for (int i = 0; i < y; i++)
			Remove = Remove->next;
		storeNext = Remove->next;
		storePrev = Remove->prev;

		storeNext->prev = storePrev;
		storePrev->next = storeNext;
		delete(Remove);
	}

	else {
		for (int i = 0; i < y; i++)
			Remove = Remove->next;

		storePrev = Remove->prev;
		storePrev->next = NULL;
		delete(Remove);
	}
}

void doublyList::display()
{
	node *temp = head;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}