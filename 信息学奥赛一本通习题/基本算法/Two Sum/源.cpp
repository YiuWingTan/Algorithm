#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


//在数组没有被排序的情况下
vector<int> twoSum(vector<int>& nums, int target) {

	map<int, int> m;
	
	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]] = i;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		
		if (m.find(target - nums[i]) != m.end()&&i!= m[target - nums[i]]) return{i,m[target - nums[i]]};


	}
	return{};
}

int binarySearch(vector<int>&arr,int lo,int hi,int target)
{

	int mid;

	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;

		if (arr[mid] > target)
		{
			hi = mid-1;
		}
		else if (arr[mid] < target)
		{
			lo = mid + 1;
		}
		else return mid;
	}
	return -1;
}

//在数组已经排序的情况下
/*
-双指针法
-二分查找
*/
vector<int> twoSum(vector<int>& numbers, int target) {

	/*int lo = 0, hi = numbers.size() - 1;

	while (lo < hi)
	{
		int val = numbers[lo] + numbers[hi];

		if (val < target)
		{
			lo++;
		}
		else if (val > target)
		{
			hi--;
		}
		else return{lo+1,hi+1};

	}*/

	return{};


}


//三数之和为0
/*
	使用二层循环内层机型两数之和的寻找
	时间复杂度为O(n^2)
*/
vector<vector<int>> threeSum(vector<int>& nums) {

	vector<vector<int>> result;
	sort(nums.begin(),nums.end());

	for (int i = 0; i < nums.size(); i++)
	{
		int lo = i + 1,hi = nums.size()-1;
		int tar = nums[i];
		while (lo < hi)
		{
			int val = nums[lo] + nums[hi];
			if (val > tar)
			{
				hi--;
			}
			else if (val < tar)
			{
				lo++;
			}
			else {
				result.push_back({ nums[i],nums[lo],nums[hi] });
				while (lo+1 <= hi&&nums[lo] == nums[lo + 1]) lo++;
				while (hi-1 >= lo&&nums[hi] == nums[hi - 1]) hi--;
				hi--;
				lo++;
			}
		}

		while (i+1 < nums.size() && nums[i] == nums[i + 1]) i++;
	}

	return result;
}


int main()
{


	getchar();
	return 0;
}