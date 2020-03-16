#include<iostream>
#include<vector>
using namespace std;
/*
int max(int i,int j)
{
	return i > j ? i : j;
}

int dp[1000][1000];

int getMaxValue(vector<vector<int>> goods,int weight)
{
	int n = goods.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <=weight; j++)
		{
			if (j < goods[i][0]) dp[i + 1][j] = dp[i][j];
			else
			{
				//厉害
				dp[i + 1][j] = max(dp[i][j], dp[i+1][j - goods[i][0]] + goods[i][1]);
				for (int k = 0; j- goods[i][0] * k >=0 ; k++)
				{
					dp[i + 1][j] = max(dp[i+1][j],dp[i][j-goods[i][0]*k]+goods[i][1]*k);
				}
			}
		}
	}

	return dp[n][weight];
}

int main()
{
	vector<vector<int>> goods{
		{ 2,3 },
		{ 1,2 },
		{ 3,4 },
		{ 2,2 }
	};
	int weight = 5;
	cout << "最大的获取价值是" << getMaxValue(goods, weight);

	getchar();
}*/