#include<iostream>
#include<vector>

using namespace std;

/*
	寻找边界--二分查找
*/

int findMin(vector<int>& nums) {

	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0];
	if (nums[nums.size() - 1] > nums[0]) return nums[0];
	if (nums[nums.size() - 1] < nums[nums.size() - 2]) return nums[nums.size() - 1];

	int low = 0, height = nums.size()-1;
	int mid;

	while (low < height)
	{
		mid = low + (height - low)/2;
		if (nums[mid] > nums[height]) low = mid+1;
		else if (nums[mid] < nums[height]) height = mid;
		
	}
	return nums[low];
}

int main()
{

	vector<int> arr = {3,1,2};

	cout << findMin(arr)<<endl;

	getchar();
	return 0;
}