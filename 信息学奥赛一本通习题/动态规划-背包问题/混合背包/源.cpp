
#include<iostream>
#include<vector>
using namespace std;

struct Item
{
	int v;
	int w;
	int n;
};

vector<Item> items;
int dp[201];

int max(int a,int b)
{
	return a > b ? a : b;
}

int main()
{
	int N, W;
	cin >> W>>N;
	items.push_back({0,0,0});
	for (int i = 1; i <= N; i++)
	{
		int w, v, n;
		cin >> w >> v >> n;

		if (n > 1)
		{
			//进行物品拆分
			int s, t=1;
			s = n;
			while (t <= s)
			{
				items.push_back({v*t,w*t,1});
				s -= t;
				t *= 2;
			}
			items.push_back({v*s,w*s,1});

		}
		else {
			items.push_back({v,w,n});
		}
	}

	
	for (int i = 1; i < items.size(); i++)
	{
		
		if (items[i].n == 0)
		{
			//无穷
			for (int j = items[i].w; j <= W; j++)
			{
				
				dp[j] = max(dp[j],dp[j - items[i].w]+items[i].v);
			}
		}
		else
		{
			//只能取一个
			for (int j = W; j >= items[i].w; j--)
			{
				
				dp[j] = max(dp[j], dp[j - items[i].w] + items[i].v);
			}
		}
	}

	cout << dp[W]<<endl;


	return 0;
}


