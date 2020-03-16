#include<iostream>
#include<vector>

using namespace std;

int dp[10];

int countNumbersWithUniqueDigits(int n) {

	dp[0] = 1;
	dp[1] = 10;
	for (int i = 2; i <= n; i++)
	{
		int m = 9;
		for (int j = 1; j <i; j++)
		{
			m *= 10 - j;
		}
		dp[i] = dp[i-1]+m;
	}
	return dp[n];
}

int main()
{
	cout << "´ð°¸ÊÇ"<< countNumbersWithUniqueDigits(4);

	getchar();
}