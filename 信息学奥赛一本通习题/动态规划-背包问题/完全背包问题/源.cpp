

#include<iostream>
using namespace std;

struct Item
{
	int w;
	int v;
};

int dp[1000];
Item items[1000];

int max(int a,int b)
{
	return a > b ? a : b;
}

int main()
{
	int W, N;
	cin >> W >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> items[i].w >> items[i].v;
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = items[i].w; j <= W; j++)
		{
			dp[j] = max(dp[j],dp[j - items[i].w] + items[i].v);
		}
	}

	cout <<"max="<< dp[W]<<endl;

	return 0;
}

