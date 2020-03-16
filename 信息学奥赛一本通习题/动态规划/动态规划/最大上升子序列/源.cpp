

#include<iostream>
using namespace std;

int dp[1000];
int a[1000];

int main()
{

	int N;
	cin >> N;


	for (int i = 0; i < N; i++)
		cin >> a[i];

	int max = 0;
	dp[0] = a[0];

	for (int i = 1; i < N; i++)
	{
		int tmp_max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j] < a[i] && tmp_max < dp[j])tmp_max = dp[j];
		}
		dp[i] = a[i] + tmp_max;
		if (max < dp[i]) max = dp[i];
	}

	cout << max << endl;

	return 0;
}
