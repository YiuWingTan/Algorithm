


#include<iostream>
#include<vector>
using namespace std;

int dp[11][11];




int main()
{
	vector<int> re;
	int k;

	for (int i = 0; i < 11; i++)
		dp[0][i] = 1;

	cin >> k;

	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j <11; j++)
		{
			if (i - j >= 0)
				dp[i][j] = dp[i - j][j] + dp[i][j - 1];
			else
				dp[i][j] = dp[i][j-1];
		}
	}

	int M,N;
	for (int i = 0; i < k; i++)
	{
		cin >> M>>N;
		re.push_back(dp[M][N]);
	}

	for (int i = 0; i < re.size(); i++)
	{
		cout << re[i]<<endl;
	}

	return 0;
}
