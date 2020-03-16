
#include<iostream>
using namespace std;



struct Item
{
	int n;
	int d;
};

int dp[1001][1000];

Item items[100];

int max(int a,int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int N,H,K;
	cin >> N >> H >> K;

	for (int i = 0; i < K; i++)
		cin >> items[i].n >> items[i].d;



	for (int i = 0; i < K; i++)
	{
		for (int j = N; j >=items[i].n; j--)
		{
			for (int h = H; h >= items[i].d; h--)
			{
				dp[j][h] = max(dp[j][h],dp[j - items[i].n][h - items[i].d]+1);
				
			}
		}
	}

	int maxn=0, maxh = 0;

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= H; j++)
		{
			if (maxn < dp[i][j])
			{
				maxn = dp[i][j];
				maxh = H -j;
			}
			else if (maxn == dp[i][j])
			{
				maxh = max(maxh,H- j);
			}
				
		}
	}

	cout << maxn << " "<<maxh<<endl;

	return 0;
}

