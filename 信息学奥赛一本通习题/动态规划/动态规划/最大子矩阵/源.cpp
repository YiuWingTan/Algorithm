
#include<iostream>

using namespace std;

int dp[101][101];

int main()
{
	int N,tmp;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			dp[i][j] = tmp + dp[i - 1][j];
		}
	}

	int max = -99999,tmp_sum = 0;
	for (int k = 0; k <= N; k++)
	{
		
		for (int i = k+1; i <=N; i++)
		{
			tmp_sum = 0;
			for (int j = 0; j < N; j++)
			{
				tmp_sum += dp[i][j] - dp[k][j];
				if (tmp_sum > max) max = tmp_sum;
				if (tmp_sum < 0) tmp_sum = 0;
			}
		}
	}

	cout << max << endl;

	return 0;
}


