
#include<iostream>
#include<stack>
using namespace std;

int m[100][100];

int dp[100][2];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> m[i][j];


	//初始化dp数组
	for (int i = 0; i < N; i++)
	{
		dp[i][0] = 1000000;
		dp[i][1] = -1;
	}

	dp[0][0] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (m[i][j] == 0) continue;
			if (dp[j][0] == 0)
			{
				dp[j][0] = dp[i][0] + m[i][j];
				dp[j][1] = i;
			}
			else if(dp[j][0]!=0&&dp[j][0]>(dp[i][0]+m[i][j])) {
				dp[j][0] = dp[i][0] + m[i][j];
				dp[j][1] = i;
			}
		}
	}

	cout << "minlong="<<dp[N-1][0]<<endl;

	stack<int> st;
	for (int i = N-1; i != -1; i = dp[i][1])
		st.push(i);

	while (!st.empty())
	{
		cout << st.top()+1 << " "; st.pop();
	}
	cout << endl;

	return 0;
}
