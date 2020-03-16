
#include<iostream>
using namespace std;

int dp[101][101];
int arr[101];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}


	for (int i = 1; i <= N; i++)
	{

		for (int j = 0; j < K; j++)
		{
			int t =(dp[i - 1][j] + arr[i])%K;
			dp[i][t] = max(dp[i][t],dp[i-1][j] + arr[i]);
			dp[i][j] = max(dp[i][j],dp[i-1][j]);
		}

	}

	cout << dp[N][0]<<endl;


	return 0;
}

