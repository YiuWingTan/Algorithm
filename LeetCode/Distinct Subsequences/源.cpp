#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int nums;
int len1;
int len2;

/*解法一 简单的回溯 时间复杂度太高了*/
void getCount1(string &s, string&t, int index, int j)
{
	if (j >= t.size()) { nums++; return; }
	if (index >= s.size()) return;
	
	cout << index << "  " << j<<endl;

	for (int i = index; i < s.size(); i++)
	{
		if (s[i] == t[j] && (len1 - i) >= (len2 - j))
		{
			getCount1(s, t, i + 1, j + 1);
		}
	}
}

int max(int u,int v)
{
	return u > v ? u : v;
}

/*解法二   区间型动态规划*/
int getCount2(string &s,string t,int index,int j)
{
	vector<vector<int>> dp;
	dp.resize(s.size());
	for (int i = 0; i < s.size(); i++)
		dp[i].resize(t.size(),0);
	for (int j = 0; j < len2; j++)
	{
		for (int i = 0; i < len1; i++)
		{
			if (i != 0 && j != 0 && t[j] == t[j - 1])
			{
				dp[i][j] = dp[i - 1][j] + dp[i-1][j - 1];
			}
			else if (s[i] == t[j])
			{
				if (i!=0&&dp[i-1][j] != 0)
				{
					if(j!=0)
					dp[i][j] = max(dp[i - 1][j],dp[i-1][j-1]) + 1;
					else dp[i][j] = dp[i - 1][j] + 1;
				}
				else if (i!=0&&j!=0&&dp[i - 1][j - 1] != 0) dp[i][j] = dp[i - 1][j - 1];
				else if(i==0&&j==0) dp[i][j] = 1;
				//else dp[i][j] = 0;
			}
			else if(i!=0)
			{
				dp[i][j] = dp[i-1][j];
			}
			cout << dp[i][j]<<"  " ;
		}
		cout << endl;
	}
	return dp[len1-1][len2-1];
}

int numDistinct(string s, string t) {

	if (s.size() == 0 || t.size() == 0) return 0;
	len1 = s.size();
	len2 = t.size();
	if (len2 > len1) return 0;

	return getCount2(s, t, 0, 0);
}




int main()
{
	/*
	"adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc"
	"bcddceeeebecbc"
	*/
	string s = "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc";
	string t = "bcddceeeebecbc";

	int val = numDistinct(s,t);
	cout << val << endl;

	getchar();
	return 0;
}