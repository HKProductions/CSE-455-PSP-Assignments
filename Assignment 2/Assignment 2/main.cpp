// Assignment 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lineCounter.h"


int main()
{
	lineCounter lineCount("list.cpp");
	lineCount.ObjectsAndFunctions();
	lineCount.LOC();
	lineCount.print();

	cout << endl << endl;

	lineCounter lineCount2("doublyList.cpp");
	lineCount2.ObjectsAndFunctions();
	lineCount2.LOC();
	lineCount2.print();

    return 0;
}

