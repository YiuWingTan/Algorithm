#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void set()
{

}

void setZeroes(vector<vector<int>>& matrix) {
	if (matrix.size() == 0) return;
	vector<int> rows;
	vector<int> cols;
	
	int m = matrix.size();
	int n = matrix[0].size();

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (matrix[i][j] == 0) { rows.push_back(i); break; }

	for (int j = 0; j < n; j++)
		for (int i = 0; i < m; i++)
			if (matrix[i][j] == 0) { cols.push_back(j); break; }

	
	
}


int main()
{


	getchar();
	return 0;
}