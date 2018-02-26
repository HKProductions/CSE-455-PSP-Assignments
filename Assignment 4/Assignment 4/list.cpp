#include "stdafx.h"
#include "list.h"

list::list()
{
	head = NULL;
}

void list::insert(float x, int y)
{
	node *Insert = new node();
	Insert->data = x;
	Insert->next = NULL;

	if (y == 0) {
		Insert->next = head;
		head = Insert;
	}

	else {
		node *temp = head;
		for (int i = 0; i < y - 1; i++) {
			temp = temp->next;
		}

		Insert->next = temp->next;
		temp->next = Insert;
	}
}

float list::oneTimeUse(list a, list b)
{
	node *temp1 = a.head;
	node *temp2 = b.head;
	float result = 0;

	while (temp1 != NULL && temp2 != NULL) {
		result = result + (temp1->data * temp2->data);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return result;
}

float list::repeatSum(list a)
{
	node *temp = a.head;
	float result = 0;

	while (temp != NULL) {
		result += temp->data;
		temp = temp->next;
	}

	return result;
}

float list::squareSum(list a)
{
	node *temp = a.head;
	float result = 0;

	while (temp != NULL) {
		result += pow(temp->data, 2.0);
		temp = temp->next;
	}

	return result;
}

float list::corralationFormula(list a, list b, int n) {
	float top, bottom, R;

	top = ((n * oneTimeUse(a, b)) - repeatSum(a) * repeatSum(b));
	bottom = sqrt((n * squareSum(a) - pow(repeatSum(a), 2.0)) * (n * squareSum(b) - pow(repeatSum(b), 2.0)));
	R = top / bottom;

	return R;
}

float list::significanceFormula(list a, list b, int n)
{
	float top, bottom, T, R;

	R = corralationFormula(a, b, n);

	if (R > 0.7) {
		top = (abs(R)) * (sqrt(n - 2));
		bottom = sqrtf(1 - pow(R, 2.0));
		T = top / bottom;

		return T;
	}

	return 0;
}
