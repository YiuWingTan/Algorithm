#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
"mississippi"
"m??*ss*?i*pi"
*/
bool isMatch(string s, string p) {

	int lens = s.size();
	int lenp = p.size();
	vector<vector<bool>> dp;
	dp.resize(lens + 1);
	for (int i = 0; i <= lens; i++)
		dp[i].resize(lenp + 1, false);

	dp[0][0] = true;

	for (int j = 1; j <= lenp; j++)
	{
		for (int i = 0; i <= lens; i++)
		{
			if (p[j - 1] == '*')
			{
				if (i - 1 >= 0)
					dp[i][j] = dp[i - 1][j - 1] | dp[i][j - 1] | dp[i - 1][j];
				else dp[i][j] = dp[i][j - 1];
			}
			else if (i-1>=0&&(s[i - 1] == p[j - 1] || p[j - 1] == '?'))
			{
				if (j - 2 >= 0 && p[j - 2] == '*')
					dp[i][j] = (dp[i][j - 1] & dp[i - 1][j - 2]) | dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j - 1];
			}
			else dp[i][j] = false;
		}
	}
	for (int i = 0; i < lens + 1; i++)
	{
		for (int j = 0; j < lenp + 1; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}

	return dp[lens][lenp];
}

void text1()
{
	string s = "acdcb";
	string p = "a*c?b";
	cout << s<<endl;
	cout << p<<endl;
	bool result = isMatch(s,p);
	cout << result<<endl;
}
void text2()
{
	string s = "";
	string p = "";
	cout << s << endl;
	cout << p << endl;
	bool result = isMatch(s, p);
	cout << result << endl;
}
void text3()
{
	string s = "";
	string p = "";
	cout << s << endl;
	cout << p << endl;
	bool result = isMatch(s, p);
	cout << result << endl;
}

int main()
{
	text1();

	getchar();
	return 0;
}