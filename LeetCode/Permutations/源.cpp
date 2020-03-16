/*
难度 中等，主题 回溯，动态规划
*/

#include<vector>
#include<iostream>
#include<map>
using namespace std;
vector<vector<int>> results;
void getCombination(map<int,int> &m,int target,vector<int>&result,vector<int> &pattern)
{
	if (result.size() == pattern.size())
	{
		results.push_back(result);
		return;
	}

	m[target] = 0;

	for (int i = 0; i < pattern.size(); i++)
	{
		if (m[pattern[i]] != 0)
		{
			result.push_back(pattern[i]);
			getCombination(m,pattern[i],result,pattern);
			result.pop_back();
		}
	}
	m[target] = 1;
}

vector<vector<int>> permute(vector<int>& nums) {
	
	if (nums.size() == 0)
	{
		results.push_back({});
		return results;
	}
	vector<int> result;
	result.reserve(3);

	map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
		m[nums[i]] = 1;

	for (int i = 0; i < nums.size(); i++)
	{
		result.push_back(nums[i]);
		getCombination(m, nums[i], result,nums);
		result.pop_back();
	}

	return results;
}

int main()
{
	vector<int> p = {1,2,3};
	
	vector<vector<int>> result = permute(p);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j]<<" ";
		cout << endl;
	}

	getchar();
	return 0;
}