#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
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
	~list();
	int search(float, string);
	void insert(float, int);
	void remove(int);
	void display();
};

#endif
