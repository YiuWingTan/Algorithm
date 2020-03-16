#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
	int dp[27];
	string str;
	int k;

	while (cin >> str >> k)
	{
		if (str.size() == 0) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i<27; i++) dp[i] = 0;

		for (int i = 0; i<str.size(); i++)
			++dp[str[i] - 'a'];
		sort(&dp[0], &dp[26]);

		for (int i = 25; i>=0 && dp[i] != 0;)
		{
			if (k>0)
			{
				--dp[i];
				k--;
				if (i > 0 && dp[i - 1] >= dp[i]) i--;
				if (dp[i] == dp[25]) i = 25;
			}
			else break;
		}
		if (k>0)
			cout << 0 << endl;
		else {
			int val = 0;
			for (int i = 0; i<26; i++)
				val += dp[i] * dp[i];
			cout << val << endl;
		}
	}


	return 0;
}

