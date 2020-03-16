#include<iostream>
#include<vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {

	vector<int> dp(nums.size(),1);
	int max = 0;
	for (int i = 0; i < nums.size(); i++)
	{

		for (int j = 0; j < i; i++)
		{

			if (dp[i] > dp[j]&& dp[i]<dp[j]+1)
			{
				dp[i] = dp[j] + 1;
			}

		}
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}

	return max;
}


int main()
{

	getchar();
	return 0;
}


