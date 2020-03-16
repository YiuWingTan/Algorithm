
#include<iostream>
using namespace std;

struct Item
{
	int v;
	int w;
};

int dp[12801];

Item items[3500];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> items[i].w>>items[i].v;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = M; j >= items[i].w; --j)
		{
			dp[j] = max(dp[j],dp[j - items[i].w]+items[i].v);
		}
	}

	cout << dp[M]<<endl;

	return 0;
}

