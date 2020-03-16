/*
难度 ：简单 主题 数组 二分查找
*/

#include<vector>
#include<iostream>

using namespace std;


int searchInsert(vector<int>& nums, int target) {

	int lo = 0;
	int hi = nums.size() - 1;
	int mid =0;
	if (hi == -1) return 0;
	while (lo<=hi)
	{
		mid = lo + (hi - lo)/2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) lo = mid+1;
		else hi = mid-1;
	}
	
	if (mid == 0&&nums[0]>target) return 0;
	if (mid == nums.size() - 1 && nums[nums.size() - 1] < target) return nums.size();
	return mid+1;
}


int main()
{
	vector<int> nums = { 1,3 };
	int target = 2;

	int result = searchInsert(nums,target);

	printf("结果为%d\n",result);

	getchar();
	return 0;
}