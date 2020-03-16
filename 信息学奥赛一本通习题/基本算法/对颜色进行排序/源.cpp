#include<iostream>
#include<vector>

using namespace std;


void sortColors(vector<int>& nums)
{
	int lo = 0, hi = nums.size()-1;


	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0&&i!=lo)
		{
			swap(nums[i],nums[lo]);
			i--;
			lo++;
		}
		else if (nums[i] == 2&&i!=hi)
		{
			swap(nums[i],nums[hi]);
			hi--;
			i--;
		}
	}


}


