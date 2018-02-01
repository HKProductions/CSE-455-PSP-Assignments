#pragma once
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

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

public:
	doublyList();
	~doublyList();
	int search(float, string);
	void insert(float, int);
	void remove(int);
	void display();
};

#endif