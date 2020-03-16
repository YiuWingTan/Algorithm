
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
		//��֤ÿ����ֻ����һ����ѡ��
		for (int j = V; j >= 0; j--)
		{
			for (int i = 0; i < items[t].size(); i++)
			{
				int u = j - items[t][i].w;
				int tmp = 0;
				if(u>=0)
				tmp = max(dp[t-1][j],dp[t-1][u]+items[t][i].v);
				//��ά��Ҫ���һ�������Ĳ�����Ϊ�п�������Ʒͬ�鲢�Ҽ۸�һ��
				dp[t][j] = max(tmp,dp[t][j]);
			}
		}
	}

	
	cout << dp[T][V]<<endl;

	return 0;
}

