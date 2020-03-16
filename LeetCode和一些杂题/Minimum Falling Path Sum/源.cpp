#include<iostream>
#include<vector>

using namespace std;

int m[102][102];
int min(int i, int j)
{
	return i > j ? j : i;
}
int minFallingPathSum(vector<vector<int>>& A) {

	int n = A.size();

	m[0][0] = INT_MAX;
	m[0][n+1] = INT_MAX;
	for (int i = 1; i <=n; i++)
	{
		m[0][i] = A[0][i-1];
	}
	
	for (int i = 1; i < n; i++)
	{
		m[i][0] = INT_MAX;
		m[i][n+1] = INT_MAX;
		for (int j = 0; j <n; j++)
		{
			m[i][j + 1] = min(min(m[i - 1][j + 1], m[i-1][j]),m[i-1][j+2])+A[i][j];
		}
	}

	int mv = INT_MAX;
	for (int i = 0; i < n; i++)
		if (m[n-1][i + 1] < mv) mv = m[n-1][i+1];
	return mv;
}


int main()
{
	vector<vector<int>> q{ { 1,2,3 },{ 4,5,6 },{ 10,8,9 } };

	cout << "最小下降路径是:"<< minFallingPathSum(q);

	getchar();
}
