#include "stdafx.h"
#include "distance.h"


Distance::Distance() {}
Distance::~Distance() {}

int Distance::Minimum(int a, int b, int c) {
	int x;

	x = a;
	if (b < x)
		x = b;
	if (c < x)
		x = c;

	return x;
}


vector<vector<int>> Distance::computeEditDistanceMatrix(string s1, string s2) {
	int n = 0, m = 0, i, j, cost;
	char s1_i, s2_j;

	//step 1
	//getting the length of the strings
	n = s1.size();
	m = s2.size();


	int a = n + 1;
	int b = m + 1;

	vector<vector<int>> matrix((a), vector<int>(b));


	//step 2
	//initializing the first column to 0...b
	for (i = 0; i < b; i++) {
		matrix[0][i] = i;
	}
	//initializing the first row to 0...a
	for (j = 0; j < a; j++) {
		matrix[j][0] = j;
	}

	//Step 3
	//Examine each character of s (i from 1 to ).
	for (i = 1; i < a; i++) {
		s1_i = s1.at(i - 1);

		//step 4
		//	Examine each character of s2 (j from 1 to b).
		for (j = 1; j < b; j++) {
			s2_j = s2.at(j - 1);

			//step 5
			/*
				If s1[i] equals s2[j], the cost is 0.
				If s1[i] doesn't equal s2[j], the cost is 1.
			*/
			if (s1_i == s2_j) {
				cost = 0;
			}
			else {
				cost = 1;
			}

			//step 6
			/*
				Set cell matrix[i,j] of the matrix equal to the minimum of:
				a. The cell immediately above plus 1: matrix[i-1,j] + 1.
				b. The cell immediately to the left plus 1: matrix[i,j-1] + 1.
				c. The cell diagonally above and to the left plus the cost: matrix[i-1,j-1] + cost.
			*/
			matrix[i][j] = Minimum(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);

		}
	}
	return matrix;
}

int Distance::computeEditDistance(string s1, string s2) {

	int n = 0, m = 0;

	//step 1
	/*
		Set n to be the length of s1.
		Set m to be the length of s2.
		If n = 0, return m and exit.
		If m = 0, return n and exit.
		Construct a matrix containing 0..m rows and 0..n columns.
	*/
	n = s1.size();
	m = s2.size();
	if (n == 0)
		return m;
	if (m == 0)
		return n;

	vector<vector<int>> matrix = computeEditDistanceMatrix(s1, s2);
	//step 7
	//returning the distance which is found in cell matrix[n,m].
	return matrix[n][m];
}

void Distance::outputEditDistanceMatrix(string s1, string s2) {
	int n, m;
	n = s1.size() + 1;
	m = s2.size() + 1;


	vector<vector<int>> matrix = computeEditDistanceMatrix(s1, s2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
