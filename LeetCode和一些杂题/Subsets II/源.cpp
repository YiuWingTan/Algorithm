#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getSubSets(vector<vector<int>> &result,vector<int> &arr,vector<int> &nums,int begin,int len)
{
	if (arr.size() == len)
	{
		result.push_back(arr);
		return;
	}
	int size = nums.size() - (len - arr.size()) + 1;
	for (int i = begin; i <size; i++)
	{
		arr.push_back(nums[i]);
		getSubSets(result,arr,nums,i+1,len);
		arr.pop_back();
		//½øÐÐÌøÔ¾
		while (i + 1 < size&&nums[i] == nums[i + 1])
			i++;
	}
	return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> result;
	vector<int> arr;
	result.push_back(vector<int>{});

	sort(nums.begin(), nums.end());

	for (int i = 1; i <= nums.size(); i++)
	{
		getSubSets(result, arr, nums, 0, i);
	}

	return result;
}


int main()
{

	vector<int> nums = { 1,2,2 };
	auto result = subsetsWithDup(nums);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}
