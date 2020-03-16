#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> used;

void make(vector<vector<int>>&result,vector<int>&nums,vector<int>&ans,int j,int k)
{
	if (k >= nums.size())
	{
		result.push_back(ans);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (used[i]) continue;
		if (i - 1 >= 0 && !used[i - 1]) continue;

		ans[k] = nums[i];
		used[i] = true;
		make(result,nums,ans,i+1,k+1);
		used[i] = false;
	}

}


vector<vector<int>> permuteUnique(vector<int>& nums) {
	
	if (nums.size() == 0) return{};

	sort(nums.begin(),nums.end());
	used.resize(nums.size(),false);

	vector<vector<int>> result;
	vector<int> ans;
	ans.resize(nums.size());

	make(result,nums,ans,0,0);

	return result;
}






