#include<stdio.h>
#include<iostream>
using namespace std;

int N;
int a[201];
bool road[201][201];
int dp[201][2];


int main()
{
	cin >> N;
	for (int i = 1; i <=N; i++)
	{
		cin >> a[i];
	}

	int to = -1, from = -1;

	while (true)
	{
		cin >> from >> to;
		if (from == 0 && to == 0) break;
		road[from][to] = true;
	}

	int max = a[N], maxID = N;
	dp[N][0] = a[N];
	dp[N][1] = -1;

	for (int i = N-1; i > 0; i--)
	{
		int tmp_max = 0,tmp_link = -1;
		dp[i][0] = a[i];
		dp[i][1] = -1;
		for (int j = i + 1; j <= N; j++)
		{
			if (road[i][j] && tmp_max < dp[j][0])
			{
				tmp_max = dp[j][0];
				tmp_link = j;
			}
		}
		dp[i][0] += tmp_max;
		dp[i][1] = tmp_link;

		if (dp[i][0] > max)
		{
			max = dp[i][0];
			maxID = i;
		}

	}

	//Êä³ö½á¹û
	
	while (maxID != -1)
	{
		cout << maxID;
		maxID = dp[maxID][1];
		if (maxID != -1) cout << "-";
	}
	cout << endl << max << endl;


	return 0;
}