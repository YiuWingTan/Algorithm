
#include<iostream>
#include<vector>
using namespace std;

struct Item
{
	int w;
	int v;
	int g;
};

vector<Item> items[100];
int dp[500][500];

int max(int a,int b)
{
	return a > b ? a : b;
}

int min(int a,int b)
{
	return a > b ? b : a;
}

int main()
{
	int V, N, T;
	cin >> V >> N >> T;

	int w, c, p;
	for (int i = 1; i <= N; i++)
	{
		cin >> w >> c >> p;

		items[p].push_back({w,c,p});
	}

	for (int t = 1; t <= T; t++)
	{
		//保证每组中只能有一个被选中
		for (int j = V; j >= 0; j--)
		{
			for (int i = 0; i < items[t].size(); i++)
			{
				int u = j - items[t][i].w;
				int tmp = 0;
				if(u>=0)
				tmp = max(dp[t-1][j],dp[t-1][u]+items[t][i].v);
				//二维版要多加一个这样的操作因为有可能有物品同组并且价格一样
				dp[t][j] = max(tmp,dp[t][j]);
			}
		}
	}

	
	cout << dp[T][V]<<endl;

	return 0;
}

