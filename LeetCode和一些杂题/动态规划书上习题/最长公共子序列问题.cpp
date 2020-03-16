#include<iostream>
#include<vector>
using namespace std;
/*
int dp[1000][1000];

int max(int i,int j)
{
	return i > j ? i : j;
}

int getMaxLength(string s,string l)
{
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < l.length(); j++)
		{
			if (s[i] == l[j]) dp[i + 1][j + 1] = dp[i][j]+1;
			else dp[i + 1][j + 1] = max(dp[i][j+1],dp[i+1][j]);
		}
	}
	return dp[s.length()][l.length()];
}

int main()
{
	cout << "最长公共子序列是"<< getMaxLength("abcd","becd")<<endl;

	getchar();
}
*/