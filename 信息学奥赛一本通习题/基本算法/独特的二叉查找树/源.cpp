#include<iostream>
#include<vector>

using namespace std;

//解法卡特兰数 -------------------动态规划

int numTrees(int n) {
	
	static vector<int> dp = {1,1,2,5};

	if (n < dp.size()) return dp[n];


	for (int k = dp.size(); k <= n; k++)
	{
		for (int i = 0; i < k; i++)
		{
			dp[k] = dp[i]*dp[k - i-1];
		}
	}
	
	return dp[n];
}




