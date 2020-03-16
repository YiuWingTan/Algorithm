
#include<iostream>
using namespace std;

int dp[100][100];
int dp_link[100][100];
int benefit[100][100];


int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin>>benefit[i][j];
		}
	}

	for (int j = 1; j <= M; j++)
	{
		dp[N][j] = benefit[N][j];
		dp_link[N][j] = j;
	}

	for (int i = N-1; i >0; i--)
	{
		for (int j = 1; j <= M; j++)
		{
			int max = 0;
			for (int k = 0; k <= j; k++)
			{
				int tmp = dp[i+1][k] + benefit[i][j-k];
				if (tmp >= max)
				{
					max = tmp;
					dp_link[i][j] = j - k;
				}
			}
			dp[i][j] = max;
		}
	}

	cout << dp[1][M]<<endl;

	int i=1, j=M;
	while (i <=N )
	{
		cout << i << " "<<dp_link[i][j]<<endl;
		j = M - dp_link[i][j];
		M = j;
		i++;
	}



	return 0;
}



