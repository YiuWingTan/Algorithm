
#include<iostream>

using namespace std;

int dp[101][101];
int arr[101];
int s[101];
int min(int a,int b)
{
	return a > b ? b : a;
}


int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		s[i] = s[i - 1] + arr[i];
	}
	
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			dp[i][j] = 0x3f3f3f3f;
		}
	}

	for (int i = 1; i <= N; i++) dp[i][i] = 0;

	for (int i = N-1; i > 0; i--)
	{
		for (int j = i + 1; j <= N; j++)
		{
			for (int k = i; k <j; k++)
			{
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j] - s[i-1]);
			}
		}
	}

	cout << dp[1][N]<<endl;


	return 0;
}

