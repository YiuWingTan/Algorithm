

#include<iostream>
using namespace std;


int min(int a,int b)
{
	return a > b ? b : a;
}

int max(int a,int b)
{
	return a > b ? a : b;
}

struct Item
{
	int o;
	int n;
	int w;
};

int dp[101][101];
Item items[2000];

int main()
{
	int O, N,K;
	cin >> O >> N>>K;

	for (int i = 1; i <= K; i++)
	{
		cin >> items[i].o>>items[i].n>>items[i].w;
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	
	for (int i = 1; i <= K; i++)
	{
		for (int o = O; o >= 0; --o)
		{
			for (int n = N; n >= 0; --n)
			{
				int u = o - items[i].o;
				int v = n - items[i].n;

				u = max(0,u);
				v = max(0,v);

				dp[o][n] = min(dp[o][n],dp[u][v]+items[i].w);
			}
		}
	}


	cout << dp[O][N]<<endl;
	return 0;
}


