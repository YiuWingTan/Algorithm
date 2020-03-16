#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>&nums,int lo,int hi)
{
	int min = INT_MAX;
	for (int i = lo; i <= hi; i++)
	{
		if (nums[i] < min) min = nums[i];
	}
	return min;
}

int findMin(vector<int>& nums)
{

	int lo = 0, hi = nums.size() - 1;

	int mid = 0;

	while (lo < hi)
	{
		mid = lo + (hi - lo) / 2;

		if (nums[mid] == nums[lo] && nums[hi] == nums[mid])
		{
			//ÕÒ²»µ½
			return findMin(nums,lo,hi);
		}

		if (nums[mid] > nums[hi])
		{
			lo = mid + 1;
		}
		else if (nums[mid] < nums[lo])
		{
			hi = mid;
		}


	}

	return hi;
}




