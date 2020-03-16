
#include<iostream>
using namespace std;

int arr[4] = {10,20,50,100};
int dp[1001];

int main()
{
	int N;
	cin >> N;

	dp[0] = 1;

	for (int i = 0; i < 4; i++)
	{
		for (int j = arr[i]; j<=N; ++j)
			dp[j] += dp[j - arr[i]];
	}

	cout << dp[N]<<endl;

	return 0;
}

