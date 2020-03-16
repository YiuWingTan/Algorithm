
#include<iostream>
using namespace std;

int arr[100][100];
int dp[100][100];

int max(int a, int b)
{
	return a > b ? a : b;
}


int main()
{

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <=N; i++)
	{
		char tmp;
		cin >> tmp;
		arr[i][i] = tmp - '0';
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = i+1; j <= N; j++)
		{
			arr[i][j] = arr[i][j - 1] * 10 + arr[j][j];
		}
	}


	for (int i = 1; i <= N; i++)
		dp[i][0] = arr[1][i];

	for (int k = 1; k <= K; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = i - 1; j > 0; j--)
			{
				dp[i][k] = max(dp[i][k],dp[j][k-1]*arr[j+1][i]);
			}
		}
	}

	cout << dp[N][K]<<endl;

	return 0;
}


