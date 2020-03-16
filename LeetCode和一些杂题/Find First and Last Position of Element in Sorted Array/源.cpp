/*
难度 中等，主题 数组，二分查找
*/
#include<iostream>
#include<vector>
using namespace std;

int searchLeft(vector<int> &nums,int lo,int hi,int target)
{
	int mid;

	while (true)
	{
		mid = lo + (hi - lo) / 2;
		if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target)) return mid;
		if (lo >= hi) break;
		if (nums[mid] < target) lo = mid+1;
		else hi = mid;

	}

	return -1;
}

int searchRight(vector<int>&nums,int lo,int hi,int target)
{
	int mid;
	int len = nums.size() - 1;
	while (true)
	{
		mid = lo + (hi - lo) / 2;
		if (nums[mid] == target && (mid == len || nums[mid + 1] > target)) return mid;
		if (lo >= hi) break;
		if (nums[mid] <=target) lo = mid + 1;
		else hi = mid;
	}

	return -1;
}


vector<int> searchRange(vector<int>& nums, int target) {

	vector<int> arr;
	arr.resize(2);
	arr[0] = arr[1] = -1;
	if (nums.size() == 0) return arr;
	arr[0] = searchLeft(nums, 0, nums.size() - 1, target);
	arr[1] = searchRight(nums, 0, nums.size() - 1, target);

	return arr;
}


int main()
{
	int target = 6;
	vector<int> list = { 6};
	auto result = searchRange(list,target);

	printf("结果是 [%d,%d]\n",result[0],result[1]);

	getchar();
	return 0;
}