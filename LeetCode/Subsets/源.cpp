#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> note;

void subsetsResult(vector<vector<int>> &result, vector<int> &arr,vector<int>&nums, int begin, int n, int k)
{

	for (int i = begin; i <= n - k + 1;)
	{
		arr[arr.size() - k] = nums[i-1];
		i++;
		if (k > 1)
		{
			subsetsResult(result, arr,nums, i, n, k - 1);
		}
		else
		{
			result.push_back(arr);
		}
	}
}

vector<vector<int>> subsets(vector<int>& nums) {

	vector<vector<int>> result;
	result.push_back(vector<int>{});
	int n = nums.size();
	int k = n;
	if (n == 0) return result;
	if (k == 0)
	{
		return result;
	}

	vector<int> arr;
	while (k >= 1)
	{
		arr.resize(k);
		subsetsResult(result, arr, nums, 1, n, k);
		k--;
	}

	return result;
}

int main()
{
	vector<int> arr{0};
 	auto result = subsets(arr);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j];
		}
		cout << endl;
	}


	getchar();
	return 0;
}