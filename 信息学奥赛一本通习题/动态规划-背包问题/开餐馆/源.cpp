#include<iostream>
#include<vector>
using namespace std;

struct Item
{
	int d;
	int v;
};


int dp[1001];
Item items[100];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	vector<int> result;
	int N;
	cin >> N;

	while (N > 0)
	{
		int n, k;
		cin >> n >> k;

		int max = 0;
		for (int i = 0; i < n; i++)
			cin >> items[i].d;

		for (int i = 0; i < n; i++)
			cin >> items[i].v;

		for (int i = 0; i < n; i++)
		{
			int tmp_max = 0;
			dp[i] = items[i].v;
			for (int j = i-1; j >= 0; j--)
			{
				if ((items[i].d - items[j].d) > k && dp[j] > tmp_max)
					tmp_max = dp[j];
			}
			dp[i] += tmp_max;

			if (max < dp[i]) max = dp[i];

		}




		result.push_back(max);
		N--;
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<<endl;
	}

	return 0;
}
