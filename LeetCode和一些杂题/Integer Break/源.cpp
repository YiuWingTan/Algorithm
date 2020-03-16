#include<iostream>
#include<vector>
using namespace std;

int dp[59];
int max(int i, int j)
{
	return i > j ? i : j;
}
int integerBreak(int n)
{
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i;j++)
		{
			dp[i] = max(dp[i], dp[i - j] * j);
			dp[i] = max(dp[i],(i-j)*j);
		}
	}
	
	return dp[n];
}

int main()
{
	int target = 58;
	cout << "能组成的最大乘积是" << integerBreak(target);
	getchar();
}