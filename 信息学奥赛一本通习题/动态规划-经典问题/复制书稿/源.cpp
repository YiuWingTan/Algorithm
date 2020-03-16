

#include<iostream>
using namespace std;


int dp[501][501];
int books[501];
int sum[501];
int M, N;
int max(int a,int b)
{
	return a > b ? a : b;
}

void print(int i,int j)
{
	if (i == 0) return;
	if (j == 1)
	{
		cout << 1 << " " << i<<endl;
		return;
	}

	int t = i,count = 0;

	while (t>0&&count + books[t] <= dp[N][M])
	{
		count += books[t--];
	}

	print(t,j-1);
	cout << t+1 << " " << i<<endl;
}

int main()
{
	
	cin >> M >> N;
	
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++)
			dp[i][j] = 0x3f3f3f3f;
	}


	for (int i = 1; i <= M; i++) {
		cin >> books[i];
		sum[i] = sum[i-1]+books[i];
		dp[1][i] = sum[i];
		
	}

	
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 1; k <=j-1; k++)
			{
				if (max(dp[i-1][k] , sum[j] - sum[k])< dp[i][j])
				{
					dp[i][j] = max(dp[i - 1][k], sum[j] - sum[k]);
					
				}

			}
		}
		
	}

	print(M,N);
	

	return 0;
}

