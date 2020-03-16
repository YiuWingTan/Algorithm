#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> dp(59,0);

int integerBreak(int n) {

	//动态规划 - dp[i]表示到当前的最大值

	dp[0] = 0;
	dp[1] = 1;
	

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i - 1; j++)
		{
			//寻找最大值
			if (dp[i] < dp[i - j] * j) dp[i] = dp[i - j] * j;
			if (dp[i] < (i - j)*j) dp[i] = (i - j)*j;
		}
	}
	return dp[n];
}

int main()
{
	cout << integerBreak(58);

	getchar();
	return 0;
}



