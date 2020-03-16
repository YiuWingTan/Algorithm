

#include<iostream>
using namespace std;

int dp[101][101][2];
int path[101];
int arr[101][101];

int max(int a, int b) { return a > b ? a : b; }

int main()
{

	int F, V;
	cin >> F >> V;

	for (int i = 1; i <= F; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			cin >> arr[i][j];
			dp[i][j][0] = -10000;
		}
	}

	for (int i = 1; i <= V-F+1; i++) dp[1][i][0] = arr[1][i];

	for (int i = 2; i <= F; i++)
	{
		for (int j = i; j <= V; j++)
		{
			for (int k = 1; k < j; k++)
			{
				
				if (dp[i - 1][k][0] + arr[i][j] > dp[i][j][0])
				{
					dp[i][j][0] = dp[i - 1][k][0] + arr[i][j];
					dp[i][j][1] = k;
				}
			}
		}
	}

	int re = -1000000,j = 0;
	for (int i = 1; i <= V; i++)
	{
		if (dp[F][i][0] > re)
		{
			re = dp[F][i][0];
			j = i;
		}
	}

	cout << re << endl;
	int i = F;
	while (i != 0)
	{
		path[i] = j;
		j = dp[i][j][1];
		i--;
	}

	for (int i = 1; i <= F; i++)
		cout << path[i]<<" ";

	return 0;
}

