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
	node *head, *tail;

public:
	list();
	void insert(float, int);
	float oneTimeUse(list);
	float repeatSum();
	float squareSum();
};

#endif
