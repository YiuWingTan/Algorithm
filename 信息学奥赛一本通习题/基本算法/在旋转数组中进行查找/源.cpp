#include<iostream>
#include<vector>

using namespace std;



int search(vector<int>& nums, int target)
{
	int lo = 0, hi = nums.size();
	
	while (lo < hi)
	{
		int mid = lo + (hi - lo) / 2;

		if (nums[mid] == target) return mid;

		if (nums[mid] == nums[lo] && nums[mid] == nums[hi]) {

			for (int i = 0; i < nums.size(); i++)
				if (nums[i] == target) return i;
			return -1;
		}


		if (nums[lo] <= nums[mid])
		{
			//×ó±ß
			if (target > nums[mid] || target < nums[lo])
			{
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		else {
			//ÔÚÓÒ±ß

			if (target > nums[mid] && target < nums[lo])
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}

		}

	}

	return nums[lo] == target ? lo : -1;
}


int main()
{


	getchar();
	return 0;
}



