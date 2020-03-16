
#include<iostream>
using namespace std;

int dp[50][50];

int search(int m,int n)
{
	if (dp[m][n] != 0) return dp[m][n];
	if (m == 0 || n == 1) return (dp[m][n] = 1);

	if (m < n) return (dp[m][n] = search(m,m));

	return (dp[m][n] = search(m, n - 1) + search(m - n, n));

}

int main()
{
	int N;
	cin >> N;
	while (N > 0)
	{
		int m, n;
		cin >> m >> n;

		cout <<search(m,n)<<endl;

		N--;
	}


	return 0;
}

