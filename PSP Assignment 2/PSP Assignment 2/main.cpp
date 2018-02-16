#include "lineCounter.h"


int main()
{
	lineCounter lineCount("list.cpp");
	lineCount.ObjectsAndFunctions();
	lineCount.LOC();
	lineCount.print();
}