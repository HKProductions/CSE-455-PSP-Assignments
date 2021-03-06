#pragma once
#ifndef SIGNIFICANCE_H
#define SIGNIFICANCE_H

#include <iostream>
#include <vector>

using namespace std;

class significance {
private:
	float R;
	float T;
	int N;
	vector<double> value = { 0.60, 0.70, 0.85, 0.90, 0.95, 0.975, 0.99, 0.995 };
	vector<vector<double>> tTable = {
		{0.325, 0.727, 1.963, 3.078, 6.314, 12.706, 31.821, 63.657},
		{0.289, 0.617, 1.386, 1.886, 2.920, 4.303, 6.965, 9.925},
		{0.277, 0.587, 1.250, 1.638, 2.353, 3.182, 4.541, 5.841},
		{0.271, 0.569, 1.190, 1.533, 2.132, 2.776, 3.747, 4.604},
		{0.267, 0.559, 1.156, 1.476, 2.015, 2.571, 3.365, 4.032},
		{0.263, 0.549, 1.119, 1.415, 1.895, 2.365, 2.998, 3.499},
		{0.262, 0.546, 1.108, 1.397, 1.860, 2.306, 2.896, 3.355},
		{0.261, 0.543, 1.100, 1.383, 1.833, 2.262, 2.821, 3.250},
		{0.260, 0.542, 1.093, 1.372, 1.812, 2.228, 2.764, 3.169},
		{0.258, 0.536, 1.074, 1.341, 1.753, 2.131, 2.602, 2.947},
		{0.257, 0.533, 1.064, 1.325, 1.725, 2.086, 2.528, 2.845},
		{0.256, 0.530, 1.055, 1.310, 1.697, 2.042, 2.457, 2.750},
		{0.253, 0.524, 1.036, 1.282, 1.645, 1.960, 2.326, 2.576}
	};
public:
	significance();
	significance(float, int);
	bool checkR();
	float significanceFormula();
	double findMaxT();
};

#endif
