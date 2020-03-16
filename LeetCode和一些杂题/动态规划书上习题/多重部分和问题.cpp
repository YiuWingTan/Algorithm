#include<iostream>
#include<vector>
using namespace std;

int dp[1000][1000];

bool isCanOne(vector<int> &n,vector<int> &num,int target)
{
	dp[0][0] = 1;
	for (int i = 0; i < n.size(); i++)
	{
		for (int j = 0; j <= target; j++)
		{
			for (int k = 0; k <= num[i]&&j-n[i]*k>=0; k++)
			{
				dp[i + 1][j] |= dp[i][j - n[i] * k];
			}
		}
	}

	return dp[n.size()][target];
}

bool isCanTwo(vector<int> &n,vector<int> &num,int target)
{
	memset(dp[0], -1, 1000 * 1000);
	dp[0][0] = num[0];
	for (int i = 0; i < n.size(); i++)
	{
		for (int j = 0; j <= target; j++)
		{
			if (dp[i][j] >= 0)
			{
				dp[i + 1][j] = num[i];
			}
			else if(j-n[i]>=0)
			{
				dp[i + 1][j] = dp[i + 1][j - n[i]] - 1;
			}
			
		}
	}


	return dp[n.size()][target]>=0;
}

int main()
{
	vector<int> n{3,5,8};
	vector<int> num{3,2,2};
	int target = 21;

	if (isCanTwo(n, num, target))
		cout << "OK"<<endl;
	else cout << "²»OK";
	getchar();
}