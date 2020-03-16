
#include<iostream>
#include<vector>
using namespace std;

int arr[500];

int dp[500][2];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i][0] = 1;
		dp[i][1] = -1;
	}

	
	for (int i = N - 2; i >= 0; i--)
	{
		//从后面所有节点中选择一个最长的且符合arr[i]<arr[j]
		int tmp_max = 0;
		int tmp_maxIndex = -1;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] <= arr[j]&&dp[j][0]>tmp_max)
			{
				tmp_max = dp[j][0];
				tmp_maxIndex = j;
			}
		}

		dp[i][0] = tmp_max + 1;
		dp[i][1] = tmp_maxIndex;
	}

	int maxIndex = 0,nodeCount = 1;
	//从dp数组中选取最长的一条

	for (int i = 0; i < N; i++)
	{
		if (dp[i][0] > nodeCount)
		{
			maxIndex = i;
			nodeCount = dp[i][0];
		}
	}
	cout << "max="<<dp[maxIndex][0]<<endl;
	while (maxIndex != -1)
	{
		cout << arr[maxIndex]<<" ";
		maxIndex = dp[maxIndex][1];
	}
	cout << endl;

	return 0;
}

