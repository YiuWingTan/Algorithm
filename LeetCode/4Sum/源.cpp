/*
	难度 中等，主题 哈希表，双指针
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {

	vector<vector<int>> result;
	sort(nums.begin(),nums.end());


	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			int lo = j + 1;
			int hi = nums.size() - 1;
			int tar = target - (nums[i]+nums[j]);

			while (lo < hi)
			{
				int offset = tar - (nums[lo]+nums[hi]);
				if (offset < 0)
				{
					hi--;
				}
				else if (offset > 0)
				{
					lo++;
				}
				else
				{
					result.push_back({nums[i],nums[j],nums[lo],nums[hi]});
					while (lo < nums.size() && nums[lo- 1] == nums[lo]) lo++;
					hi--;
					while (hi >= 0 && nums[hi + 1] == nums[hi]) hi--;
				}
			}

			while (j+1 < nums.size() && nums[j + 1] == nums[j])j++;
		}
		while (i+1<nums.size()&&nums[i+1]==nums[i]) i++;
	}

	return result;

}


int main()
{
	vector<int> nums{ 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> list = fourSum(nums,0);

	for (int i = 0; i < list.size(); i++)
	{
		printf("%d %d %d %d\n",list[i][0],list[i][1],list[i][2],list[i][3]);
	}

	getchar();
	return 0;

}


