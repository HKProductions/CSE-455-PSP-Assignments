#include "stdafx.h"
#include "linear.h"

linear::linear()
{
	B0 = 0;
	B1 = 0;
	xAvg = 0;
	yAvg = 0;
}

float linear::b1Calculate(list a, list b, int n)
{
	//Declare local variables to calculate top and bottom
	//seperatly, and set the averages of the two lists
	float top, bottom;
	xAvg = averageCalculate(a, n);
	yAvg = averageCalculate(b, n);

	//Calculate the top and bottom parts of the b1 equation
	top = oneTimeUse(a, b) - (n * xAvg * yAvg);
	bottom = squareSum(a) - (n * pow(xAvg, 2.0));

	//Store the final result of the top and bottom in the b1
	//variable
	B1 = top / bottom;

	return B1;
}

float linear::b0Calculate()
{
	//Calculate the b0 for the lists and store in 
	//B0 class variable
	B0 = yAvg - (B1 * xAvg);

	return B0;
}

float linear::averageCalculate(list a, int n)
{
	//Calculate average by going to list function and getting total
	//then divide by list size
	float avg = repeatSum(a) / n;

	return avg;
}

float linear::getB0()
{
	return B0;
}

float linear::getB1()
{
	return B1;
}

float linear::getxAvg()
{
	return xAvg;
}


