#include<iostream>
#include<vector>
using namespace std;
/*

//Ҫ��dpͨ���ݹ����������
int dp[1000][1000];//dp�����ʾ���ӵ�һ����Ʒ����i����Ʒʱ����j�������������ܻ�õ����ֵ

int max(int i,int j)
{
	return i > j ? i : j;
}

int getMaxValule(vector<vector<int>> &goods,int weight)
{
	int n = goods.size();
	if (n == 0) return 0;
	
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j <= weight; j++)
		{
			if (j < goods[i][0]) dp[i][j] = dp[i + 1][j];
			else
			{
				dp[i][j] = max(dp[i+1][j],dp[i+1][j-goods[i][0]]+goods[i][1]);
			}
		}
	}

	return dp[0][weight];
}


int main()
{
	vector<vector<int>> goods{
		{2,3},
		{1,2},
		{3,4},
		{2,2}
	};
	int weight = 5;
	cout << "���Ļ�ȡ��ֵ��"<< getMaxValule(goods,weight);

	getchar();
}
*/