

#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
vector<long long> dp;

int main()
{
	int N, V;
	cin >> N >> V;

	dp.resize(V+1,0);
	int tmp;
	for (int i = 0; i < N; i++)
	{
		
		cin >> tmp;
		arr.push_back(tmp);
		
	}

	dp[0] = 1;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = arr[i]; j <= V; j++)
		{
			dp[j] += dp[j - arr[i]];
		}
	}


	cout << dp[V]<<endl;

	return 0;
}
