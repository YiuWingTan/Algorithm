#include<iostream>
#include<vector>


using namespace std;

int minFallingPathSum(vector<vector<int>>& A) {

	int n = A.size();

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int best = A[i-1][j];

			if (j - 1 >= 0 && best > A[i-1][j - 1]) best = A[i-1][j-1];
			if (j + 1 < n&&A[i-1][j + 1] < best) best = A[i-1][j+1];

			A[i][j] += best;
		}
	}

	int min = INT_MAX;
	for (int j = 0; j < n&&n-1>=0; j++)
	{
		if (min > A[n - 1][j]) min = A[n-1][j];
	}
	return min;

}


