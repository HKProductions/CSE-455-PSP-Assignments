#include "stdafx.h"
#include "prediction.h"
#include <vector>

prediction::prediction()
{
	
}

float prediction::calculateDev(list a, list b, float b0, float b1, int n)
{
	float variance = 0,
		part1 = 0,
		part2 = 0,
		B0 = b0,
		B1 = b1;

	part1 = 1.0 / (n - 2);
	part2 = varianceSum(a, b, B0, B1);

	variance = part1 * part2;

	deviation = sqrt(variance);

	return deviation;
}

float prediction::calcuateRange(list a, float x, int n, int s)
{
	vector <double> t1 = { 1.963, 1.386, 1.250, 1.190, 1.156, 1.134, 1.119, 1.108, 1.100, 1.093, 1.074, 1.064, 1.055, 1.036 };
	vector <double> t2 = { 6.314, 2.920, 2.353, 2.132, 2.015, 1.943, 1.895, 1.860, 1.833, 1.812, 1.753, 1.725, 1.697, 1.645 };
	float t70 = 0;
	float t90 = 0;
	float avg = getxAvg();

	if (s == 70) {
		t70 = t1[n - 2 - 1];
		T70 = t70 * deviation * sqrt(1 + (1.0 / n) + (pow(x - avg, 2.0) / rangeSum(a, avg)));
		return T70;
	}

	t90 = t2[n - 2 - 1];
	T90 = t90 * deviation * sqrt(1 + (1.0 / n) + (pow(x - avg, 2.0) / rangeSum(a, avg)));

	return T90;
}

float prediction::calculatePI(float y)
{
	if (LPI1 == NULL) {
		LPI1 = y - T70;
		return LPI1;
	}
	else if (UPI1 == NULL) {
		UPI1 = y + T70;
		return UPI1;
	}
	else if (LPI2 == NULL) {
		LPI2 = y - T90;
		return LPI2;
	}
	else
		UPI2 = y + T90;

	return UPI2;
}
