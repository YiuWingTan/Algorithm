
#include<iostream>
using namespace std;


int dp[2000];
int arr[50];


int main()
{
	int N, T;
	cin >> N >> T;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dp[0] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = T; j >= arr[i]; j--)
			dp[j] += dp[j-arr[i]];
	}

	cout << dp[T]<<endl;

	return 0;
}

