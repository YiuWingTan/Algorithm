
#include<iostream>
#include<string>
#include<vector>
using namespace std;


int dp[1000][1000];
char a[1000];
char b[1000];

int min(int a, int b, int c)
{
	if (a < b) return a < c ? a : c;
	
	return b < c ? b : c;

}

int main()
{
	int N;
	vector<int> result;
	
	cin >> N;

	while (N > 0)
	{
		string str;
		int lena, lenb;
		cin >> str;
		lena = str.size();
		for (int i = 0; i < lena; i++) {
			a[i + 1] = str[i];
			dp[i+1][0] = i+1;
		}
		cin >> str;
		lenb = str.size();
		for (int i = 0; i < lenb; i++) {
			b[i + 1] = str[i];
			dp[0][i+1] = i+1;
		}

		

		for (int i = 1; i <= lena; i++)
		{
			for (int j = 1; j <= lenb; j++)
			{
				if (a[i] == b[j])
				{
					dp[i][j] = dp[i-1][j-1];
				}
				else
				{
					//修改其中一个字符，或者是删除a中的一个字符或者是删除b总的一个字符
					dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
				}
			}
		}
		cout << dp[lena][lenb] << endl;
		N--;
	}

	//for (int i = 0; i < result.size(); i++) cout << result[i]<<endl;

	return 0;
}

