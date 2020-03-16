#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int minPathSum(vector<vector<int>>& grid) {
	
	vector<int> dp;
	dp.resize(grid.size(),0);
	int n = grid.size();
	int left = 0;

	for (int i = 0; i < n; i++) dp[i] = grid[0][i];

	for (int i = 1; i < n; i++)
	{
		left = INT_MAX;
		for (int j = 0; j < n; j++)
		{
			if(j-1>=0)
				dp[j] = min(dp[j]+grid[i][j],left+grid[i][j]);
			else dp[j] = dp[j]+grid[i][j];
			left = dp[j];
		}
	}

	return dp[n-1];
}


int main()
{

	getchar();
	return 0;
}

