#include<iostream>
#include<vector>

using namespace std;

int find(vector<int> &nums,int lo,int hi,int target)
{
	int mid;
	
	while (lo <= hi)
	{
		 mid = lo + (hi - lo) / 2;
		if (nums[mid] == target) return mid;

		if (nums[mid] < target)
		{
			if (nums[mid] < nums[hi])
			{
				if (target <= nums[hi]) lo = mid + 1;
				else hi = mid;
			}
			else
			{
				lo = mid + 1;
			}
		}
		else
		{

			if (nums[mid] < nums[hi])
			{
				hi = mid;
			}
			else
			{
				if (nums[lo] <= target) hi = mid;
				else lo = mid + 1;
			}
		}
	}

	return -1;
}

int search(vector<int>& nums, int target) {

	int lo = 0;
	int hi = nums.size()-1;
	if (hi == -1)return -1;
	if (target == nums[hi]) return hi;
	if (target == nums[lo]) return lo;
	return find(nums,lo,hi,target);
	
}


int main()
{
	vector<int> nums = { 3,4,5,6,7,8,1,2};
	int target = 7;

	int index = search(nums,target);

	printf("%d µÄË÷ÒıÊÇ%d\n",target,index);

	getchar();
	return 0;
}