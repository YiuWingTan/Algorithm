
/*
考虑两个人同时走

*/

#include<iostream>
using namespace std;




int arr[11][11];
int dp[11][11][11][11];

int max(int a,int b)
{
	return a > b ? a : b;
}


int main()
{
	int N;
	cin >> N;

	int i, j, k;

	while (cin >> i >> j >> k)
	{
		if (i == 0 && j == 0 && k == 0) break;
		arr[i][j] = k;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int h = 1; h <= N; h++)
			{
				for (int k = 1; k <= N; k++)
				{
					int tmp1 = max(dp[i-1][j][h-1][k],dp[i][j-1][h][k-1]);
					int tmp2 = max(dp[i-1][j][h][k-1],dp[i][j-1][h-1][k]);

					dp[i][j][h][k] = max(tmp1,tmp2);

					if (i == h && j == k)
					{
						//当两个人都到达同一个位置的时候
						dp[i][j][h][k] += arr[i][j];
					}
					else
					{
						dp[i][j][h][k] += arr[i][j] + arr[h][k];
					}
				}
			}
		}
	}

	cout << dp[N][N][N][N]<<endl;

	
	return 0;
}






