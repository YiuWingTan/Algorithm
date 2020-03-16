
#include<vector>
#include<iostream>
using namespace std;


int dp[101];
int m[101][101];

int max(int a,int b)
{
	return a > b ? a : b;
}


int main()
{
	int N;
	vector<int> result;
	cin >> N;

	while (N > 0)
	{
		memset(dp,0x00,sizeof(int)*100);

		int r, c;
		cin >> r >> c;

		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				cin >> m[i][j];
				dp[j] = max(dp[j],dp[j-1]) + m[i][j];
			}
		}

		result.push_back(dp[c]);

		N--;
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i]<<endl;

	return 0;
}
