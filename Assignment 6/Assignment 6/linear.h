#pragma once
#ifndef LINEAR_H
#define LINEAR_H

#include "list.h"

class linear : public list {
protected:
	float B0, B1, xAvg, yAvg;

public:
	linear();
	float b1Calculate(list, list, int);
	float b0Calculate();
	float averageCalculate(list, int);
	float getB0();
	float getB1();
	float getxAvg();
};

#endif 