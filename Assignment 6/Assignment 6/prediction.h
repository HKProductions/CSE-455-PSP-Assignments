#pragma once
#ifndef PREDICTION_H
#define PREDICTION_H

#include "linear.h"

class prediction : public linear {
private:
	float deviation, T70, T90, LPI1, UPI1, LPI2, UPI2;
public:
	prediction();
	float calculateDev(list, list, float, float, int);
	float calcuateRange(list, float, int, int);
	float calculatePI(float);
};

#endif 