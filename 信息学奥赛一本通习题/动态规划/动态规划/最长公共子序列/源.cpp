
#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001];

int max(int a,int b)
{
	return a > b ? a : b;
}


int main()
{
	string a,b;
	cin >> a;
	cin >> b;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == b[0]) dp[i][0] = 1;
		else if (i - 1 >= 0) dp[i][0] = dp[i-1][0];

	}


	for (int j = 0; j < b.size(); j++)
	{
		if (a[0] == b[j]) dp[0][j] = 1;
		else if (j - 1 >= 0 ) dp[0][j] = dp[0][j - 1];

	}


	for (int i = 1; i < a.size(); i++)
	{
		for (int j = 1; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	

	cout << dp[a.size()-1][b.size()-1]<<endl;



	return 0;
}


