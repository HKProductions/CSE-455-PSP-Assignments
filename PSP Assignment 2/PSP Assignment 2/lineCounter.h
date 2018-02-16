#pragma once
#ifndef LINECOUNTER_H
#define LINEcOUNTER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class lineCounter
{
private:
	int status;
	int length;
	ifstream input;
	string fileName;
	vector <string> objectName;
	vector <int> functionCount;
	vector <int> objectCount;
	bool ignore(string a);
	string getClassName(string name);

public:
	lineCounter(string fileName);
	void ObjectsAndFunctions();
	void LOC();
	void print();
};

#endif 

