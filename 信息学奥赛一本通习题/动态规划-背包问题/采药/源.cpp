
/*
01±³°üÎÊÌâ
*/

#include<iostream>
using namespace std;

struct Item
{
	int t;
	int v;
};

int dp[2000];
Item items[200];

int max(int a, int b)
{
	return a > b ? a : b;
}


int main()
{
	int T, N;
	cin >> T >> N;

	for (int i = 0; i < N; i++)
		cin >> items[i].t >> items[i].v;
	

	for (int i = 0; i < N; i++)
	{
		for (int j = T; j >= items[i].t; j--)
		{
			dp[j] = max(dp[j],dp[j - items[i].t]+items[i].v);
		}
	}


	cout << dp[T]<<endl;

	return 0;
}

