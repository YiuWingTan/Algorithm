
#include<iostream>
#include<string>
using namespace std;

int dp[2001][2001];
char a[2001];
char b[2001];

int min(int a,int b,int c)
{
	if (a > b)
	{
		return b > c ? c : b;
	}
	
	return a > c ? c : a;
	
}

int main()
{
	string tmp;
	int index = 1,lena,lenb;
	cin >> tmp;
	lena = tmp.size();
	for (int i = 0; i < tmp.size(); i++) a[index++] = tmp[i];
	
	cin >> tmp;
	index = 1;
	lenb = tmp.size();
	for (int i = 0; i < tmp.size(); i++) b[index++] = tmp[i];



	for (int i = 1; i <=lena; i++) 
	{

		for (int j = 1; j <=lenb; j++)
		{
			dp[i][j] = 0x3f3f3f3f;
		}
	}

	for (int i = 1; i <= lena; i++) {
		dp[i][0] = i;
		
	}
	for (int i = 1; i <= lenb; i++) dp[0][i] = i;



	for (int i = 1; i <=lena; i++)
	{
		for (int j = 1; j <=lenb; j++)
		{

			if (a[i] == b[j])
				dp[i][j] = dp[i-1][j-1];
			else
			{
				dp[i][j] = min(dp[i-1][j-1]+1,dp[i][j-1]+1,dp[i-1][j]+1);
			}
		}
	}

	cout << dp[lena][lenb]<<endl;

	return 0;
}

