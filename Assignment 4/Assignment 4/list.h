#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct node
{
	float data;
	node *next;
};

class list {
private:
	//Stores the head of the list
	node *head;

public:
	list();
	void insert(float, int);
	float oneTimeUse(list, list);
	float repeatSum(list);
	float squareSum(list);
	float corralationFormula(list, list, int);
	float significanceFormula(list, list, int, float);
};

#endif