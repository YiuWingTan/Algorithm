/*
	难度 中等 主题 双指针，数组 96.89%
*/

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int abs(int v)
{
	return v > 0 ? v : -v;
}

int threeSumClosest(vector<int>& nums, int target) {

	if (nums.size() < 3) return 0;

	sort(nums.begin(),nums.end());

	int sum = nums[0] + nums[1] + nums[2];
	int offset = abs(sum - target);;

	for (int i = 0; i < nums.size()-2; i++)
	{
		int mi = i + 1;
		int hi = nums.size() - 1;
		int s = 0;

		while (mi < hi)
		{
			s = nums[mi] + nums[hi] + nums[i];

			if (s > target)
			{
				hi--;
			}
			else if (s < target)
			{
				mi++;
			}
			else
			{
				return target;
			}
			if (abs(s - target) < offset)
			{
				sum = s;
				offset = abs(s - target);
			}
		}
		while (i<nums.size()-2&&nums[i]==nums[i+1]) i++;
	}

	return sum;
}

int main()
{
	vector<int> nums{ -1,2,1,-4 };
	int v = threeSumClosest(nums,1);

	printf("%d\n",v);

	getchar();
	return 0;
}