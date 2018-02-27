#include "stdafx.h"
#include "significance.h"

significance::significance()
{
	R = 0;
	T = 0;
	N = 0;
}

significance::significance(float r, int n)
{
	R = r;
	N = n;
	T = 0;
}

bool significance::checkR()
{
	if (R > 0.7)
		return true;

	return false;
}

float significance::significanceFormula()
{
	if (!checkR())
		return 0;

	float top = (abs(R)) * (sqrt(N - 2));
	float bottom = sqrtf(1 - pow(R, 2.0));
	T = top / bottom;

	return T;
}

double significance::findMaxT()
{
	int min = -1, max = -1;

	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			if (min == -1 && max == -1 && tTable[i][j] >= T) {
				min = j;
			}
			else if (min != -1 && max == -1 && tTable[i][j] >= R)
				max = j;
		}

		if (min >= 0 && max >= 0) 
			return value[max];
		else {
			min = -1;
			max = -1;
		}
	}
	return -1;
}
