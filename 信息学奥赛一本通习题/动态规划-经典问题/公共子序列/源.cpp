
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int dp[201][201];
char  a[201];
char b[201];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	string tmp_a, tmp_b;
	vector<int> result;

	while (cin >> tmp_a >> tmp_b)
	{
		int lena = tmp_a.size();
		int lenb = tmp_b.size();
		
		for (int i = 0; i < lena; i++) a[i + 1] = tmp_a[i];
		for (int i = 0; i <lenb; i++) b[i + 1] = tmp_b[i];
		
		for (int i = 1; i <= lena; i++)
		{
			for (int j = 1; j <= lenb; j++) 
			{
				if (a[i] == b[j])
					dp[i][j] = dp[i-1][j-1]+1;
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}

		result.push_back(dp[lena][lenb]);
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i]<<endl;

	return 0;
}

