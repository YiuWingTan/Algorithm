

#include<iostream>
using namespace std;

int result;

/* 递归做法 */
void count(int n,int k,int p)
{
	if (k == 1)
	{
		if (n >= p) result++;
		return;
	}

	for (int i = p; i <= n / k; i++)
	{
		count(n-i,k-1,i);
	}

}

/*动态规划做法*/
/*考虑将n个小球放到k个袋子中，f[k][n] = k个袋子中所有的小球个数都大于1 + k个袋子中只有一个小球为1*/
int f[7][201];
int dp(int n,int k)
{
	f[0][0] = 1;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = f[i][j-i] + f[i-1][j-1];
		}
	}
	
	return f[k][n];
}



int main()
{
	int n, k;
	cin >> n >> k;
	count(n, k, 1);
	cout << result<<endl;


	return 0;
}

