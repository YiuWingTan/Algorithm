

#include<iostream>
using namespace std;

int dp[20001];
int arr[30];

int max(int a,int b)
{
	return a > b ? a : b;
}

int main()
{
	int V, N;
	cin >> V >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = V; j >= arr[i]; --j)
		{
			dp[j] = max(dp[j],dp[j-arr[i]]+ arr[i]);
		}
	}

	cout << V - dp[V]<<endl;

	return 0;
}
