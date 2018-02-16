#include "list.h"

list::list()
{
	head = NULL;
	tail = NULL;
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

float list::oneTimeUse(list a)
{
	node *temp1 = head;
	node *temp2 = a.head;
	float result = 0;

	while (temp1 != NULL && temp2 != NULL) {
		result = result + (temp1->data * temp2->data);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return result;
}

float list::repeatSum()
{
	node *temp = head;
	float result = 0;

	while (temp != NULL) {
		result += temp->data;
		temp = temp->next;
	}

	return result;
}

float list::squareSum()
{
	node *temp = head;
	float result = 0;

	while (temp != NULL) {
		result += pow(temp->data, 2.0);
		temp = temp->next;
	}

	return result;
}
