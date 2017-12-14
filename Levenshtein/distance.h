#pragma once
#include "stdafx.h"

class Distance
{
public:
	Distance();
	~Distance();
	int computeEditDistance(string s1, string s2);
	void outputEditDistanceMatrix(string s1, string s2);
	vector<vector<int>> computeEditDistanceMatrix(string s1, string s2);
private:
	int Minimum(int a, int b, int c);
};

