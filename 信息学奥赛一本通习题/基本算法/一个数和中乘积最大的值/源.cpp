#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> dp(59,0);

int integerBreak(int n) {

	//��̬�滮 - dp[i]��ʾ����ǰ�����ֵ

	dp[0] = 0;
	dp[1] = 1;
	

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i - 1; j++)
		{
			//Ѱ�����ֵ
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



